#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#include "tinyengine_types.h"
#include "tinyengine_platform.h"
#include "tinyengine_debug_utilities.h" // TODO(hayden): For debugging purposes only, make sure to remove eventually

typedef struct win32_digital_button
{
    u32 Up;
    u32 Down;
    b32 Pressed;
    b32 Released;

    b32 WMDown;
} win32_digital_button;

typedef struct win32_mouse
{
    win32_digital_button Left;
    win32_digital_button Middle;
    win32_digital_button Right;
    win32_digital_button Extra1;
    win32_digital_button Extra2;
    s16 WheelDelta;
    s32 X; // TODO(hayden): Vector, or leave as is?
    s32 Y; // TODO(hayden): Vector, or leave as is?
    f32 NormX; // TODO(hayden): Is this the normalization Kyryl was requesting?
    f32 NormY;
} win32_mouse;

#define NUM_RAW_INPUT_DEVICES 2 // NOTE(hayden): Keyboard & Mouse -- TODO(hayden): Gamepad

static win32_mouse Win32Mouse;
static win32_digital_button Win32Keyboard[0xFE];

static b32 IsRunning;
static ID3D11Device *Device;
static ID3D11DeviceContext *DeviceContext;
static IDXGISwapChain *Swapchain;
static ID3D11RenderTargetView *RenderTargetView;
static D3D_FEATURE_LEVEL ActiveFeatureLevel;

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

                    if(DXGIFactory->lpVtbl->CreateSwapChain(DXGIFactory, Device, &SwapchainDescription, &Swapchain) == 0)
                    {
                        DXGIFactory->lpVtbl->Release(DXGIFactory);

                        ID3D11Texture2D *Backbuffer = 0;
                        if(Swapchain->lpVtbl->GetBuffer(Swapchain, 0, &IID_ID3D11Texture2D, &Backbuffer) == 0)
                        {
                            if(Device->lpVtbl->CreateRenderTargetView(Device, Backbuffer, 0, &RenderTargetView) == 0)
                            {
                                Backbuffer->lpVtbl->Release(Backbuffer);

                                RECT WindowRect = {0};
                                if(GetWindowRect(Window, &WindowRect))
                                {
                                    D3D11_VIEWPORT Viewport = {0};
                                    Viewport.Width = WindowRect.right - WindowRect.bottom;
                                    Viewport.Height = WindowRect.bottom - WindowRect.top;
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
                    // TOOD(zak): Logging
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
            UINT SizeOfBuffer = sizeof(RAWINPUT);
            char Data[sizeof(RAWINPUT)] = {0};
            if(GetRawInputData((HRAWINPUT)LParam, RID_INPUT, Data, &SizeOfBuffer, sizeof(RAWINPUTHEADER)) <= SizeOfBuffer)
            {
                RAWINPUT *RawInput = (RAWINPUT *)Data;

                if(RawInput->header.dwType == RIM_TYPEMOUSE)
                {
                    // Mouse Buttons & Wheel
                    USHORT CurrentMouseButton = RawInput->data.mouse.usButtonFlags;
                    switch(CurrentMouseButton)
                    {
                        case RI_MOUSE_LEFT_BUTTON_UP:
                        case RI_MOUSE_LEFT_BUTTON_DOWN:
                        {
                            Win32Mouse.Left.WMDown = (CurrentMouseButton & RI_MOUSE_LEFT_BUTTON_DOWN);
                        } break;

                        case RI_MOUSE_MIDDLE_BUTTON_UP:
                        case RI_MOUSE_MIDDLE_BUTTON_DOWN:
                        {
                            Win32Mouse.Middle.WMDown = (CurrentMouseButton & RI_MOUSE_MIDDLE_BUTTON_DOWN);
                        } break;

                        case RI_MOUSE_RIGHT_BUTTON_UP:
                        case RI_MOUSE_RIGHT_BUTTON_DOWN:
                        {
                            Win32Mouse.Right.WMDown = (CurrentMouseButton & RI_MOUSE_RIGHT_BUTTON_DOWN);
                        } break;

                        case RI_MOUSE_BUTTON_4_UP:
                        case RI_MOUSE_BUTTON_4_DOWN:
                        {
                            Win32Mouse.Extra1.WMDown = (CurrentMouseButton & RI_MOUSE_BUTTON_4_DOWN);
                        } break;

                        case RI_MOUSE_BUTTON_5_UP:
                        case RI_MOUSE_BUTTON_5_DOWN:
                        {
                            Win32Mouse.Extra2.WMDown = (CurrentMouseButton & RI_MOUSE_BUTTON_5_DOWN);
                        } break;

                        case RI_MOUSE_WHEEL:
                        {
                            Win32Mouse.WheelDelta = RawInput->data.mouse.usButtonData;
                        } break;

                        default:
                        {
                            // TODO(hayden): Does anything else need to be handled
                        }
                    }
                }
                else if(RawInput->header.dwType == RIM_TYPEKEYBOARD)
                {
                    const RAWKEYBOARD RawKeyboard = RawInput->data.keyboard;

                    UINT VirtualKey = RawKeyboard.VKey;
                    UINT ScanCode = RawKeyboard.MakeCode;
                    UINT Flags = RawKeyboard.Flags;

                    if(VirtualKey == VK_SHIFT)
                    {
                        VirtualKey = MapVirtualKeyW(ScanCode, MAPVK_VSC_TO_VK_EX); // Corrects Left/Right Shift w/ VK_LSHIFT/VK_RSHIFT
                    }
                    else if(VirtualKey == VK_NUMLOCK)
                    {
                        // Corrects PAUSE/BREAK and NUMLOCK having the same scan code.. And a bug--MapVirtualKey doesn't set the extended bit!
                        ScanCode = (MapVirtualKeyW(VirtualKey, MAPVK_VK_TO_VSC) | 0x100);
                    }

                    if(VirtualKey != 255)
                    {
                        // e0 and e1 are escape sequences used for certain special keys, such as PRINT and PAUSE/BREAK.
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
                            // right-hand CONTROL and ALT have their e0 bit set
                            case VK_CONTROL:
                            {
                                if(IsE0)
                                {
                                    VirtualKey = VK_RCONTROL; // Keys::RIGHT_CONTROL;
                                }
                                else
                                {
                                    VirtualKey = VK_LCONTROL; // Keys::LEFT_CONTROL;
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

                            // NUMPAD ENTER has its e0 bit set
                            case VK_RETURN:
                            {
                                if(IsE0)
                                {
                                    VirtualKey = VK_SEPARATOR;
                                } 
                            } break;

                            // the standard INSERT, DELETE, HOME, END, PRIOR and NEXT keys will always have their e0 bit set, but the
                            // corresponding keys on the NUMPAD will not.
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

                            // the standard arrow keys will always have their e0 bit set, but the
                            // corresponding keys on the NUMPAD will not.
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

                            // NUMPAD 5 doesn't have its e0 bit set
                            case VK_CLEAR:
                            {   
                                if(!IsE0)
                                { 
                                    VirtualKey = VK_NUMPAD5;
                                }
                            } break;
                        }

                        b32 IsUp = (Flags & RI_KEY_BREAK);
                        b32 IsDown = !IsUp;
                        u32 CurrentKey = 0;

                        // Assign VirtualKey to Engine's te_key enum
                        switch(VirtualKey)
                        {
                            case 0x30:
                            case 0x31:
                            case 0x32:
                            case 0x33:
                            case 0x34:
                            case 0x35:
                            case 0x36:
                            case 0x37:
                            case 0x38:
                            case 0x39:
                            { // Numbers 0-9
                                for(int I = 0x30; I <= 0x39; ++I)
                                {
                                    if(I == VirtualKey)
                                    {
                                        Win32Keyboard[I - 0x30].WMDown = IsDown;
                                    }
                                }
                            } break;
                            
                            ///

                            case 0x41:
                            case 0x42:
                            case 0x43:
                            case 0x44:
                            case 0x45:
                            case 0x46:
                            case 0x47:
                            case 0x48:
                            case 0x49:
                            case 0x4A:
                            case 0x4B:
                            case 0x4C:
                            case 0x4D:
                            case 0x4E:
                            case 0x4F:
                            case 0x50:
                            case 0x51:
                            case 0x52:
                            case 0x53:
                            case 0x54:
                            case 0x55:
                            case 0x56:
                            case 0x57:
                            case 0x58:
                            case 0x59:
                            case 0x5A:
                            { // Letters A-Z
                                int Offset = 10;
                                for(int I = 0x41; I <= 0x5A; ++I)
                                {
                                    if(I == VirtualKey)
                                    {
                                        Win32Keyboard[I - (0x41-Offset)].WMDown = IsDown;
                                    }
                                }
                            } break;

                            ///

                            case VK_NUMPAD0:
                            case VK_NUMPAD1:
                            case VK_NUMPAD2:
                            case VK_NUMPAD3:
                            case VK_NUMPAD4:
                            case VK_NUMPAD5:
                            case VK_NUMPAD6:
                            case VK_NUMPAD7:
                            case VK_NUMPAD8:
                            case VK_NUMPAD9:
                            case VK_MULTIPLY:
                            case VK_ADD:
                            case VK_SEPARATOR:
                            case VK_SUBTRACT:
                            case VK_DECIMAL:
                            case VK_DIVIDE:
                            {
                                int Offset = 10 + 26;
                                for(int I = VK_NUMPAD0; I <= VK_DIVIDE; ++I)
                                {
                                    Win32Keyboard[I - (VK_NUMPAD0-Offset)].WMDown = IsDown;
                                }
                            } break;

                            ///

                            case VK_F1:
                            case VK_F2:
                            case VK_F3:
                            case VK_F4:
                            case VK_F5:
                            case VK_F6:
                            case VK_F7:
                            case VK_F8:
                            case VK_F9:
                            case VK_F10:
                            case VK_F11:
                            case VK_F12:
                            case VK_F13:
                            case VK_F14:
                            case VK_F15:
                            case VK_F16:
                            case VK_F17:
                            case VK_F18:
                            case VK_F19:
                            case VK_F20:
                            case VK_F21:
                            case VK_F22:
                            case VK_F23:
                            case VK_F24:
                            {
                                int Offset = 10 + 26 + 16;
                                for(int I = VK_F1; I <= VK_F24; ++I)
                                {
                                    Win32Keyboard[I - (VK_F1-Offset)].WMDown = IsDown;
                                }
                            } break;

                            ///

                            case VK_LEFT:
                            case VK_UP:
                            case VK_RIGHT:
                            case VK_DOWN:
                            {
                                int Offset = 10 + 26 + 16 + 24;
                                for(int I = VK_LEFT; I <= VK_DOWN; ++I)
                                {
                                    Win32Keyboard[I - (VK_LEFT-Offset)].WMDown = IsDown;
                                }
                            } break;

                            ///

                            case VK_BACK:
                            {
                                Win32Keyboard[KEY_BACKSPACE].WMDown = IsDown;
                            } break;

                            case VK_TAB:
                            {
                                Win32Keyboard[KEY_TAB].WMDown = IsDown;
                            } break;

                            case VK_RETURN:
                            {
                                Win32Keyboard[KEY_RETURN].WMDown = IsDown;
                            } break;

                            case VK_LSHIFT:
                            {
                                Win32Keyboard[KEY_LSHIFT].WMDown = IsDown;
                            } break;

                            case VK_RSHIFT:
                            {
                                Win32Keyboard[KEY_RSHIFT].WMDown = IsDown;
                            } break;

                            case VK_LCONTROL:
                            {
                                Win32Keyboard[KEY_LCONTROL].WMDown = IsDown;
                            } break;

                            case VK_RCONTROL:
                            {
                                Win32Keyboard[KEY_RCONTROL].WMDown = IsDown;
                            } break;

                            case VK_CAPITAL:
                            {
                                Win32Keyboard[KEY_CAPSLOCK].WMDown = IsDown;
                            } break;

                            ///

                            case VK_SPACE:
                            {
                                Win32Keyboard[KEY_SPACE].WMDown = IsDown;
                            } break;

                            case VK_LWIN:
                            {
                                Win32Keyboard[KEY_LSUPER].WMDown = IsDown;
                            } break;

                            case VK_RWIN:
                            {
                                Win32Keyboard[KEY_RSUPER].WMDown = IsDown;
                            } break;

                            case VK_LMENU:
                            {
                                Win32Keyboard[KEY_LALT].WMDown = IsDown;
                            } break;

                            case VK_RMENU:
                            {
                                Win32Keyboard[KEY_RALT].WMDown = IsDown;
                            } break;

                            ///

                            case VK_ESCAPE:
                            {
                                Win32Keyboard[KEY_ESCAPE].WMDown = IsDown;
                            } break;

                            case VK_PRIOR:
                            {
                                Win32Keyboard[KEY_PAGEUP].WMDown = IsDown;
                            } break;

                            case VK_NEXT:
                            {
                                Win32Keyboard[KEY_PAGEDOWN].WMDown = IsDown;
                            } break;

                            case VK_HOME:
                            {
                                Win32Keyboard[KEY_HOME].WMDown = IsDown;
                            } break;

                            case VK_END:
                            {
                                Win32Keyboard[KEY_END].WMDown = IsDown;
                            } break;

                            case VK_INSERT:
                            {
                                Win32Keyboard[KEY_INSERT].WMDown = IsDown;
                            } break;

                            case VK_DELETE:
                            {
                                Win32Keyboard[KEY_DELETE].WMDown = IsDown;
                            } break;

                            case VK_PAUSE:
                            {
                                Win32Keyboard[KEY_PAUSE].WMDown = IsDown;
                            } break;

                            case VK_NUMLOCK:
                            {
                                Win32Keyboard[KEY_NUMLOCK].WMDown = IsDown;
                            } break;

                            case VK_SCROLL: // TODO(hayden): Not being handled correctly!!!
                            {
                                Win32Keyboard[KEY_SCROLLLOCK].WMDown = IsDown;
                            } break;

                            case VK_SNAPSHOT:
                            {
                                Win32Keyboard[KEY_PRINTSCREEN].WMDown = IsDown;
                            } break;

                            ///

                            case VK_OEM_PLUS:
                            {
                                Win32Keyboard[KEY_PLUS].WMDown = IsDown;
                            } break;

                            case VK_OEM_COMMA:
                            {
                                Win32Keyboard[KEY_COMMA].WMDown = IsDown;
                            } break;

                            case VK_OEM_MINUS:
                            {
                                Win32Keyboard[KEY_MINUS].WMDown = IsDown;
                            } break;

                            case VK_OEM_1:
                            {
                                // NOTE(hayden): Shared VKCode
                                Win32Keyboard[KEY_SEMICOLON].WMDown = IsDown;
                                Win32Keyboard[KEY_OEM_1].WMDown = IsDown;
                            } break;

                            case VK_OEM_2:
                            {
                                // NOTE(hayden): Shared VKCode
                                Win32Keyboard[KEY_SLASH].WMDown = IsDown;
                                Win32Keyboard[KEY_OEM_2].WMDown = IsDown;
                            } break;

                            case VK_OEM_3:
                            {
                                // NOTE(hayden): Shared VKCode
                                Win32Keyboard[KEY_GRAVE].WMDown = IsDown;
                                Win32Keyboard[KEY_OEM_3].WMDown = IsDown;
                            } break;

                            case VK_OEM_4:
                            {
                                // NOTE(hayden): Shared VKCode
                                Win32Keyboard[KEY_LBRACKET].WMDown = IsDown;
                                Win32Keyboard[KEY_OEM_4].WMDown = IsDown;
                            } break;

                            case VK_OEM_5:
                            {
                                // NOTE(hayden): Shared VKCode
                                Win32Keyboard[KEY_BACKSLASH].WMDown = IsDown;
                                Win32Keyboard[KEY_OEM_5].WMDown = IsDown;
                            } break;

                            case VK_OEM_6:
                            {
                                // NOTE(hayden): Shared VKCode
                                Win32Keyboard[KEY_RBRACKET].WMDown = IsDown;
                                Win32Keyboard[KEY_OEM_6].WMDown = IsDown;
                            } break;

                            case VK_OEM_7:
                            {
                                // NOTE(hayden): Shared VKCode
                                Win32Keyboard[KEY_QUOTE].WMDown = IsDown;
                                Win32Keyboard[KEY_OEM_7].WMDown = IsDown;
                            } break;

                            case VK_OEM_8:
                            {
                                Win32Keyboard[KEY_OEM_8].WMDown = IsDown;
                            } break;

                            case VK_OEM_102:
                            {
                                Win32Keyboard[KEY_OEM_102].WMDown = IsDown;
                            } break;

                            case 0xE1: // OEM Specific
                            {
                                Win32Keyboard[KEY_OEM_SPEC1].WMDown = IsDown;
                            } break;

                            case 0xE3: // OEM Specific
                            {
                                Win32Keyboard[KEY_OEM_SPEC2].WMDown = IsDown;
                            } break;

                            case 0xE4: // OEM Specific
                            {
                                Win32Keyboard[KEY_OEM_SPEC3].WMDown = IsDown;
                            } break;

                            case VK_OEM_CLEAR:
                            {
                                Win32Keyboard[KEY_OEM_CLEAR].WMDown = IsDown;
                            } break;

                            ///

                            case VK_BROWSER_BACK:
                            {
                                Win32Keyboard[KEY_BROWSER_BACK].WMDown = IsDown;
                            } break;

                            case VK_BROWSER_FORWARD:
                            {
                                Win32Keyboard[KEY_BROWSER_FORWARD].WMDown = IsDown;
                            } break;

                            case VK_BROWSER_REFRESH:
                            {
                                Win32Keyboard[KEY_BROWSER_REFRESH].WMDown = IsDown;
                            } break;

                            case VK_BROWSER_STOP:
                            {
                                Win32Keyboard[VK_BROWSER_STOP].WMDown = IsDown;
                            } break;

                            case VK_BROWSER_SEARCH:
                            {
                                Win32Keyboard[KEY_BROWSER_SEARCH].WMDown = IsDown;
                            } break;

                            case VK_BROWSER_FAVORITES:
                            {
                                Win32Keyboard[KEY_BROWSER_FAVORITES].WMDown = IsDown;
                            } break;

                            case VK_BROWSER_HOME:
                            {
                                Win32Keyboard[KEY_BROWSER_HOME].WMDown = IsDown;
                            } break;

                            ///

                            case VK_VOLUME_MUTE:
                            {
                                Win32Keyboard[KEY_VOLUME_MUTE].WMDown = IsDown;
                            } break;

                            case VK_VOLUME_UP:
                            {
                                Win32Keyboard[KEY_VOLUME_UP].WMDown = IsDown;
                            } break;

                            case VK_VOLUME_DOWN:
                            {
                                Win32Keyboard[KEY_VOLUME_DOWN].WMDown = IsDown;
                            } break;

                            ///

                            case VK_MEDIA_NEXT_TRACK:
                            {
                                Win32Keyboard[KEY_MEDIA_NEXT_TRACK].WMDown = IsDown;
                            } break;

                            case VK_MEDIA_PREV_TRACK:
                            {
                                Win32Keyboard[KEY_MEDIA_PREV_TRACK].WMDown = IsDown;
                            } break;

                            case VK_MEDIA_STOP:
                            {
                                Win32Keyboard[KEY_MEDIA_STOP].WMDown = IsDown;
                            } break;

                            case VK_MEDIA_PLAY_PAUSE:
                            {
                                Win32Keyboard[KEY_MEDIA_PLAYPAUSE].WMDown = IsDown;
                            } break;

                            ///

                            case VK_LAUNCH_MAIL:
                            {
                                Win32Keyboard[KEY_LAUNCH_MAIL].WMDown = IsDown;
                            } break;

                            case VK_LAUNCH_MEDIA_SELECT:
                            {
                                Win32Keyboard[KEY_LAUNCH_MEDIASELECT].WMDown = IsDown;
                            } break;

                            case VK_LAUNCH_APP1:
                            {
                                Win32Keyboard[KEY_LAUNCH_APP1].WMDown = IsDown;
                            } break;

                            case VK_LAUNCH_APP2:
                            {
                                Win32Keyboard[KEY_LAUNCH_APP2].WMDown = IsDown;
                            } break;

                            ///

                            case VK_HELP:
                            {
                                Win32Keyboard[KEY_HELP].WMDown = IsDown;
                            } break;

                            case VK_MENU:
                            {
                                Win32Keyboard[KEY_MENU].WMDown = IsDown;
                            } break;

                            case VK_PRINT:
                            {
                                Win32Keyboard[KEY_PRINT].WMDown = IsDown;
                            } break;

                            case VK_SELECT:
                            {
                                Win32Keyboard[KEY_SELECT].WMDown = IsDown;
                            } break;

                            case VK_EXECUTE:
                            {
                                Win32Keyboard[KEY_EXEC].WMDown = IsDown;
                            } break;

                            case VK_APPS:
                            {
                                Win32Keyboard[KEY_APPLICATION].WMDown = IsDown;
                            } break;

                            case VK_SLEEP:
                            {
                                Win32Keyboard[KEY_SLEEP].WMDown = IsDown;
                            } break;

                            ///

                            case VK_KANA:
                            {
                                // NOTE(hayden): Shared VKCode
                                Win32Keyboard[KEY_MODE_KANA].WMDown = IsDown;
                                Win32Keyboard[KEY_MODE_HANGEUL].WMDown = IsDown;
                                Win32Keyboard[KEY_MODE_JUNJA].WMDown = IsDown;
                            } break;

                            case VK_JUNJA:
                            {
                                Win32Keyboard[KEY_MODE_JUNJA].WMDown = IsDown;
                            } break;

                            case VK_FINAL:
                            {
                                Win32Keyboard[KEY_MODE_FINAL].WMDown = IsDown;
                            } break;

                            case VK_KANJI:
                            {
                                // NOTE(hayden): Shared VKCode
                                Win32Keyboard[KEY_MODE_HANJA].WMDown = IsDown;
                                Win32Keyboard[KEY_MODE_KANJI].WMDown = IsDown;
                            } break;

                            ///

                            case VK_ATTN:
                            {
                                Win32Keyboard[KEY_ATTN].WMDown = IsDown;
                            } break;

                            case VK_CRSEL:
                            {
                                Win32Keyboard[KEY_CRSEL].WMDown = IsDown;
                            } break;

                            case VK_EXSEL:
                            {
                                Win32Keyboard[KEY_EXSEL].WMDown = IsDown;
                            } break;

                            case VK_EREOF:
                            {
                                Win32Keyboard[KEY_EREOF].WMDown = IsDown;
                            } break;

                            case VK_PLAY:
                            {
                                Win32Keyboard[KEY_PLAY].WMDown = IsDown;
                            } break;

                            case VK_ZOOM:
                            {
                                Win32Keyboard[KEY_ZOOM].WMDown = IsDown;
                            } break;

                            case VK_NONAME:
                            {
                                Win32Keyboard[KEY_NONAME].WMDown = IsDown;
                            } break;

                            case VK_PA1:
                            {
                                Win32Keyboard[KEY_PA1].WMDown = IsDown;
                            } break;
                        }

                        // getting a human-readable string
                        //UINT Key = (ScanCode << 16) | (IsE0 << 24);
                        //char Buffer[512] = {0};
                        //GetKeyNameTextW((LONG)Key, Buffer, 512);
                    }
                }
            }
        } break;

        case WM_MOUSEMOVE:
        {
            // Cursor
            Win32Mouse.X = LParam & 0xFFFF; // TODO(hayden): There is a macro for this in <windowsx.h>
            Win32Mouse.Y = (LParam >> 16) & 0xFFFF; // TODO(hayden): There is a macro for this in <windowsx.h>

            // Normalized
            // TODO(hayden): Pull this out into the engine code!
            // TODO(hayden): Also, this isn't "centered" (where it's (0,0) at the center of the screen)
            RECT ClientRect;
            GetClientRect(Window, &ClientRect);
            Win32Mouse.NormX =  (f32)Win32Mouse.X / (f32)(ClientRect.right-1);
            Win32Mouse.NormY = (f32)Win32Mouse.Y / (f32)(ClientRect.bottom-1);
        } break;

        default:
        {
            Result = DefWindowProcW(Window, Message, WParam, LParam);
        } break;
    }

    return(Result);
}

static void
Win32ProcessDigitalButton(win32_digital_button *Button)
{
    // TODO(hayden): Avoid wrapping Up/Down?
    b32 IsDown = Button->WMDown;
    Button->Down = IsDown ? ++Button->Down : false;
    Button->Up = !IsDown ? ++Button->Up : false;
    Button->Pressed = (Button->Down == 1);
    Button->Released = (Button->Up == 1);
}

// TODO(hayden): Split into multiple functions?
static void
Win32UpdateInput(win32_mouse *Win32Mouse, win32_digital_button *Win32Keyboard)
{
    Win32ProcessDigitalButton(&Win32Mouse->Left);
    Win32ProcessDigitalButton(&Win32Mouse->Middle);
    Win32ProcessDigitalButton(&Win32Mouse->Right);
    Win32ProcessDigitalButton(&Win32Mouse->Extra1);
    Win32ProcessDigitalButton(&Win32Mouse->Extra2);

    // Keyboard
    for(int KeyIndex = 0; KeyIndex < (sizeof(Win32Keyboard) / sizeof(Win32Keyboard[0])) ; ++KeyIndex)
    {
        Win32ProcessDigitalButton(&Win32Keyboard[KeyIndex]);
    }
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
            // Input
            RAWINPUTDEVICE RawInputDevices[NUM_RAW_INPUT_DEVICES];
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
            }

            if(RegisterRawInputDevices(RawInputDevices, NUM_RAW_INPUT_DEVICES, sizeof(RAWINPUTDEVICE)))
            {
                if(Win32InitD3D11(Window))
                {
                    if(ShowWindow(Window, SW_SHOW) == 0)
                    {
                        IsRunning = true;

                        while(IsRunning)
                        {
                            MSG Message;
                            while(PeekMessageW(&Message, Window, 0, 0, PM_REMOVE))
                            {
                                TranslateMessage(&Message);
                                DispatchMessageW(&Message);
                            }

                            Win32UpdateInput(&Win32Mouse, Win32Keyboard);

                            // TODO(zak): I dont remember if we need to OMSetRenderTargets every frame. Lets see 
                            DeviceContext->lpVtbl->OMSetRenderTargets(DeviceContext, 1, &RenderTargetView, 0);

                            float ClearColor[4] = {1.0f, 0.0f, 0.0f, 1.0f};
                            DeviceContext->lpVtbl->ClearRenderTargetView(DeviceContext, RenderTargetView, ClearColor);
                            
                            // Update App
                            // Render App

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