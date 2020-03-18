#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>
#include <xinput.h>

#define CINTERFACE
#define COBJMACROS
#define D3D11_NO_HELPERS
#include <d3d11.h>
#include <dxgi.h>

#include <initguid.h>
#include <audioclient.h>
#include <mmdeviceapi.h>

#ifndef STB_SPRINTF_IMPLEMENTATION
#define STB_SPRINTF_IMPLEMENTATION
#endif
#include "stb_sprintf.h"

#include <math.h>

#include "handmademath.h"

#include "tinyengine_types.h"
#include "tinyengine_platform.h"

static b32 IsRunning;
static ID3D11Device *Device;
static ID3D11DeviceContext *DeviceContext;
static IDXGISwapChain *Swapchain;
static ID3D11RenderTargetView *RenderTargetView;
static D3D_FEATURE_LEVEL ActiveFeatureLevel;

DEFINE_GUID(CLSID_MMDeviceEnumerator, 0xBCDE0395, 0xE52F, 0x467C, 0x8E, 0x3D, 0xC4, 0x57, 0x92, 0x91, 0x69, 0x2E);
DEFINE_GUID(IID_IMMDeviceEnumerator, 0xA95664D2, 0x9614, 0x4F35, 0xA7, 0x46, 0xDE, 0x8D, 0xB6, 0x36, 0x17, 0xE6);
DEFINE_GUID(IID_IAudioClient, 0x1CB9AD4C, 0xDBFA, 0x4C32, 0xB1, 0x78, 0xC2, 0xF5, 0x68, 0xA7, 0x03, 0xB2);
DEFINE_GUID(IID_IAudioRenderClient, 0xF294ACFC, 0x3146, 0x4483, 0xA7, 0xBF, 0xAD, 0xDC, 0xA7, 0xC2, 0x60, 0xE2);

////////////////////////////////////

static void
Win32PrintDebugString(char* Format, ...)
{
    static char Buffer[1024];
    va_list ArgumentList;
    va_start(ArgumentList, Format);
    stbsp_vsprintf(Buffer, Format, ArgumentList);
    va_end(ArgumentList);
    OutputDebugStringA(Buffer);
}

#include "tinyengine.c"

typedef struct win32_audio_thread_params
{
    IAudioClient *AudioClient;
    IAudioRenderClient *AudioRenderClient;    
    u32 SamplesPerSecond;
    u32 ChannelCount;
} win32_audio_thread_params;

