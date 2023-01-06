
module.exports = class CoreModule {
    constructor(rules) {
        this.Name = "Core";
        this.Imports = ["Engine"];
        this.Exports = [];

        this.Module = false;
    }
};