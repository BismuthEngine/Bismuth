
module.exports = class SodiumVulkanModule {
    constructor(target) {
        this.Name = "SodiumVulkan";
        this.Imports = ["SodiumAPI", "Vulkan", "Log"];
        this.Exports = [];
        // Sodium is not intended for in-editor use, no need in reflecion
        this.useBMT = false;

        if(target.platform != "Win32") {
            this.Exclude.push("win32");
        }
    }
};