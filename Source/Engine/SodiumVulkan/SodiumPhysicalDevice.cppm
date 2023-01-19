export module SodiumVulkan:SodiumPhysicalDevice;

import SodiumAPI;
import :vulka;

export class VkSodiumPhysicalDevice : public ISodiumPhysicalDevice {
public:
    VkSodiumPhysicalDevice(vk::PhysicalDevice dev) {

    }

    virtual ISodiumDevice* CreateDevice(SodiumDeviceCreationInfo info) override {
        return nullptr;
    }
};