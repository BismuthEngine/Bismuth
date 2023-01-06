export module SodiumAPI:SodiumCmdBuffer;

export class ISodiumCmdBuffer {
protected:
    virtual void CmdBeginRenderPass() {}
    virtual void CmdEndRenderPass() {}

    virtual void CmdSetViewport() {}

    friend class SodiumRenderer;

public:

    virtual void CmdBindPipeline() {}

    virtual void CmdDraw() {}
    virtual void CmdDrawIndexed() {}
    virtual void CmdDrawIndexedIndirect() {}
};