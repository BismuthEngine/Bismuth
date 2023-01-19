export module SodiumAPI:SodiumInstance;

export import :SodiumPhysicalDevice;
export import :SodiumSurface;

export struct SodiumInstanceCreationInfo {
    const char*        pApplicationName;
    const char*        pEngineName;
    unsigned int       vMajor;
    unsigned int       vMinor;
    unsigned int       vPatch;
};

export class ISodiumInstance {
public:
    virtual ISodiumPhysicalDevice* CreatePhysicalDevice() {return nullptr;}
    virtual ISodiumSurface* CreateSurface(SodiumSurfaceCreateInfo info) {return nullptr;}
};