export module Sodium:SodiumRenderer;

import :Loader;

import Log;

export class SodiumRenderer {
protected:
    ISodiumInstance* instance;
    ISodiumSurface* surface;
public:
    SodiumRenderer() {
        SodiumInstanceCreationInfo info;
 
        instance = Sodium::CreateInstance(info);

        if(!instance) {
            Logger::CriticalError("[SODIUM]: Was not able to create instance");
        }
    }

    void InitializeWithSurface(ESurfaceType type, void* handle) {
        SodiumSurfaceCreateInfo info;
        info.surfaceType = type;
        info.pHandle = handle;
        
        surface = instance->CreateSurface(info);
    }
};