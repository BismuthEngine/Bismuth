
module.exports = class CoreModule {
    constructor(rules) {
        this.Name = "Core";
        this.Imports = ["Engine", "Services"];
        this.Exports = [];

        this.Module = false;
    }
};