static DWORD WINAPI
Win32AudioThread(void *Parameter)
{
    win32_audio_thread_params *Params = (win32_audio_thread_params *)Parameter;
    if(Params)
    {
        SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_BELOW_NORMAL);

        HANDLE BufferReadyEvent = CreateEvent(0, 0, 0, 0);
        if(BufferReadyEvent != INVALID_HANDLE_VALUE)
        {
            if(Params->AudioClient->lpVtbl->SetEventHandle(Params->AudioClient, BufferReadyEvent) == 0)
            {
                UINT BufferSize = 0;
                if(Params->AudioClient->lpVtbl->GetBufferSize(Params->AudioClient, &BufferSize) == 0)
                {
                    if(Params->AudioClient->lpVtbl->Start(Params->AudioClient) == 0)
                    {
                        for(;;)
                        {
                            if(WaitForSingleObject(BufferReadyEvent, INFINITE) == WAIT_OBJECT_0)
                            {
                                UINT Padding = 0;
                                if(Params->AudioClient->lpVtbl->GetCurrentPadding(Params->AudioClient, &Padding) == 0)
                                {
                                    UINT WriteAmount = BufferSize - Padding;
                                    if(WriteAmount > 0)
                                    {
                                        BYTE *Buffer = 0;
                                        if(Params->AudioRenderClient->lpVtbl->GetBuffer(Params->AudioRenderClient, WriteAmount, &Buffer) == 0)
                                        {
                                            tiny_platform_audio Audio = {0};
                                            Audio.ChannelCount = Params->ChannelCount;
                                            Audio.SampleCount = Params->SamplesPerSecond;
                                            Audio.SampleCount = WriteAmount;
                                            Audio.Buffer = Buffer;

                                            // Pass this buffer to the engine and have it fill it with the audio samples
                                            // that the game/app layer requests to play

                                            Params->AudioRenderClient->lpVtbl->ReleaseBuffer(Params->AudioRenderClient, WriteAmount, 0);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return(0);
}

static b32 
Win32InitWASAPI()
{
    b32 Result = false;

    IMMDeviceEnumerator *DeviceEnumerator = 0;
    if(CoCreateInstance(&CLSID_MMDeviceEnumerator, 0, CLSCTX_ALL, &IID_IMMDeviceEnumerator, (void **)&DeviceEnumerator) == 0)
    {
        IMMDevice *IMMDevice = 0;
        if(DeviceEnumerator->lpVtbl->GetDefaultAudioEndpoint(DeviceEnumerator, eRender, eConsole, &IMMDevice) == 0)
        {
            DeviceEnumerator->lpVtbl->Release(DeviceEnumerator);

            IAudioClient *AudioClient = 0;
            if(IMMDevice->lpVtbl->Activate(IMMDevice, &IID_IAudioClient, CLSCTX_ALL, 0, (void **)&AudioClient) == 0)
            {
                WAVEFORMATEX WaveFormat = {0};
                WaveFormat.wFormatTag = WAVE_FORMAT_PCM;
                WaveFormat.nChannels = 2;
                WaveFormat.nSamplesPerSec = 44100;
                WaveFormat.wBitsPerSample = 16;
                WaveFormat.nBlockAlign = (WaveFormat.nChannels * WaveFormat.wBitsPerSample) / 8;
                WaveFormat.nAvgBytesPerSec = (WaveFormat.nSamplesPerSec * WaveFormat.nBlockAlign);

                s64 SecondsToHundredNanos = 10000000;
                REFERENCE_TIME BufferDuration = (SecondsToHundredNanos / 20);
                if(AudioClient->lpVtbl->Initialize(AudioClient, AUDCLNT_SHAREMODE_SHARED, AUDCLNT_STREAMFLAGS_EVENTCALLBACK | AUDCLNT_STREAMFLAGS_RATEADJUST | AUDCLNT_STREAMFLAGS_AUTOCONVERTPCM, BufferDuration, 0, &WaveFormat, 0) == 0)
                {
                    IAudioRenderClient *AudioRenderClient = 0;
                    if(AudioClient->lpVtbl->GetService(AudioClient, &IID_IAudioRenderClient, (void **)&AudioRenderClient) == 0)
                    {
                        win32_audio_thread_params *AudioThreadParams = HeapAlloc(GetProcessHeap(), 0, sizeof(win32_audio_thread_params));
                        if(AudioThreadParams)
                        {
                            AudioThreadParams->AudioClient = AudioClient;
                            AudioThreadParams->AudioRenderClient = AudioRenderClient;
                            AudioThreadParams->SamplesPerSecond = WaveFormat.nSamplesPerSec;
                            AudioThreadParams->ChannelCount = WaveFormat.nChannels;

                            if(CreateThread(0, 0, Win32AudioThread, AudioThreadParams, 0, 0) != INVALID_HANDLE_VALUE)
                            {
                                Result = true;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        // TODO(zak): Logging
    }
    
    return(Result);
}

static b32 
Win32InitD3D11(HWND Window)
{
    b32 Result = false;

    UINT Flags = 0;
#if TINYENGINE_DEBUG
    Flags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    D3D_FEATURE_LEVEL SupportedFeatureLevels[3] = 
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };

    // TODO(zak): Using the default adapter is not a great idea on systems with multiple gpus, handle this.
    if(D3D11CreateDevice(0, D3D_DRIVER_TYPE_HARDWARE, 0, Flags, SupportedFeatureLevels, ArrayCount(SupportedFeatureLevels), D3D11_SDK_VERSION, &Device, &ActiveFeatureLevel, &DeviceContext) !=  0)
    {
        // TODO(zak): Log something saying we couldn't create the device with the hardware driver so now we will try the warp driver instead.
        if(D3D11CreateDevice(0, D3D_DRIVER_TYPE_WARP, 0, Flags, SupportedFeatureLevels, ArrayCount(SupportedFeatureLevels), D3D11_SDK_VERSION, &Device, &ActiveFeatureLevel, &DeviceContext) !=  0)
        {
            // TODO(zak): Log error that we couldn't initialize d3d11 with the warp driver either
        }
    }

    if(Device)
    {
        // Now we need to get the DXGIFactory from the Device to create a swapchain
        IDXGIDevice *DXGIDevice = 0;
        if(Device->lpVtbl->QueryInterface(Device, &IID_IDXGIDevice, (void **)&DXGIDevice) == 0)
        {
            IDXGIAdapter *DXGIAdapter = 0;
            if(DXGIDevice->lpVtbl->GetAdapter(DXGIDevice, &DXGIAdapter) == 0)
            {
                DXGIDevice->lpVtbl->Release(DXGIDevice);

                IDXGIFactory *DXGIFactory = 0;
                if(DXGIAdapter->lpVtbl->GetParent(DXGIAdapter, &IID_IDXGIFactory, (void **)&DXGIFactory) == 0)
                {
                    DXGIAdapter->lpVtbl->Release(DXGIAdapter);

                    int MonitorHz = 60;
                    
                    DEVMODEW DevMode = {0};
                    DevMode.dmSize = sizeof(DEVMODEW);
                    if(EnumDisplaySettingsW(0, ENUM_CURRENT_SETTINGS, &DevMode))
                    {
                        MonitorHz = DevMode.dmDisplayFrequency;
                    }
                    else
                    {
                        // TODO(zak): Logging we weren't able to query the monitorhz falling back to 60
                    }

                    DXGI_SWAP_CHAIN_DESC SwapchainDescription = {0};
                    SwapchainDescription.BufferDesc.Width = GetSystemMetrics(SM_CXSCREEN); // NOTE(zak): We will make the Swapchain's with and height the size of the monitor, so that we only need to resize the viewport and not the buffers when we get WM_SIZE
                    SwapchainDescription.BufferDesc.Height = GetSystemMetrics(SM_CYSCREEN);
                    SwapchainDescription.BufferDesc.RefreshRate.Numerator = MonitorHz;
                    SwapchainDescription.BufferDesc.RefreshRate.Denominator = 1;
                    SwapchainDescription.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM_SRGB; // BGRA Blts are faster than RGBA blts in d3d11 
                    SwapchainDescription.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
                    SwapchainDescription.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
                    SwapchainDescription.SampleDesc.Count = 1; // NOTE(zak): If we ever want MSAA you turn it on here
                    SwapchainDescription.SampleDesc.Quality = 0;
                    SwapchainDescription.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
                    SwapchainDescription.BufferCount = 1; // NOTE(zak): When/If this Swapchain goes full screen the buffer count needs to be increased to two as it wont be able to use desktop as its front buffer.
                    SwapchainDescription.OutputWindow = Window;
                    SwapchainDescription.Windowed = 1;
                    SwapchainDescription.SwapEffect = DXGI_SWAP_EFFECT_DISCARD; // TODO(zak): On Win8/10 we should be using Flip model swapchains instead, these are not supported on Win7.
                    SwapchainDescription.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH; // DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH allows us to switch between a Windows and Fullscreen modes. 

                    if(DXGIFactory->lpVtbl->CreateSwapChain(DXGIFactory, (IUnknown*)Device, &SwapchainDescription, &Swapchain) == 0)
                    {
                        DXGIFactory->lpVtbl->Release(DXGIFactory);

                        ID3D11Texture2D *Backbuffer = 0;
                        if(Swapchain->lpVtbl->GetBuffer(Swapchain, 0, &IID_ID3D11Texture2D, (void**)&Backbuffer) == 0)
                        {
                            if(Device->lpVtbl->CreateRenderTargetView(Device, (ID3D11Resource*)Backbuffer, 0, &RenderTargetView) == 0)
                            {
                                Backbuffer->lpVtbl->Release(Backbuffer);

                                RECT WindowRect = {0};
                                if(GetWindowRect(Window, &WindowRect))
                                {
                                    D3D11_VIEWPORT Viewport = {0};
                                    Viewport.Width = (FLOAT)(WindowRect.right - WindowRect.bottom);
                                    Viewport.Height = (FLOAT)(WindowRect.bottom - WindowRect.top);
                                    Viewport.MaxDepth = 1.0f;

                                    DeviceContext->lpVtbl->RSSetViewports(DeviceContext, 1, &Viewport);

                                    Result = true;
                                }
                                else
                                {
                                    // TODO(zak): Logging
                                }
                            }
                            else
                            {
                                // TODO(zak): Logging
                            }
                        }
                        else
                        {
                            // TODO(zak): Logging
                        }
                    }
                    else
                    {
                        // TODO(zak): Logging
                    }
                }
                else
                {
                    // TODO(zak): Logging
                }
            }
            else
            {
                // TODO(zak): Logging
            }
        }
        else
        {
            // TODO(zak): Logging
        }
    }                
    else
    {
        // TODO(zak): Logging
    }

    return(Result);
}

static LRESULT CALLBACK
Win32MainWindowCallback(HWND Window, UINT Message, WPARAM WParam, LPARAM LParam)
{
    LRESULT Result = 0;

    switch(Message)
    {
        case WM_CLOSE:
        {
            IsRunning = false;
        } break;

        case WM_INPUT:
        {
            UINT SizeOfBuffer;
            GetRawInputData((HRAWINPUT)LParam, RID_INPUT, NULL, &SizeOfBuffer, sizeof(RAWINPUTHEADER));
            HANDLE Heap = GetProcessHeap();
            LPBYTE Data = (LPBYTE)HeapAlloc(Heap, 0, SizeOfBuffer);
            
            if(GetRawInputData((HRAWINPUT)LParam, RID_INPUT, Data, &SizeOfBuffer, sizeof(RAWINPUTHEADER)) <= SizeOfBuffer)
            {
                RAWINPUT *RawInput = (RAWINPUT *)Data;

                tiny_event Event = {0};
                if(RawInput->header.dwType == RIM_TYPEMOUSE)
                {
                    // Mouse Buttons & Wheel
                    Event.Type = TINY_EVENT_TYPE_MOUSE;
                    Event.Mouse.InputType = TINY_INPUT_TYPE_BUTTON; // NOTE(hayden): This isn't the case for wheel events

                    USHORT CurrentMouseButton = RawInput->data.mouse.usButtonFlags;
                    switch(CurrentMouseButton)
                    {
                        case RI_MOUSE_LEFT_BUTTON_UP:
                        case RI_MOUSE_LEFT_BUTTON_DOWN:
                        {
                            Event.Mouse.Button = MOUSE_LEFT;
                            Event.Mouse.ButtonIsDown = (CurrentMouseButton & RI_MOUSE_LEFT_BUTTON_DOWN);
                        } break;

                        case RI_MOUSE_MIDDLE_BUTTON_UP:
                        case RI_MOUSE_MIDDLE_BUTTON_DOWN:
                        {
                            Event.Mouse.Button = MOUSE_MIDDLE;
                            Event.Mouse.ButtonIsDown = (CurrentMouseButton & RI_MOUSE_MIDDLE_BUTTON_DOWN) >> 4;
                        } break;

                        case RI_MOUSE_RIGHT_BUTTON_UP:
                        case RI_MOUSE_RIGHT_BUTTON_DOWN:
                        {
                            Event.Mouse.Button = MOUSE_RIGHT;
                            Event.Mouse.ButtonIsDown = (CurrentMouseButton & RI_MOUSE_RIGHT_BUTTON_DOWN) >> 2;
                        } break;

                        case RI_MOUSE_BUTTON_4_UP:
                        case RI_MOUSE_BUTTON_4_DOWN:
                        {
                            Event.Mouse.Button = MOUSE_EXTRA1;
                            Event.Mouse.ButtonIsDown = (CurrentMouseButton & RI_MOUSE_BUTTON_4_DOWN) >> 6;
                        } break;

                        case RI_MOUSE_BUTTON_5_UP:
                        case RI_MOUSE_BUTTON_5_DOWN:
                        {
                            Event.Mouse.Button = MOUSE_EXTRA2;
                            Event.Mouse.ButtonIsDown = (CurrentMouseButton & RI_MOUSE_BUTTON_5_DOWN) >> 8;
                        } break;

                        case RI_MOUSE_WHEEL:
                        {
                            Event.Mouse.InputType = TINY_INPUT_TYPE_SCROLL_WHEEL;
                            Event.Mouse.WheelDelta = RawInput->data.mouse.usButtonData;
                        } break;

                        default:
                        {
                            // TODO(hayden): Does anything else need to be handled?
                        }
                    }

                    // TODO(hayden): Assert this?
                    if(Event.Mouse.Button || Event.Mouse.WheelDelta) // Don't push events we aren't choosing to handle
                    {
                        Tiny_PushInputEvent(Event);
                    }
                } 
                else if(RawInput->header.dwType == RIM_TYPEKEYBOARD)
                {
                    // TODO(hayden): Handle Alt-F4!
                    const RAWKEYBOARD RawKeyboard = RawInput->data.keyboard;

                    UINT VirtualKey = RawKeyboard.VKey;
                    UINT ScanCode = RawKeyboard.MakeCode;
                    UINT Flags = RawKeyboard.Flags;

                    if(VirtualKey != 255)
                    {
                        if(VirtualKey == VK_SHIFT)
                        {
                            VirtualKey = MapVirtualKeyW(ScanCode, MAPVK_VSC_TO_VK_EX); // Corrects Left/Right Shift w/ VK_LSHIFT/VK_RSHIFT
                        }
                        else if(VirtualKey == VK_NUMLOCK)
                        {
                            // Corrects PAUSE/BREAK and NUMLOCK having the same scan code.. And a bug--MapVirtualKey doesn't set the extended bit!
                            ScanCode = (MapVirtualKeyW(VirtualKey, MAPVK_VK_TO_VSC) | 0x100);
                        }

                        // E0 and E1 are escape sequences used for certain special keys, such as PRINT and PAUSE/BREAK.
                        const b32 IsE0 = ((Flags & RI_KEY_E0) != 0);
                        const b32 IsE1 = ((Flags & RI_KEY_E1) != 0);

                        if(IsE1)
                        {
                            if(VirtualKey == VK_PAUSE)
                            {
                                ScanCode = 0x45; // MapVirtualKey is unable to map VK_PAUSE, so it is mapped by hand
                            }
                            else
                            {
                                ScanCode = MapVirtualKey(VirtualKey, MAPVK_VK_TO_VSC); // Turns Escape Sequence VirtualKey into correct ScanCode using MapVirtualKey
                            }
                        }

                        // Assign the last of the weird ones
                        switch(VirtualKey)
                        {
                            // Right-hand CONTROL and ALT have their E0 bit set
                            case VK_CONTROL:
                            {
                                if(IsE0)
                                {
                                    VirtualKey = VK_RCONTROL;
                                }
                                else
                                {
                                    VirtualKey = VK_LCONTROL;
                                }
                            } break;

                            case VK_MENU:
                            {
                                if(IsE0)
                                {
                                    VirtualKey = VK_RMENU;
                                }
                                else
                                {   
                                    VirtualKey = VK_LMENU;
                                }
                            } break;

                            // NUMPAD ENTER has its E0 bit set
                            case VK_RETURN:
                            {
                                if(IsE0)
                                {
                                    VirtualKey = VK_SEPARATOR;
                                } 
                            } break;

                            // The standard INSERT, DELETE, HOME, END, PRIOR and NEXT keys will always have their E0 bit set, but the corresponding keys on the NUMPAD will not
                            case VK_INSERT:
                            {
                                if(!IsE0)
                                {
                                    VirtualKey = VK_NUMPAD0;
                                }
                            } break;

                            case VK_DELETE:
                            {
                                if(!IsE0)
                                {
                                    VirtualKey = VK_DECIMAL;
                                }
                            } break;

                            case VK_HOME:
                            {
                                if(!IsE0)
                                {
                                    VirtualKey = VK_NUMPAD7;
                                }
                            } break;

                            case VK_END:
                            {
                                if(!IsE0)
                                {
                                    VirtualKey = VK_NUMPAD1;
                                }
                            } break;

                            case VK_PRIOR:
                            {
                                if(!IsE0)
                                {
                                    VirtualKey = VK_NUMPAD9;
                                }
                            } break;

                            case VK_NEXT:
                            {
                                if(!IsE0)
                                {
                                    VirtualKey = VK_NUMPAD3;
                                }
                            } break;

                            // The standard arrow keys will always have their E0 bit set, but the corresponding keys on the NUMPAD will not
                            case VK_LEFT:
                            {
                                if(!IsE0)
                                {
                                    VirtualKey = VK_NUMPAD4;
                                }
                            } break;

                            case VK_RIGHT:
                            {   
                                if(!IsE0)
                                { 
                                    VirtualKey = VK_NUMPAD6;
                                }
                            } break;

                            case VK_UP:
                            {   
                                if(!IsE0)
                                { 
                                    VirtualKey = VK_NUMPAD8;
                                }
                            } break;

                            case VK_DOWN:
                            {   
                                if(!IsE0)
                                { 
                                    VirtualKey = VK_NUMPAD2;
                                }
                            } break;

                            // NUMPAD 5 doesn't have its E0 bit set
                            case VK_CLEAR:
                            {   
                                if(!IsE0)
                                { 
                                    VirtualKey = VK_NUMPAD5;
                                }
                            } break;
                        }

                        b32 IsDown = !(Flags & RI_KEY_BREAK);

                        Event.Type = TINY_EVENT_TYPE_KEYBOARD;
                        Event.Keyboard.KeyIsDown = IsDown;
                        Event.Keyboard.KeyType = false;

                        // Assign VirtualKey to Engine's te_key_type enum
                        if((VirtualKey >= 'A') && (VirtualKey <= 'Z'))
                        {
                            for(u32 VKIndex = 'A'; VKIndex <= 'Z'; ++VKIndex)
                            {
                                if(VKIndex == VirtualKey)
                                {
                                    Event.Keyboard.KeyType = (VKIndex - 'A') + KEY_A;
                                    break;
                                }
                            }
                        }
                        else if((VirtualKey >= '0') && (VirtualKey <= '9'))
                        {
                            for(u32 VKIndex = '0'; VKIndex <= '9'; ++VKIndex)
                            {
                                int Offset = KEY_0;
                                if(VKIndex == VirtualKey)
                                {
                                    Event.Keyboard.KeyType = VKIndex - ('0' - Offset);
                                    break;
                                }
                            }
                        }
                        else if((VirtualKey >= VK_NUMPAD0) && (VirtualKey <= VK_DIVIDE))
                        {
                            int Offset = KEY_NUMPAD_0;
                            for(u32 VKIndex = VK_NUMPAD0; VKIndex <= VK_DIVIDE; ++VKIndex)
                            {
                                if(VKIndex == VirtualKey)
                                {
                                    Event.Keyboard.KeyType = VKIndex - (VK_NUMPAD0-Offset);
                                    break;
                                }
                            }
                        }
                        else if((VirtualKey >= VK_F1) && (VirtualKey <= VK_F24))
                        {
                            int Offset = KEY_F1;
                            for(u32 VKIndex = VK_F1; VKIndex <= VK_F24; ++VKIndex)
                            {
                                if(VKIndex == VirtualKey)
                                {
                                    Event.Keyboard.KeyType = VKIndex - (VK_F1-Offset);
                                    break;
                                }
                            }
                        }
                        else if((VirtualKey >= VK_LEFT) && (VirtualKey <= VK_DOWN))
                        {
                            int Offset = KEY_LEFT;
                            for(u32 VKIndex = VK_LEFT; VKIndex <= VK_DOWN; ++VKIndex)
                            {
                                if(VKIndex == VirtualKey)
                                {
                                    Event.Keyboard.KeyType = VKIndex - (VK_LEFT-Offset);
                                    break;
                                }
                            }
                        }
                        else
                        {
                            switch(VirtualKey)
                            {
                                case VK_BACK:
                                {
                                    Event.Keyboard.KeyType = KEY_BACKSPACE;
                                } break;

                                case VK_TAB:
                                {
                                    Event.Keyboard.KeyType = KEY_TAB;
                                } break;

                                case VK_RETURN:
                                {
                                    Event.Keyboard.KeyType = KEY_ENTER;
                                } break;

                                case VK_LSHIFT:
                                {
                                    Event.Keyboard.KeyType = KEY_LSHIFT;
                                } break;

                                case VK_RSHIFT:
                                {
                                    Event.Keyboard.KeyType = KEY_RSHIFT;
                                } break;

                                case VK_LCONTROL:
                                {
                                    Event.Keyboard.KeyType = KEY_LCONTROL;
                                } break;

                                case VK_RCONTROL:
                                {
                                    Event.Keyboard.KeyType = KEY_RCONTROL;
                                } break;

                                case VK_CAPITAL:
                                {
                                    Event.Keyboard.KeyType = KEY_CAPSLOCK;
                                } break;

                                ///

                                case VK_SPACE:
                                {
                                    Event.Keyboard.KeyType = KEY_SPACE;
                                } break;

                                case VK_LWIN:
                                {
                                    Event.Keyboard.KeyType = KEY_LSUPER;
                                } break;

                                case VK_RWIN:
                                {
                                    Event.Keyboard.KeyType = KEY_RSUPER;
                                } break;

                                case VK_LMENU:
                                {
                                    Event.Keyboard.KeyType = KEY_LALT;
                                } break;

                                case VK_RMENU:
                                {
                                    Event.Keyboard.KeyType = KEY_RALT;
                                } break;

                                ///

                                case VK_ESCAPE:
                                {
                                    Event.Keyboard.KeyType = KEY_ESCAPE;
                                } break;

                                case VK_PRIOR:
                                {
                                    Event.Keyboard.KeyType = KEY_PAGEUP;
                                } break;

                                case VK_NEXT:
                                {
                                    Event.Keyboard.KeyType = KEY_PAGEDOWN;
                                } break;

                                case VK_HOME:
                                {
                                    Event.Keyboard.KeyType = KEY_HOME;
                                } break;

                                case VK_END:
                                {
                                    Event.Keyboard.KeyType = KEY_END;
                                } break;

                                case VK_INSERT:
                                {
                                    Event.Keyboard.KeyType = KEY_INSERT;
                                } break;

                                case VK_DELETE:
                                {
                                    Event.Keyboard.KeyType = KEY_DELETE;
                                } break;

                                case VK_PAUSE:
                                {
                                    Event.Keyboard.KeyType = KEY_PAUSE;
                                } break;

                                case VK_NUMLOCK:
                                {
                                    Event.Keyboard.KeyType = KEY_NUMLOCK;
                                } break;

                                case VK_SCROLL: // TODO(hayden): Not being handled correctly!!!
                                {
                                    Event.Keyboard.KeyType = KEY_SCROLLLOCK;
                                } break;

                                case VK_SNAPSHOT:
                                {
                                    Event.Keyboard.KeyType = KEY_PRINTSCREEN;
                                } break;

                                ///

                                case VK_OEM_PLUS:
                                {
                                    Event.Keyboard.KeyType = KEY_PLUS;
                                } break;

                                case VK_OEM_COMMA:
                                {
                                    Event.Keyboard.KeyType = KEY_COMMA;
                                } break;

                                case VK_OEM_MINUS:
                                {
                                    Event.Keyboard.KeyType = KEY_MINUS;
                                } break;

                                case VK_OEM_1:
                                {
                                    // NOTE(hayden): Shared VKCode
                                    Event.Keyboard.KeyType = KEY_SEMICOLON;
                                } break;

                                case VK_OEM_2:
                                {
                                    // NOTE(hayden): Shared VKCode
                                    Event.Keyboard.KeyType = KEY_SLASH;
                                } break;

                                case VK_OEM_3:
                                {
                                    // NOTE(hayden): Shared VKCode
                                    Event.Keyboard.KeyType = KEY_GRAVE;
                                } break;

                                case VK_OEM_4:
                                {
                                    // NOTE(hayden): Shared VKCode
                                    Event.Keyboard.KeyType = KEY_LBRACKET;
                                } break;

                                case VK_OEM_5:
                                {
                                    // NOTE(hayden): Shared VKCode
                                    Event.Keyboard.KeyType = KEY_BACKSLASH;
                                } break;

                                case VK_OEM_6:
                                {
                                    // NOTE(hayden): Shared VKCode
                                    Event.Keyboard.KeyType = KEY_RBRACKET;
                                } break;

                                case VK_OEM_7:
                                {
                                    // NOTE(hayden): Shared VKCode
                                    Event.Keyboard.KeyType = KEY_QUOTE;
                                } break;

                                case VK_OEM_8:
                                {
                                    Event.Keyboard.KeyType = KEY_OEM_8;
                                } break;

                                case VK_OEM_102:
                                {
                                    Event.Keyboard.KeyType = KEY_OEM_102;
                                } break;

                                case 0xE1: // OEM Specific
                                {
                                    Event.Keyboard.KeyType = KEY_OEM_SPECIFIC1;
                                } break;

                                case 0xE3: // OEM Specific
                                {
                                    Event.Keyboard.KeyType = KEY_OEM_SPECIFIC2;
                                } break;

                                case 0xE4: // OEM Specific
                                {
                                    Event.Keyboard.KeyType = KEY_OEM_SPECIFIC3;
                                } break;

                                case VK_OEM_CLEAR:
                                {
                                    Event.Keyboard.KeyType = KEY_OEM_CLEAR;
                                } break;

                                ///

                                case VK_BROWSER_BACK:
                                {
                                    Event.Keyboard.KeyType = KEY_BROWSER_BACK;
                                } break;

                                case VK_BROWSER_FORWARD:
                                {
                                    Event.Keyboard.KeyType = KEY_BROWSER_FORWARD;
                                } break;

                                case VK_BROWSER_REFRESH:
                                {
                                    Event.Keyboard.KeyType = KEY_BROWSER_REFRESH;
                                } break;

                                case VK_BROWSER_STOP:
                                {
                                    Event.Keyboard.KeyType = VK_BROWSER_STOP;
                                } break;

                                case VK_BROWSER_SEARCH:
                                {
                                    Event.Keyboard.KeyType = KEY_BROWSER_SEARCH;
                                } break;

                                case VK_BROWSER_FAVORITES:
                                {
                                    Event.Keyboard.KeyType = KEY_BROWSER_FAVORITES;
                                } break;

                                case VK_BROWSER_HOME:
                                {
                                    Event.Keyboard.KeyType = KEY_BROWSER_HOME;
                                } break;

                                ///

                                case VK_VOLUME_MUTE:
                                {
                                    Event.Keyboard.KeyType = KEY_VOLUME_MUTE;
                                } break;

                                case VK_VOLUME_UP:
                                {
                                    Event.Keyboard.KeyType = KEY_VOLUME_UP;
                                } break;

                                case VK_VOLUME_DOWN:
                                {
                                    Event.Keyboard.KeyType = KEY_VOLUME_DOWN;
                                } break;

                                ///

                                case VK_MEDIA_NEXT_TRACK:
                                {
                                    Event.Keyboard.KeyType = KEY_MEDIA_NEXT_TRACK;
                                } break;

                                case VK_MEDIA_PREV_TRACK:
                                {
                                    Event.Keyboard.KeyType = KEY_MEDIA_PREV_TRACK;
                                } break;

                                case VK_MEDIA_STOP:
                                {
                                    Event.Keyboard.KeyType = KEY_MEDIA_STOP;
                                } break;

                                case VK_MEDIA_PLAY_PAUSE:
                                {
                                    Event.Keyboard.KeyType = KEY_MEDIA_PLAYPAUSE;
                                } break;

                                ///

                                case VK_LAUNCH_MAIL:
                                {
                                    Event.Keyboard.KeyType = KEY_LAUNCH_MAIL;
                                } break;

                                case VK_LAUNCH_MEDIA_SELECT:
                                {
                                    Event.Keyboard.KeyType = KEY_LAUNCH_MEDIASELECT;
                                } break;

                                case VK_LAUNCH_APP1:
                                {
                                    Event.Keyboard.KeyType = KEY_LAUNCH_APPLICATION1;
                                } break;

                                case VK_LAUNCH_APP2:
                                {
                                    Event.Keyboard.KeyType = KEY_LAUNCH_APPLICATION2;
                                } break;

                                ///

                                case VK_HELP:
                                {
                                    Event.Keyboard.KeyType = KEY_HELP;
                                } break;

                                case VK_MENU:
                                {
                                    Event.Keyboard.KeyType = KEY_MENU;
                                } break;

                                case VK_PRINT:
                                {
                                    Event.Keyboard.KeyType = KEY_PRINT;
                                } break;

                                case VK_SELECT:
                                {
                                    Event.Keyboard.KeyType = KEY_SELECT;
                                } break;

                                case VK_EXECUTE:
                                {
                                    Event.Keyboard.KeyType = KEY_EXEC;
                                } break;

                                case VK_APPS:
                                {
                                    Event.Keyboard.KeyType = KEY_APPLICATIONS;
                                } break;

                                case VK_SLEEP:
                                {
                                    Event.Keyboard.KeyType = KEY_SLEEP;
                                } break;

                                ///

                                case VK_KANA:
                                {
                                    // NOTE(hayden): Shared VKCode
                                    Event.Keyboard.KeyType = KEY_MODE_KANA;
                                } break;

                                case VK_JUNJA:
                                {
                                    Event.Keyboard.KeyType = KEY_MODE_JUNJA;
                                } break;

                                case VK_FINAL:
                                {
                                    Event.Keyboard.KeyType = KEY_MODE_FINAL;
                                } break;

                                case VK_KANJI:
                                {
                                    // NOTE(hayden): Shared VKCode
                                    Event.Keyboard.KeyType = KEY_MODE_KANJI;
                                } break;

                                ///

                                case VK_ATTN:
                                {
                                    Event.Keyboard.KeyType = KEY_ATTN;
                                } break;

                                case VK_CRSEL:
                                {
                                    Event.Keyboard.KeyType = KEY_CRSEL;
                                } break;

                                case VK_EXSEL:
                                {
                                    Event.Keyboard.KeyType = KEY_EXSEL;
                                } break;

                                case VK_EREOF:
                                {
                                    Event.Keyboard.KeyType = KEY_EREOF;
                                } break;

                                case VK_PLAY:
                                {
                                    Event.Keyboard.KeyType = KEY_PLAY;
                                } break;

                                case VK_ZOOM:
                                {
                                    Event.Keyboard.KeyType = KEY_ZOOM;

                                } break;

                                case VK_NONAME:
                                {
                                    Event.Keyboard.KeyType = KEY_NONAME;
                                } break;

                                case VK_PA1:
                                {
                                    Event.Keyboard.KeyType = KEY_PA1;
                                } break;
                            }
                        }

                        Tiny_PushInputEvent(Event);

                        // getting a human-readable string
                        //UINT Key = (ScanCode << 16) | (IsE0 << 24);
                        //char Buffer[512] = {0};
                        //GetKeyNameTextW((LONG)Key, Buffer, 512);
                    }
                }
                else if(RawInput->header.dwType == RIM_TYPEHID)
                {
                    // TODO(hayden): Controller/Joystick stuff!
                }
            }
        } break;

        case WM_MOUSEMOVE:
        {
            // Cursor
            tiny_event Event = {0};
            Event.Type = TINY_EVENT_TYPE_MOUSE;
            Event.Mouse.InputType = TINY_INPUT_TYPE_MOVE;

            Event.Mouse.X = GET_X_LPARAM(LParam);
            Event.Mouse.Y = GET_Y_LPARAM(LParam);

            // Normalized
            // TODO(hayden): Pull this out into the engine code!
            // TODO(hayden): Also, this isn't "centered" (where it's (0,0) at the center of the screen)
            //RECT ClientRect;
            //GetClientRect(Window, &ClientRect);
            //Event.Mouse.NormalizedX = (f32)Event.Mouse.X / (f32)(ClientRect.right-1);
            //Event.Mouse.NormalizedY = (f32)Event.Mouse.Y / (f32)(ClientRect.bottom-1);

            Tiny_PushInputEvent(Event);
        } break;

        default:
        {
            Result = DefWindowProcW(Window, Message, WParam, LParam);
        } break;
    }

    return(Result);
}

inline void
Win32PushValidXInputButtonEvents(int ControllerNumber, XINPUT_GAMEPAD ControllerState, tiny_controller_enum Button, int XInputButtonMask)
{
    tiny_event Event = {0};
    Event.Type = TINY_EVENT_TYPE_CONTROLLER;

    tiny_event_controller *TinyController = &Event.Controller;
    TinyController->Number = (u8)ControllerNumber;

    TinyController->ButtonIsDown = (ControllerState.wButtons & XInputButtonMask) ? true : false; // Get rid of flag so it's just 1 or 0

    if(TinyController->ButtonIsDown) 
    {
        TinyController->Button = Button;
        if(Button >= CONTROLLER_BUTTON_UP && Button <= CONTROLLER_BUTTON_BACK)
        {
            // All Digital Buttons
            TinyController->InputType = TINY_INPUT_TYPE_BUTTON;
        }
#if 0
        else if(Button == CONTROLLER_THUMBSTICK_LEFT)
        {
            Controller->InputType = TINY_INPUT_TYPE_THUMBSTICK;
            Controller->X = ControllerState.sThumbLX;
            Controller->Y = ControllerState.sThumbLY;
        }
        else if(Button == CONTROLLER_THUMBSTICK_RIGHT)
        {
            Controller->InputType = TINY_INPUT_TYPE_THUMBSTICK;
            Controller->X = ControllerState.sThumbRX;
            Controller->Y = ControllerState.sThumbRY;
        }
        else if(Button == CONTROLLER_SHOULDER_LEFT)
        {
            Controller->InputType = TINY_INPUT_TYPE_SHOULDER;
            Controller->Trigger = ControllerState.bLeftTrigger;
        }
        else if(Button == CONTROLLER_SHOULDER_RIGHT)
        {
            Controller->InputType = TINY_INPUT_TYPE_SHOULDER;
            Controller->Trigger = ControllerState.bRightTrigger;
        }
#endif

        // TODO(hayden): Should this happen here, or should it happen outside of this function for clarity?
        Tiny_PushInputEvent(Event);
    }
}

inline void
Win32PushValidXInputTriggerEvents(int ControllerNumber, XINPUT_GAMEPAD ControllerState, tiny_controller_enum EnumType)
{
    static u8 LastLeft;
    static u8 LastRight;

    tiny_event Event = {0};
    Event.Type = TINY_EVENT_TYPE_CONTROLLER;

    tiny_event_controller *TinyController = &Event.Controller;
    TinyController->Number = (u8)ControllerNumber;
    TinyController->InputType = TINY_INPUT_TYPE_TRIGGER;
    TinyController->Button = EnumType;

    if(EnumType == CONTROLLER_TRIGGER_LEFT)
    {
        if(ControllerState.bLeftTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
        {
            TinyController->Trigger = ControllerState.bLeftTrigger; 
        }
        else 
        {
            TinyController->Trigger = 0;
        }
    }
    else if(EnumType == CONTROLLER_TRIGGER_RIGHT)
    {
        if(ControllerState.bRightTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
        {
            TinyController->Trigger = ControllerState.bRightTrigger; 
        }
        else 
        {
            TinyController->Trigger = 0;
        }
    }

    if(EnumType == CONTROLLER_TRIGGER_LEFT && (ControllerState.bLeftTrigger != LastLeft))
    {
        LastLeft = ControllerState.bLeftTrigger;
        Tiny_PushInputEvent(Event);
    }
    else if(EnumType == CONTROLLER_TRIGGER_RIGHT && (ControllerState.bRightTrigger != LastRight))
    {
        LastRight = ControllerState.bRightTrigger;
        Tiny_PushInputEvent(Event);
    }
}

inline void
Win32FillXInputControllerThumbstickValues(tiny_event_controller *TinyController, SHORT XInputThumbX, SHORT XInputThumbY, int Deadzone)
{
    TinyController->ActualX = XInputThumbX;
    TinyController->ActualY = XInputThumbY;

    if(TinyController->ActualX < -32767) { TinyController->ActualX = -32767; }
    if(TinyController->ActualY < -32767) { TinyController->ActualY = -32767; }

    TinyController->Magnitude = (u32)sqrt(TinyController->ActualX*TinyController->ActualX + TinyController->ActualY*TinyController->ActualY);
    TinyController->ActualXNormalized = (f32)TinyController->ActualX / (f32)TinyController->Magnitude;
    TinyController->ActualYNormalized = (f32)TinyController->ActualY / (f32)TinyController->Magnitude;

    TinyController->DeadzonedX = (TinyController->ActualX > Deadzone) ? (TinyController->ActualX - Deadzone) : 0;
    TinyController->DeadzonedX = (TinyController->ActualX < Deadzone) ? (TinyController->ActualX + Deadzone) : TinyController->DeadzonedX;
    TinyController->DeadzonedY = (TinyController->ActualY > Deadzone) ? (TinyController->ActualY - Deadzone) : 0;
    TinyController->DeadzonedY = (TinyController->ActualY < Deadzone) ? (TinyController->ActualY + Deadzone) : TinyController->DeadzonedY;
    

    if(TinyController->Magnitude > (u32)Deadzone)
    {
        if(TinyController->Magnitude > 32767) { TinyController->Magnitude = 32767; }

        TinyController->Magnitude -= Deadzone;
        TinyController->MagnitudeNormalized = (f32)TinyController->Magnitude / (32767 - Deadzone);

        TinyController->DeadzonedXNormalized = (f32)TinyController->DeadzonedX / (f32)TinyController->Magnitude;
        TinyController->DeadzonedYNormalized = (f32)TinyController->DeadzonedY / (f32)TinyController->Magnitude;
    }
    else
    {
        TinyController->Magnitude = 0;
        TinyController->DeadzonedX = 0;
        TinyController->DeadzonedY = 0;
        TinyController->MagnitudeNormalized = 0.0f;
        TinyController->DeadzonedXNormalized = 0.0f;
        TinyController->DeadzonedYNormalized = 0.0f;
    }
}

inline void
Win32PushValidXInputThumbstickEvents(int ControllerNumber, XINPUT_GAMEPAD ControllerState, tiny_controller_enum EnumType)
{
    // Only push changed values
    static int LastLeftX;
    static int LastLeftY;
    static int LastRightX;
    static int LastRightY;

    tiny_event Event = {0};
    Event.Type = TINY_EVENT_TYPE_CONTROLLER;

    tiny_event_controller *TinyController = &Event.Controller;
    TinyController->Number = (u8)ControllerNumber;
    TinyController->InputType = TINY_INPUT_TYPE_THUMBSTICK;
    TinyController->Button = EnumType;

    if(EnumType == CONTROLLER_THUMBSTICK_LEFT)
    {
        Win32FillXInputControllerThumbstickValues(TinyController, ControllerState.sThumbLX, ControllerState.sThumbLY, XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
    }
    else if(EnumType == CONTROLLER_THUMBSTICK_RIGHT)
    {
        Win32FillXInputControllerThumbstickValues(TinyController, ControllerState.sThumbRX, ControllerState.sThumbRY, XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
    }

    if(EnumType == CONTROLLER_THUMBSTICK_LEFT && (TinyController->ActualX != LastLeftX || TinyController->ActualY != LastLeftY))
    {
        LastLeftX = TinyController->ActualX;
        LastLeftY = TinyController->ActualY;
        Tiny_PushInputEvent(Event);
    }
    else if(EnumType == CONTROLLER_THUMBSTICK_RIGHT && (TinyController->ActualX != LastRightX || TinyController->ActualX != LastRightX))
    {
        LastRightX = TinyController->ActualX;
        LastRightY = TinyController->ActualY;
        Tiny_PushInputEvent(Event);
    }
}

typedef struct vertex
{
    hmm_vec4 Position;
    hmm_vec4 Color;
} vertex;

typedef struct read_file_debug
{
    void *Contents;
    u32 FileSize;
} read_file_debug;

read_file_debug
Win32ReadFileDebug(char *Filename)
{
    read_file_debug Result = {0};

    HANDLE FileHandle = CreateFileA(Filename, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
    if(FileHandle != INVALID_HANDLE_VALUE)
    {
        LARGE_INTEGER FileSize;
        if(GetFileSizeEx(FileHandle, &FileSize))
        {
            Assert(FileSize.QuadPart <= 0xFFFFFFFF);
            u32 FileSize32 = (u32)FileSize.QuadPart;
            Result.Contents = VirtualAlloc(0, FileSize32, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE);
            if(Result.Contents)
            {
                DWORD BytesRead;
                if(ReadFile(FileHandle, Result.Contents, FileSize32, &BytesRead, 0) && (FileSize32 == BytesRead))
                {
                    // NOTE(casey): File read successfully
                    Result.FileSize = FileSize32;
                }
                else
                {                    
                    // TODO(hayden): Logging
                    VirtualFree(Result.Contents, 0, MEM_RELEASE);
                    Result.Contents = 0;
                }
            }
            else
            {
                // TODO(hayden): Logging
            }
        }
        else
        {
            // TODO(hayden): Logging
        }

        CloseHandle(FileHandle);
    }
    else
    {
        // TODO(hayden): Logging
    }

    return(Result);
}

int WINAPI
WinMain(HINSTANCE Instance, HINSTANCE PrevInstance, LPSTR CommandLine, int ShowCode)
{
    WNDCLASSW WindowClass = {0};
    WindowClass.style = CS_OWNDC;
    WindowClass.lpfnWndProc = Win32MainWindowCallback;
    WindowClass.hInstance = Instance;
    WindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WindowClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    WindowClass.lpszClassName = L"Win32TinyEngineWindowClass"; // NOTE(zak): At somepoint the window class should reflect the applications name

    if(RegisterClassW(&WindowClass))
    {
        HWND Window = CreateWindowExW(0, WindowClass.lpszClassName, L"TinyEngine", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, Instance, 0);  // NOTE(zak): At somepoint the window name should reflect the applications name
        if(Window != INVALID_HANDLE_VALUE)
        {
            // RawInput
            RAWINPUTDEVICE RawInputDevices[4]; // TODO(hayden): Joystick
            { 
                // Mouse
                RawInputDevices[0].usUsagePage = 0x01;
                RawInputDevices[0].usUsage = 0x02;
                RawInputDevices[0].dwFlags = 0;
                RawInputDevices[0].hwndTarget = Window;

                // Keyboard
                RawInputDevices[1].usUsagePage = 0x01;
                RawInputDevices[1].usUsage = 0x06;
                RawInputDevices[1].dwFlags = RIDEV_NOLEGACY;
                RawInputDevices[1].hwndTarget = Window;

                // TODO(hayden): Joystick
                RawInputDevices[2].usUsagePage = 0x01;
                RawInputDevices[2].usUsage = 0x04;
                RawInputDevices[2].dwFlags = 0;
                RawInputDevices[2].hwndTarget = Window;

                // TODO(hayden): Gamepad
                RawInputDevices[3].usUsagePage = 0x01;
                RawInputDevices[3].usUsage = 0x05;
                RawInputDevices[3].dwFlags = 0;
                RawInputDevices[3].hwndTarget = Window;
            }

            // D3D 11
        //  {
                // TODO(hayden): Hot path for debug shader reloading

                // Input Assembler
                D3D11_INPUT_ELEMENT_DESC ElementDesc[] = 
                {
                    {"POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
                    {"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0},
                };
                read_file_debug ShaderCode = Win32ReadFileDebug("shaders.fxc");
                ID3D11InputLayout *InputLayout;
                Device->lpVtbl->CreateInputLayout(Device, ElementDesc, ArrayCount(ElementDesc), &ShaderCode.Contents, ShaderCode.FileSize, &InputLayout);
                
                // Bind to device with DeviceContext->lpVtbl->VSSetShader
        //  }

            if(RegisterRawInputDevices(RawInputDevices, ArrayCount(RawInputDevices), sizeof(RAWINPUTDEVICE)))
            {
                if(Win32InitD3D11(Window))
                {
                    b32 DidComInitialize = true;
                    if(CoInitializeEx(0, COINIT_MULTITHREADED) != S_OK)
                    {
                        // NOTE(zak): I've seen CoInitializeEx fail on some systems before so if it fails lets try to just CoInitalize
                        // TODO(zak): Logging that CoInitializeEx failed
                        if(CoInitialize(0) != S_OK)
                        {
                            // TODO(zak): CoInitialize failed as well lets log this
                            DidComInitialize = false;
                        }
                    }

                    if(DidComInitialize)
                    {
                        if(!Win32InitWASAPI())
                        {
                            // TODO(zak): Logging
                        }
                    }

                    if(ShowWindow(Window, SW_SHOW) == 0)
                    {
                        IsRunning = true;
                        while(IsRunning)
                        {
                            GlobalPlatform.EventQueueSize = 0;

                            MSG Message;
                            while(PeekMessageW(&Message, Window, 0, 0, PM_REMOVE))
                            {
                                TranslateMessage(&Message);
                                DispatchMessageW(&Message);
                            }

                            // TODO(zak): I dont remember if we need to OMSetRenderTargets every frame. Lets see 
                            DeviceContext->lpVtbl->OMSetRenderTargets(DeviceContext, 1, &RenderTargetView, 0);

                            float ClearColor[4] = {1.0f, 0.0f, 0.0f, 1.0f};
                            DeviceContext->lpVtbl->ClearRenderTargetView(DeviceContext, RenderTargetView, ClearColor);

                            // XInput
                            for(DWORD ControllerIndex = 0; ControllerIndex < XUSER_MAX_COUNT; ++ControllerIndex)
                            {
                                XINPUT_STATE ControllerState = {0};
                                if(XInputGetState(ControllerIndex, &ControllerState) == ERROR_SUCCESS)
                                {
                                    // Connected
                                    XINPUT_GAMEPAD Gamepad = ControllerState.Gamepad;
                                    Win32PushValidXInputButtonEvents(ControllerIndex,     Gamepad, CONTROLLER_BUTTON_UP,           XINPUT_GAMEPAD_DPAD_UP);
                                    Win32PushValidXInputButtonEvents(ControllerIndex,     Gamepad, CONTROLLER_BUTTON_DOWN,         XINPUT_GAMEPAD_DPAD_DOWN);
                                    Win32PushValidXInputButtonEvents(ControllerIndex,     Gamepad, CONTROLLER_BUTTON_LEFT,         XINPUT_GAMEPAD_DPAD_LEFT);
                                    Win32PushValidXInputButtonEvents(ControllerIndex,     Gamepad, CONTROLLER_BUTTON_RIGHT,        XINPUT_GAMEPAD_DPAD_RIGHT);
                                    Win32PushValidXInputButtonEvents(ControllerIndex,     Gamepad, CONTROLLER_BUTTON_A,            XINPUT_GAMEPAD_A);
                                    Win32PushValidXInputButtonEvents(ControllerIndex,     Gamepad, CONTROLLER_BUTTON_B,            XINPUT_GAMEPAD_B);
                                    Win32PushValidXInputButtonEvents(ControllerIndex,     Gamepad, CONTROLLER_BUTTON_X,            XINPUT_GAMEPAD_X);
                                    Win32PushValidXInputButtonEvents(ControllerIndex,     Gamepad, CONTROLLER_BUTTON_Y,            XINPUT_GAMEPAD_Y);
                                    Win32PushValidXInputButtonEvents(ControllerIndex,     Gamepad, CONTROLLER_BUTTON_START,        XINPUT_GAMEPAD_START);
                                    Win32PushValidXInputButtonEvents(ControllerIndex,     Gamepad, CONTROLLER_BUTTON_BACK,         XINPUT_GAMEPAD_BACK);
                                    Win32PushValidXInputButtonEvents(ControllerIndex,     Gamepad, CONTROLLER_BUTTON_THUMB_LEFT,   XINPUT_GAMEPAD_LEFT_THUMB);
                                    Win32PushValidXInputButtonEvents(ControllerIndex,     Gamepad, CONTROLLER_BUTTON_THUMB_RIGHT,  XINPUT_GAMEPAD_RIGHT_THUMB);
                                    Win32PushValidXInputButtonEvents(ControllerIndex,     Gamepad, CONTROLLER_BUTTON_BUMPER_LEFT,  XINPUT_GAMEPAD_LEFT_SHOULDER);
                                    Win32PushValidXInputButtonEvents(ControllerIndex,     Gamepad, CONTROLLER_BUTTON_BUMPER_RIGHT, XINPUT_GAMEPAD_RIGHT_SHOULDER);
                                    Win32PushValidXInputTriggerEvents(ControllerIndex,    Gamepad, CONTROLLER_TRIGGER_LEFT);
                                    Win32PushValidXInputTriggerEvents(ControllerIndex,    Gamepad, CONTROLLER_TRIGGER_RIGHT);
                                    Win32PushValidXInputThumbstickEvents(ControllerIndex, Gamepad, CONTROLLER_THUMBSTICK_LEFT);
                                    Win32PushValidXInputThumbstickEvents(ControllerIndex, Gamepad, CONTROLLER_THUMBSTICK_RIGHT);
                                }   
                                else
                                {
                                    // Not connected
                                }
                            }

                            Tiny_Update(&GlobalPlatform);
                            Tiny_Render();

                            Swapchain->lpVtbl->Present(Swapchain, 1, 0); // VSync is on! Change the `1` to a `0` to turn it off
                        }
                    }
                    else
                    {
                        // TODO(zak): Logging
                    }

                    RenderTargetView->lpVtbl->Release(RenderTargetView);               
                    Swapchain->lpVtbl->Release(Swapchain);
                    DeviceContext->lpVtbl->Release(DeviceContext);
                    Device->lpVtbl->Release(Device);
                }
                else
                {
                    // TODO(zak): Loggings
                }
            }
            else
            {
                // TODO(hayden): Logging
            }
        }
        else
        {
            // TODO(zak): Logging
        }
        
    }
    else
    {
        // TODO(zak): Logging
    }

    return(0);
}