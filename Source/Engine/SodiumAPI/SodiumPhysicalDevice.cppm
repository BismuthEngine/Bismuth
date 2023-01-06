export module SodiumAPI:SodiumPhysicalDevice;

export import :SodiumDevice;

export struct SodiumPhysicalDeviceCreationInfo {

};

export class ISodiumPhysicalDevice {
public:
    virtual ISodiumDevice* CreateDevice() {}
};