export module SodiumAPI:SodiumDevice;

export import :SodiumShaderModule;
export import :SodiumBuffer;
export import :SodiumPipeline;

export struct SodiumDeviceCreationInfo {

};

export class ISodiumDevice {
public:

    virtual ISodiumShaderModule* CreateShaderModule(SodiumShaderModuleCreateInfo info) {return nullptr;}
    virtual ISodiumBuffer* CreateBuffer(SodiumBufferCreateInfo info) {return nullptr;}
    virtual ISodiumPipeline* CreatePipeline(SodiumPipelineCreateInfo info) {return nullptr;}
};