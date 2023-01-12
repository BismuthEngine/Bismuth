export module Fiber:FiberWindow;

export import :FiberDispatcher;

export import Sodium;

import Types;

export class IFiberWindow {
protected:
    const FiberDispatcher* eventDispatcher;
    const SodiumRenderer* renderer;

public:
    IFiberWindow() {
        eventDispatcher = new FiberDispatcher();
        renderer = new SodiumRenderer();
    }

    virtual void Initialize(SString title, unsigned int width, unsigned int height, bool fullscreen = false) {}
    
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