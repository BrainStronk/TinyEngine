#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "tinyengine_types.h"

static b32 IsRunning;

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
            // TODO(zak): Initalize D3D11 here

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

                    // Clear the window
                    
                    // Update App
                    // Render App

                    // Present Backbuffer 
                }
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