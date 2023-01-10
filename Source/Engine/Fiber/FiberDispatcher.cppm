export module Fiber:FiberDispatcher;

export import :FiberEvent;

export typedef void (*FiberSubscriptionDelegate)(const FiberEvent&);

export class FiberDispatcher {

};