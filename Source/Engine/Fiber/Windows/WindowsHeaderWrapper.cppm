// Essential wrapper around windows.h for llvm clang frontend

module;

#include <windows.h>

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

export typedef WNDCLASS WndClass;

export namespace WinAPIStatics {
    const inline DWord WS_OverlappedWindow = WS_OVERLAPPEDWINDOW;

    const inline DWord CW_UseDefault = CW_USEDEFAULT;
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