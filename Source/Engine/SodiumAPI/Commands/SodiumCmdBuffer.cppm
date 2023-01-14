export module SodiumAPI:SodiumCmdBuffer;

export struct SodiumCmdBufferCreateInfo {

};

export struct SodiumCmdBuffeBeginInfo {

};

export struct SodiumCmdBuffeEndInfo {

};


export class ISodiumCmdBuffer {
protected:
    virtual void CmdSetViewport() {}

    virtual void BeginCommandBuffer() {}
    virtual void EndCommandBuffer() {}
    virtual void ResetCommandBuffer() {}

    friend class SodiumRenderer;

public:

    virtual void CmdBeginRenderPass() {}
    virtual void CmdEndRenderPass() {}

    virtual void CmdBindPipeline() {}

    virtual void CmdDraw() {}
    virtual void CmdDrawIndexed() {}
    virtual void CmdDrawIndexedIndirect() {}
};