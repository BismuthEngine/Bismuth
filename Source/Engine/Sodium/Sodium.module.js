
module.exports = class SodiumModule {
    constructor(target) {
        this.Name = "Sodium";
        this.Imports = ["SodiumAPI", "SodiumVulkan", "Log"];
        this.Exports = [];
        // Sodium is not intended for in-editor use, no need in reflecion
        this.useBMT = false;

        if (target.platform == "Win32") {
            //this.Imports.push("SodiumD3D12");
        }
    }
};