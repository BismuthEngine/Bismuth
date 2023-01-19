export module SodiumAPI:SodiumInstance;

export import :SodiumPhysicalDevice;
export import :SodiumSurface;

export struct SodiumInstanceCreationInfo {
    const char*        pApplicationName;
    unsigned int       applicationVersion;
    const char*        pEngineName;
    unsigned int       engineVersion;
};

export class ISodiumInstance {
public:
    virtual ISodiumPhysicalDevice* CreatePhysicalDevice() {return nullptr;}
    virtual ISodiumSurface* CreateSurface(SodiumSurfaceCreateInfo info) {return nullptr;}
};