export module SodiumVulkan:SodiumDevice;

import SodiumAPI;
import :vulka;
import :SodiumSurface;
import :SodiumSwapchain;
import Log;

export class VkSodiumDevice : public ISodiumDevice {
    vk::Device device;
public:

    VkSodiumDevice(vk::Device dev) {
        device = dev;
    }

    virtual bool IsValid() const override {
        return device != nullptr;
    }

    virtual ISodiumShaderModule* CreateShaderModule(SodiumShaderModuleCreateInfo info) override {return nullptr;}
    virtual ISodiumBuffer* CreateBuffer(SodiumBufferCreateInfo info) override {return nullptr;}
    virtual ISodiumPipeline* CreatePipeline(SodiumPipelineCreateInfo info) override {return nullptr;}

    virtual ISodiumCmdPool* CreateCommandPool(SodiumCmdPoolCreateInfo info) override {return nullptr;}
    virtual ISodiumCmdBuffer* CreateCommandBuffer(SodiumCmdBufferCreateInfo info) override {return nullptr;}

    virtual ISodiumDeviceMemory* AllocateMemory(SodiumMemoryAllocateInfo info) override {return nullptr;}
    virtual ISodiumMemoryRequirements* GetImageMemoryRequirements(ISodiumImage* image) override {return nullptr;}

    virtual ISodiumSwapchain* CreateSwapchain(SodiumSwapchainCreateInfo info) override {
        VkSodiumSurface* surface = dynamic_cast<VkSodiumSurface*>(info.surface);
        if(surface == nullptr) {
            Logger::CriticalError("[SODIUM][Vulkan] Surface must be specified when creating Swapchain");
        }
        vk::SwapchainKHR swapchain;

        vk::Extent2D extent = {info.width, info.height};

        vk::SwapchainCreateInfoKHR createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
        createInfo.surface = surface->GetSurfaceKHR();
        createInfo.minImageCount = info.minImageCount;
        //createInfo.imageFormat = info.format;
        //createInfo.imageColorSpace = info.colorSpace;
        createInfo.imageExtent = extent;
        createInfo.imageArrayLayers = info.imageArrayLayers;
        createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;

        return new VkSodiumSwapchain(swapchain);
    }
};