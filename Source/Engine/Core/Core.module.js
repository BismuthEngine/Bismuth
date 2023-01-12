
module.exports = class CoreModule {
    constructor(rules) {
        this.Name = "Core";
        this.Imports = ["Application", "Engine", "Services", "Log"];
        this.Exports = [];

        this.Module = false;
    }
};