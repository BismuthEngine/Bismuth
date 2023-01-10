export module Fiber:FiberWindow;

export import :FiberDispatcher;

export class IFiberWindow {
protected:
    const FiberDispatcher* eventDispatcher;

public:
    IFiberWindow() {
        eventDispatcher = new FiberDispatcher();
    }
};