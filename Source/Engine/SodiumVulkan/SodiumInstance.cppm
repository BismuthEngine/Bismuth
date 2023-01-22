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

    bool isDeviceSuitable(vk::PhysicalDevice) {
        return true;
    }
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
        appinfo.apiVersion = vk::API_VERSION_1_2;

        // TODO Dynamic arrays, isolate win32
        const char* extensions[] = {"VK_KHR_surface", "VK_KHR_win32_surface"};
        const char* validationLayers[] = {"VK_LAYER_KHRONOS_validation"};

        vk::InstanceCreateInfo cinfo = {};
        cinfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        cinfo.pApplicationInfo = &appinfo;
        cinfo.enabledLayerCount = static_cast<unsigned int>(1);
        cinfo.ppEnabledLayerNames = validationLayers;
        cinfo.enabledExtensionCount = static_cast<unsigned int>(2);
        cinfo.ppEnabledExtensionNames = extensions;

        if(vk::vkCreateInstance(&cinfo, nullptr, &instance) != VK_SUCCESS) {
            Logger::CriticalError("[Sodium][Vulkan] Was not able to create Instance!");
        }

        Logger::Log("[Sodium][Vulkan] Instance created!");
    }

    virtual ISodiumPhysicalDevice* CreatePhysicalDevice() override {
        unsigned int deviceCount = 0;
        vk::vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

        if(deviceCount == 0) {
            Logger::CriticalError("[Sodium][Vulkan] No physical devices detected!");
        }

        vk::PhysicalDevice* devices = new vk::PhysicalDevice[deviceCount];
        vk::vkEnumeratePhysicalDevices(instance, &deviceCount, devices);

        for (int i = 0; i < deviceCount; i++) {
            if (isDeviceSuitable(devices[i])) {
                return new VkSodiumPhysicalDevice(devices[i]);
                break;
            }
        }
        
        return nullptr;
    }

    virtual ISodiumSurface* CreateSurface(SodiumSurfaceCreateInfo info) override {
        vk::SurfaceKHR surface;
        if(info.surfaceType == ESurfaceType::Win32) {
            #ifdef _WIN32
                vk::Win32SurfaceCreateInfoKHR cinfo;
                cinfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
                cinfo.pNext = nullptr;
                cinfo.flags = 0;
                cinfo.hwnd = ExtractHWND(info.pHandle);
                cinfo.hinstance = GetThisModuleInstance();
                
                if(vk::vkCreateWin32SurfaceKHR(instance, &cinfo, nullptr, &surface) != VK_SUCCESS) {
                    Logger::CriticalError("[Sodium][Vulkan] vkCreateWin32SurfaceKHR was not loaded!");
                    return nullptr;
                }

                Logger::Log("[Sodium][Vulkan] Created vkCreateWin32SurfaceKHR!");

                return new VkSodiumSurface(surface);
            #endif
        }
        return nullptr;
    }
};