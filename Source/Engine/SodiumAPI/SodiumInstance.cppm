export module SodiumAPI:SodiumInstance;

export import :SodiumPhysicalDevice;
export import :SodiumSurface;

export struct SodiumInstanceCreationInfo {

};

export class ISodiumInstance {
public:
    virtual ISodiumPhysicalDevice* CreatePhysicalDevice() {return nullptr;}
    virtual ISodiumSurface* CreateSurface(SodiumSurfaceCreateInfo info) {return nullptr;}
};