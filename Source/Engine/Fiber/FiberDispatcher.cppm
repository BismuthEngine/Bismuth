export module Fiber:FiberDispatcher;

export import :FiberEvent;
import Types;

export typedef void (*FiberSubscriptionDelegate)(const FiberEvent&);

export class FiberDispatcher {
    TArray<FiberSubscriptionDelegate> subscribers; 
public:
    FiberDispatcher() {

    }

    void Subscribe(const FiberSubscriptionDelegate& subscriber) {
        subscribers.Add(subscriber);
    }

    void Dispatch(const FiberEvent& event) {
        
    }

};