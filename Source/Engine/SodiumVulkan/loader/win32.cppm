module;

#include <windows.h>

export module SodiumVulkan:win32;

export HWND ExtractHWND(void* hWnd) {
    return *static_cast<HWND*>(hWnd);
}

export HINSTANCE GetWindowInstance(void* hWnd) {
    return (HINSTANCE)GetWindowLong(ExtractHWND(hWnd), -6);
}

export HINSTANCE GetThisModuleInstance() {
    return GetModuleHandle(nullptr);
}