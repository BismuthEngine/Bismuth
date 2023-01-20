export module SodiumAPI:SodiumPhysicalDevice;

export import :SodiumDevice;

export import :SodiumObject;

export struct SodiumPhysicalDeviceCreationInfo {

};

export class ISodiumPhysicalDevice : public ISodiumObject {
public:
    virtual ISodiumDevice* CreateDevice(SodiumDeviceCreationInfo info) {return nullptr;}
};