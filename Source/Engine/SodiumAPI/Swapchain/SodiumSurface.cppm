export module SodiumAPI:SodiumSurface;

export enum class ESurfaceType : unsigned int {
    Win32,
    Wayland,
    X11,
    Appkit
};

export struct SodiumSurfaceCreateInfo {
    ESurfaceType surfaceType;
    // NSView for MacOS
    // HWND for Win32
    // Display for XLib
    // wl_display for Wayland
    void* pHandle;
};

export class ISodiumSurface {

};