export module SodiumVulkan:SodiumInstance;

import :vulka;
import SodiumAPI;
import Log;

import :SodiumSurface;

#ifdef _WIN32
import :win32;
#endif

export class VkSodiumInstance : public ISodiumInstance {
    vk::Instance instance;
public:
    VkSodiumInstance(SodiumInstanceCreationInfo createInfo) {
        if(vk::InitializeLoader() != vk::Result::VK_SUCCESS) {
            Logger::CriticalError("[Sodium][Vulkan] Failed Initialization!");
        }

        Logger::Log("[Sodium][Vulkan] Vulkan Initialized!");
    }

    //virtual ISodiumPhysicalDevice* CreatePhysicalDevice() {return nullptr;}
    virtual ISodiumSurface* CreateSurface(SodiumSurfaceCreateInfo info) override {
        vk::SurfaceKHR surface;
        if(info.surfaceType == ESurfaceType::Win32) {
            #ifdef _WIN32
                vk::Win32SurfaceCreateInfoKHR cinfo;
                cinfo.sType = vk::StructureType::VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
                cinfo.pNext = nullptr;
                //cinfo.hwnd = ExtractHWND(info.pHandle);
                //cinfo.hinstance = GetWindowInstance(info.pHandle);

                //vk::vkCreateWin32SurfaceKHR(instance, &cinfo, nullptr, &surface);

                return new VkSodiumSurface(surface);
            #else
                return nullptr;
            #endif
        }
        return nullptr;
    }
};