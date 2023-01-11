export module SodiumAPI:SodiumSurface;

export enum class ESurfaceType {
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
    const void* pHandle;
};

export class ISodiumSurface {

};