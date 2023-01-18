export module Fiber:Win32FiberWindow;

import :FiberWindow;
import :WindowsHeaderWrapper;

import Sodium;
 
import Types;
import Log;

export class Win32FiberWindow : public IFiberWindow {
protected:
    HWnd hwnd = 0;
    HInstance hInstance = 0;
    Msg msg;

    static LResult WindowProc(HWnd hwnd, UInt uMsg, WParam wParam, LParam lParam) {
        switch(uMsg) {
            case WinAPIStatics::WM_Destroy:
                PostQuitMessageStub(0);
                break;
            case WinAPIStatics::WM_Create:

                break;
            case WinAPIStatics::WM_KeyDown:

                break;
            case WinAPIStatics::WM_KeyUp:

                break;
        }

        return DefWindowProcStub(hwnd, uMsg, wParam, lParam);
    }
public:
    Win32FiberWindow() {
    }

    virtual void Initialize(const char* title, unsigned int width, unsigned int height, bool fullscreen = false) override {
        // Get HINSTANCE
        hInstance = GetModuleHandleStub(0); 

        // Register the window class.
        //const Wchar_t CLASS_NAME[] = title.Data();

        WndClass wc = { 0 };

        wc.lpfnWndProc   = Win32FiberWindow::WindowProc;
        wc.hInstance     = hInstance;
        wc.hCursor = LoadCursorStub(0, WinAPIStatics::IDC_Arrow);
        wc.lpszClassName = title;

        if(!RegisterClassStub(&wc)) {
            // CRITICAL ERROR
            Logger::CriticalError("");
        }

        // Create the window.

        hwnd = CreateWindowExStub(
            0,                              // Optional window styles.
            title,                     // Window class
            "Bismuth",                     // Window text
            WinAPIStatics::WS_Visible | WinAPIStatics::WS_OverlappedWindow,            // Window style

            // Size and position
            WinAPIStatics::CW_UseDefault, WinAPIStatics::CW_UseDefault, width, height,

            0,       // Parent window    
            0,       // Menu
            hInstance,  // Instance handle
            0        // Additional application data
            );

        if (hwnd == 0)
        {
            // CRITICAL ERROR
            Logger::CriticalError("");
        }

        Logger::Log("Fiber: Window created");

        renderer->InitializeWithSurface(ESurfaceType::Win32, hwnd);
    }
    
    virtual void Show() override {ShowWindowStub(hwnd, true);}
    virtual void Hide() override {ShowWindowStub(hwnd, false);}

    virtual void Minimize() override {}
    virtual void Maximize() override {}
    virtual void Restore() override {}

    virtual void MinMax() override {}

    virtual void SetTitle(SString title) override {}

    virtual void SetWidth(unsigned int width) override {}
    virtual void SetHeight(unsigned int height) override {}

    virtual void SetFullscreen(bool fullscreen) override {}

    virtual void ShowCursor(bool show) override {ShowCursorStub(show);}

    virtual void Tick() override {
        if(GetMessageStub(&msg, 0, 0, 0) > 0) {
            TranslateMessageStub(&msg);
            DispatchMessageStub(&msg);
        } else {
            bShouldClose = true;
        }
    }
};