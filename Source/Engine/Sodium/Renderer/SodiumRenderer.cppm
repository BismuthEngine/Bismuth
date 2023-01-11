export module Sodium:SodiumRenderer;

import :Loader;

export class SodiumRenderer {
protected:
    ISodiumInstance* instance;
    ISodiumSurface* surface;
public:
    SodiumRenderer();

    void InitializeWithSurface(ESurfaceType type, void* handle);
};