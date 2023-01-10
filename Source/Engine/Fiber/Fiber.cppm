export module Fiber;

export import :FiberWindow;
#ifdef PLATFORM_WINDOWS
    export import :Win32FiberWindow;
#endif
#ifdef PLATFORM_LINUX
    export import :WaylandFiberWindow;
    export import :X11FiberWindow;
#endif
#ifdef PLATFORM_MAC
    export import :AppkitFiberWindow;
#endif

export class FiberFactory {
public:
    static IFiberWindow* CreateWindow() {return new Win32FiberWindow();} 
};