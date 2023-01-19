export module SodiumAPI:SodiumDevice;

export import :SodiumShaderModule;
export import :SodiumBuffer;
export import :SodiumPipeline;
export import :SodiumCmdPool;
export import :SodiumDeviceMemory;
export import :SodiumMemoryRequirements;
export import :SodiumImage;
export import :SodiumCmdBuffer;
export import :SodiumDeviceMemory;
export import :SodiumSurface;

export struct SodiumDeviceCreationInfo {

};

export class ISodiumDevice {
public:

    virtual ISodiumShaderModule* CreateShaderModule(SodiumShaderModuleCreateInfo info) {return nullptr;}
    virtual ISodiumBuffer* CreateBuffer(SodiumBufferCreateInfo info) {return nullptr;}
    virtual ISodiumPipeline* CreatePipeline(SodiumPipelineCreateInfo info) {return nullptr;}

    virtual ISodiumCmdPool* CreateCommandPool(SodiumCmdPoolCreateInfo info) {return nullptr;}
    virtual ISodiumCmdBuffer* CreateCommandBuffer(SodiumCmdBufferCreateInfo info) {return nullptr;}

    virtual ISodiumDeviceMemory* AllocateMemory(SodiumMemoryAllocateInfo info) {return nullptr;}
    virtual ISodiumMemoryRequirements* GetImageMemoryRequirements(ISodiumImage* image) {return nullptr;}
};