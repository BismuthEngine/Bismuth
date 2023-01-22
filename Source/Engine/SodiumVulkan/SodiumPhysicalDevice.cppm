export module SodiumVulkan:SodiumPhysicalDevice;

import SodiumAPI;
import :vulka;

import Log;

import :SodiumDevice;

export class VkSodiumPhysicalDevice : public ISodiumPhysicalDevice {
protected:
    vk::PhysicalDevice device;
public:
    VkSodiumPhysicalDevice(vk::PhysicalDevice dev) 
        : device(dev)
    {}

    virtual bool IsValid() const override {
        return device != nullptr;
    }


    static unsigned int findQueueFamilies(vk::PhysicalDevice dev) {
        unsigned int index;

        unsigned int queueFamilyCount = 0;
        vk::vkGetPhysicalDeviceQueueFamilyProperties(dev, &queueFamilyCount, nullptr);

        vk::QueueFamilyProperties queueFamilies[queueFamilyCount];
        vk::vkGetPhysicalDeviceQueueFamilyProperties(dev, &queueFamilyCount, queueFamilies);
        
        for (int i = 0; i < queueFamilyCount; i++) {
            if (queueFamilies[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
                index = i;
                break;
            }
        }

        return index;
    }

    virtual ISodiumDevice* CreateDevice(SodiumDeviceCreationInfo info) override {
        vk::Device dev;

        unsigned int index = VkSodiumPhysicalDevice::findQueueFamilies(device);

        vk::DeviceQueueCreateInfo queueCreateInfo{};
        queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo.pNext = nullptr;
        queueCreateInfo.flags = 0;
        queueCreateInfo.queueFamilyIndex = index;
        queueCreateInfo.queueCount = 1;
        float queuePriority = 1.0f;
        queueCreateInfo.pQueuePriorities = &queuePriority;

        vk::PhysicalDeviceFeatures deviceFeatures{};
        vk::vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

        const char* extensions[] = {"VK_KHR_swapchain"};

        vk::DeviceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        createInfo.pNext = nullptr;
        createInfo.flags = 0;
        createInfo.pQueueCreateInfos = &queueCreateInfo;
        createInfo.queueCreateInfoCount = 1;
        createInfo.pEnabledFeatures = &deviceFeatures;
        createInfo.enabledExtensionCount = 1;
        createInfo.ppEnabledExtensionNames = extensions;
        createInfo.enabledLayerCount = 0;

        if (vk::vkCreateDevice(device, &createInfo, nullptr, &dev) != VK_SUCCESS) {
            Logger::CriticalError("[VULKAN] Failed to create device!");
        }

        return new VkSodiumDevice(dev);
    }
};