export module SodiumVulkan:SodiumPhysicalDevice;

import SodiumAPI;
import :vulka;

import :SodiumDevice;

export class VkSodiumPhysicalDevice : public ISodiumPhysicalDevice {
protected:
    vk::PhysicalDevice device;
public:
    VkSodiumPhysicalDevice(vk::PhysicalDevice dev) 
        : device(dev)
    {}

    virtual ISodiumDevice* CreateDevice(SodiumDeviceCreationInfo info) override {
        vk::Device device;

        return new VkSodiumDevice(device);
    }
};