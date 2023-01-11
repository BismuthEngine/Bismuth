
module.exports = class PlatformModule {
    constructor(target) {
        this.Name = "Platform";
        this.Imports = [];
        this.Exports = [];
        // Platform is BMT functionality provider
        this.useBMT = false;
    }
};