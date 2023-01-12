export module Fiber:Win32FiberWindow;

import :FiberWindow;
import :WindowsHeaderWrapper;
 
import Types;

export class Win32FiberWindow : public IFiberWindow {
protected:
    HWnd hwnd;
    HInstance hInstance;
public:
    Win32FiberWindow() {
    }

    virtual void Initialize(SString title, unsigned int width, unsigned int height, bool fullscreen = false) {
        // Get HINSTANCE
        hInstance = GetModuleHandleStub(0); 

        // Register the window class.
        //const Wchar_t CLASS_NAME[] = title.Data();

        WndClass wc = { };

        //wc.lpfnWndProc   = WindowProc;
        wc.hInstance     = hInstance;
        wc.lpszClassName = title.Data();

        RegisterClassStub(&wc);

        // Create the window.

        hwnd = CreateWindowExStub(
            0,                              // Optional window styles.
            title.Data(),                     // Window class
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
    }
    
    virtual void Show() {}
    virtual void Hide() {}

    virtual void Minimize() {}
    virtual void Maximize() {}
    virtual void Restore() {}

    virtual void MinMax() {}

    virtual void SetTitle(SString title) {}

    virtual void SetWidth(unsigned int width) {}
    virtual void SetHeight(unsigned int height) {}

    virtual void SetFullscreen(bool fullscreen) {}
};