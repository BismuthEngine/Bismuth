const path = require("path");

module.exports = class VulkanDeploy {
    constructor(Target) {
		this.Name = "Vulkan";
        this.Path = Target.EnvArgs.VULKAN_SDK;

        this.License = "Vulkan.license";
        if (this.Path != undefined) {
            this.Includes = [path.join(this.Path, "./Include")];

            /*if (Target.arch == "x86_32") {
                this.StaticLibs = [path.join(this.Path, "./Lib32/vulkan-1.lib")];
            } else if (Target.arch == "x86_64") {
                this.StaticLibs = [path.join(this.Path, "./Lib/vulkan-1.lib")];
            }*/

            // -lvulkan
            this.LinkerOptions = ["vulkan"];
        }
    }

    Deploy(api) {
		/*if(this.Path == undefined) {
			console.log(api.Color().yellowBright.bold("[VULKAN] Can't find Vulkan SDK on your PC, downloading Vulkan-Headers"));	
        }*/
        console.log(api.Color().yellowBright.bold("[VULKAN] Downloading Vulkan-Headers")); 
        //api.GitClone(`https://github.com/KhronosGroup/Vulkan-Headers`);
    }
};