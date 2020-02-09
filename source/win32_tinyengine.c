#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#include "tinyengine_types.h"

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

        default:
        {
            Result = DefWindowProcW(Window, Message, WParam, LParam);
        } break;
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
            // TODO(zak): Logging
        }
        
    }
    else
    {
        // TODO(zak): Logging
    }

    return(0);
}