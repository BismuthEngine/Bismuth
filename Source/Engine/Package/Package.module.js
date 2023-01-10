
module.exports = class PackageModule {
    constructor(target) {
        this.Name = "Package";
        this.Imports = ["Services"];
        this.Exports = [];
        // This is system module, should never be exposed to editor
        this.useBMT = false;
    }
};