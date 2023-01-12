export module Sodium:SodiumRenderer;

import :Loader;

export class SodiumRenderer {
protected:
    ISodiumInstance* instance;
    ISodiumSurface* surface;
public:
    SodiumRenderer() {
        SodiumInstanceCreationInfo info;
 
        instance = Sodium::CreateInstance(info);
    }

    void InitializeWithSurface(ESurfaceType type, void* handle) {
        SodiumSurfaceCreateInfo info;
        info.surfaceType = type;
        info.pHandle = handle;
        
        surface = instance->CreateSurface(info);
    }
};