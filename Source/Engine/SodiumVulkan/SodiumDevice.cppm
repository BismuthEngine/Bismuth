export module SodiumVulkan:SodiumDevice;

import SodiumAPI;
import :vulka;

export class VkSodiumDevice : public ISodiumDevice {
    vk::Device device;
public:

    VkSodiumDevice(vk::Device dev) {

    }

    virtual bool IsValid() const override {
        return true;
    }

    virtual ISodiumShaderModule* CreateShaderModule(SodiumShaderModuleCreateInfo info) override {return nullptr;}
    virtual ISodiumBuffer* CreateBuffer(SodiumBufferCreateInfo info) override {return nullptr;}
    virtual ISodiumPipeline* CreatePipeline(SodiumPipelineCreateInfo info) override {return nullptr;}

    virtual ISodiumCmdPool* CreateCommandPool(SodiumCmdPoolCreateInfo info) override {return nullptr;}
    virtual ISodiumCmdBuffer* CreateCommandBuffer(SodiumCmdBufferCreateInfo info) override {return nullptr;}

    virtual ISodiumDeviceMemory* AllocateMemory(SodiumMemoryAllocateInfo info) override {return nullptr;}
    virtual ISodiumMemoryRequirements* GetImageMemoryRequirements(ISodiumImage* image) override {return nullptr;}
};