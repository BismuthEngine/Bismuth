export module Engine;

import Log;

export class SEngine {
public:
    static SEngine* GlobalEngine;

    SEngine() {
        if(SEngine::GlobalEngine) {
            // Error
        }

        SEngine::GlobalEngine = this;
        
        Logger::Log("Global Engine initialized");
    }
};

SEngine* SEngine::GlobalEngine = nullptr;