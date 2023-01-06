
module.exports = class SodiumVulkanModule {
    constructor(target) {
        this.Name = "SodiumVulkan";
        this.Imports = ["SodiumAPI", "Vulkan"];
        this.Exports = [];
        // Sodium is not intended for in-editor use, no need in reflecion
        this.useBMT = false;
    }
};