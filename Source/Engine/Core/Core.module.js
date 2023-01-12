
module.exports = class CoreModule {
    constructor(rules) {
        this.Name = "Core";
        this.Imports = ["Engine", "Services", "Log"];
        this.Exports = [];

        this.Module = false;
    }
};