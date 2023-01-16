export module Fiber:Win32FiberWindow;

import :FiberWindow;
import :WindowsHeaderWrapper;

import Sodium;
 
import Types;

export class Win32FiberWindow : public IFiberWindow {
protected:
    HWnd hwnd;
    HInstance hInstance;
    Msg msg;

    static LResult WindowProc(HWnd hwnd, UInt uMsg, WParam wParam, LParam lParam) {
        switch(uMsg) {
            case WinAPIStatics::WM_Destroy:

                return 0;
            case WinAPIStatics::WM_Create:

                return 0;
            case WinAPIStatics::WM_KeyDown:

                return 0;
            case WinAPIStatics::WM_KeyUp:

                return 0;
        }

        return DefWindowProcStub(hwnd, uMsg, wParam, lParam);
    }
public:
    Win32FiberWindow() {
    }

    virtual void Initialize(const char* title, unsigned int width, unsigned int height, bool fullscreen = false) {
        // Get HINSTANCE
        hInstance = GetModuleHandleStub(0); 

        // Register the window class.
        //const Wchar_t CLASS_NAME[] = title.Data();

        WndClass wc = { 0 };

        wc.lpfnWndProc   = Win32FiberWindow::WindowProc;
        wc.hInstance     = hInstance;
        wc.lpszClassName = title;

        RegisterClassStub(&wc);

        // Create the window.

        hwnd = CreateWindowExStub(
            0,                              // Optional window styles.
            title,                     // Window class
            "Bismuth",                     // Window text
            WinAPIStatics::WS_OverlappedWindow,            // Window style

            // Size and position
            WinAPIStatics::CW_UseDefault, WinAPIStatics::CW_UseDefault, WinAPIStatics::CW_UseDefault, WinAPIStatics::CW_UseDefault,

            0,       // Parent window    
            0,       // Menu
            hInstance,  // Instance handle
            0        // Additional application data
            );

        if (hwnd == 0)
        {
            // CRITICAL ERROR
           
        }

        renderer->InitializeWithSurface(ESurfaceType::Win32, hwnd);
    }
    
    virtual void Show() override {ShowWindowStub(hwnd, false);}
    virtual void Hide() override {}

    virtual void Minimize() override {}
    virtual void Maximize() override {}
    virtual void Restore() override {}

    virtual void MinMax() override {}

    virtual void SetTitle(SString title) override {}

    virtual void SetWidth(unsigned int width) override {}
    virtual void SetHeight(unsigned int height) override {}

    virtual void SetFullscreen(bool fullscreen) override {}

    virtual void Tick() override {
        if(GetMessageStub(&msg, 0, 0, 0) > 0) {
            TranslateMessageStub(&msg);
            DispatchMessageStub(&msg);
        } else {
            bShouldClose = true;
        }
    }
};