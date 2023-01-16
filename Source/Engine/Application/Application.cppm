export module Application;

import Engine;
import Fiber;

export class SApplication {
protected:
    static SApplication* GlobalApplication;

    SEngine *localEngine;

    IFiberWindow *window;
public:
    SApplication() {
        if(SApplication::GlobalApplication) {
            // Error
        }

        SApplication::GlobalApplication = this;

        localEngine = new SEngine();

        window = FiberFactory::CreateWindow();

        window->Initialize("Bismuth Engine", 1280, 720);
        window->Show();
    }

    SApplication* Get() {return SApplication::GlobalApplication;}

    bool ShouldQuit() const {
        return window->ShouldClose();
    }

    void Tick() {
        window->Tick();
    }
};

SApplication* SApplication::GlobalApplication = nullptr;