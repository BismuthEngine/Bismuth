export module Application;

import Engine;

export class Application {
protected:
    static Application* GlobalApplication;
public:
    Application* Get() {return Application::GlobalApplication;}
};