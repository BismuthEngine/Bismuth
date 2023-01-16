// Essential wrapper around windows.h for llvm clang frontend

module;

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#pragma comment(lib, "user32.lib")

export module Fiber:WindowsHeaderWrapper;

export typedef HWND HWnd;
export typedef HINSTANCE HInstance;
export typedef HMODULE HModule;
export typedef HMENU HMenu;

export typedef LPCSTR LPCStr;
export typedef LPVOID LPVoid;
export typedef wchar_t Wchar_t;
export typedef ATOM Atom;
export typedef DWORD DWord;
export typedef LRESULT LResult;
export typedef UINT UInt;
export typedef WPARAM WParam;
export typedef LPARAM LParam;
export typedef MSG Msg;
export typedef LPMSG LPMsg;
export typedef LONG_PTR LongPtr;

export typedef WNDCLASS WndClass;

export namespace WinAPIStatics {
    const inline DWord WS_OverlappedWindow = WS_OVERLAPPEDWINDOW;
    const inline DWord WS_Visible = WS_VISIBLE;

    const inline DWord CW_UseDefault = CW_USEDEFAULT;

    const inline UInt WM_Destroy = WM_DESTROY;
    const inline UInt WM_Paint = WM_PAINT;
    const inline UInt WM_KeyDown = WM_KEYDOWN;
    const inline UInt WM_KeyUp = WM_KEYUP;
    const inline UInt WM_LButtonDown = WM_LBUTTONDOWN;
    const inline UInt WM_LButtonUp = WM_LBUTTONUP;
    const inline UInt WM_RButtonDown = WM_RBUTTONDOWN;
    const inline UInt WM_RButtonUp = WM_RBUTTONUP;
    const inline UInt WM_MButtonDown = WM_MBUTTONDOWN;
    const inline UInt WM_MButtonUp = WM_MBUTTONUP;
    const inline UInt WM_Create = WM_CREATE;

}

export HModule GetModuleHandleStub(LPCStr handle) {
    return GetModuleHandle(handle);
}

export Atom RegisterClassStub(const WndClass* obj) {
    return RegisterClass(obj);
}

export HWnd CreateWindowExStub(DWord exStyle, LPCStr className, LPCStr winName, DWord dwStyle, int x, int y, int w, int h, HWnd parent, HMenu menu, HInstance hI, LPVoid lpParam) {
    return CreateWindowEx(exStyle, className, winName, dwStyle, x, y, w, h, parent, menu, hI, lpParam);
}

export LResult DefWindowProcStub(HWnd hwnd, UInt uMsg, WParam w, LParam l) {
    return DefWindowProc(hwnd, uMsg, w, l);
}

export int ShowWindowStub(HWnd hwnd, int nCmdShow) {
    return ShowWindow(hwnd, nCmdShow);
}

export int GetMessageStub(LPMsg msg, HWnd hwnd, UInt min, UInt max) {
    return GetMessage(msg, hwnd, min, max);
}

export int TranslateMessageStub(LPMsg msg) {
    return TranslateMessage(msg);
}

export int DispatchMessageStub(LPMsg msg) {
    return DispatchMessage(msg);
}

export LongPtr SetWindowLongPtrStub(HWnd hwnd, int idx, LongPtr newLong) {
    return SetWindowLongPtr(hwnd, idx, newLong);
}

export LongPtr GetWindowLongPtrStub(HWnd hwnd, int idx) {
    return GetWindowLongPtr(hwnd, idx);
}

export void PostQuitMessageStub(int exitCode) {
    return PostQuitMessage(exitCode);
}