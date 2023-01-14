
module.exports = class ModuleModule {
    constructor(target) {
        this.Name = "Module";
        this.Imports = ["Types"];
        this.Exports = [];
        // This is BMT functionality provider, we can't address it to BMT
        this.useBMT = false;
    }
};