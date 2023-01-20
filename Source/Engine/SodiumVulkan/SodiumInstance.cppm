export module SodiumVulkan:SodiumInstance;

import :vulka;
import SodiumAPI;
import Log;

import :SodiumSurface;
import :SodiumPhysicalDevice;

#ifdef _WIN32
import :win32;
#endif

export class VkSodiumInstance : public ISodiumInstance {
protected:
    vk::Instance instance;
public:
    virtual bool IsValid() const override {return instance != nullptr;}

    VkSodiumInstance(SodiumInstanceCreationInfo createInfo) {
        if(vk::InitializeLoader() != VK_SUCCESS) {
            Logger::CriticalError("[Sodium][Vulkan] Failed Initialization!");
        }

        Logger::Log("[Sodium][Vulkan] Vulkan Initialized!");

        vk::ApplicationInfo appinfo = {};
        appinfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appinfo.pApplicationName = createInfo.pApplicationName;
        appinfo.applicationVersion = vk::MAKE_API_VERSION(createInfo.vMajor, createInfo.vMinor, createInfo.vPatch);
        appinfo.pEngineName = createInfo.pEngineName;
        appinfo.engineVersion = vk::MAKE_API_VERSION(createInfo.vMajor, createInfo.vMinor, createInfo.vPatch);
        appinfo.apiVersion = vk::API_VERSION_1_0;

        vk::InstanceCreateInfo cinfo = {};
        cinfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        cinfo.pApplicationInfo = &appinfo;
        cinfo.enabledLayerCount = 0;
        cinfo.enabledExtensionCount = 0;

        if(vk::vkCreateInstance(&cinfo, nullptr, &instance) != VK_SUCCESS) {
            Logger::CriticalError("[Sodium][Vulkan] Was not able to create Instance!");
        }

        Logger::Log("[Sodium][Vulkan] Instance created!");
    }

    virtual ISodiumPhysicalDevice* CreatePhysicalDevice() override {
        vk::PhysicalDevice device;
        
        return new VkSodiumPhysicalDevice(device);
    }

    virtual ISodiumSurface* CreateSurface(SodiumSurfaceCreateInfo info) override {
        vk::SurfaceKHR surface;
        if(info.surfaceType == ESurfaceType::Win32) {
            #ifdef _WIN32
                vk::Win32SurfaceCreateInfoKHR cinfo;
                cinfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
                cinfo.hwnd = ExtractHWND(info.pHandle);
                cinfo.hinstance = GetWindowInstance(info.pHandle);
                
                /*if(vk::vkCreateWin32SurfaceKHR(instance, &cinfo, nullptr, &surface) != VK_SUCCESS) {
                    Logger::CriticalError("[Sodium][Vulkan] vkCreateWin32SurfaceKHR was not loaded!");
                    return nullptr;
                }*/

                Logger::Log("[Sodium][Vulkan] Created vkCreateWin32SurfaceKHR!");

                return new VkSodiumSurface(surface);
            #endif
        }
        return nullptr;
    }
};