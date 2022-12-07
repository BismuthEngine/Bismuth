
export default class SodiumVulkanModule {
    constructor(target) {
        this.Name = "SodiumVulkan";
        this.Imports = ["Vulkan"];
        this.Exports = [];
        // Sodium is not intended for in-editor use, no need in reflecion
        this.useBMT = false;
    }
};