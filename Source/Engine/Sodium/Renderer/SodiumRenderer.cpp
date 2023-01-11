module Sodium:SodiumRenderer;

import :Loader;

SodiumRenderer::SodiumRenderer() 
{
    SodiumInstanceCreationInfo info;
 
    instance = Sodium::CreateInstance(info);
}

void SodiumRenderer::InitializeWithSurface(ESurfaceType type, void* handle) 
{
    SodiumSurfaceCreateInfo info;
    info.surfaceType = type;
    info.pHandle = handle;
    
    surface = instance->CreateSurface(info);
}