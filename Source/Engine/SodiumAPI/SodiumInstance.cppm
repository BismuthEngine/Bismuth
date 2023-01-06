export module SodiumAPI:SodiumInstance;

export import :SodiumPhysicalDevice;

export struct SodiumInstanceCreationInfo {

};

export class ISodiumInstance {
public:
    virtual ISodiumPhysicalDevice* CreatePhysicalDevice() {}
};