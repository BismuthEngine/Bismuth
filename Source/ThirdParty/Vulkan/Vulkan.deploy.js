

export default class VulkanDeploy {
    constructor(Target) {
        this.Path = Target.EnvArgs.VULKAN_SDK;

        this.License = "Vulkan.license";
        this.Includes = ["./Deploy/Vulkan/include"];
        this.StaticLibs = ["./Deploy/Vulkan/libs"];

        // -lvulkan
        this.LinkerOptions = ["vulkan"];
    }

    Deploy() {

    }
};