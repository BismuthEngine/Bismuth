
module.exports = class ApplicationModule {
    constructor(rules) {
        this.Name = "Application";
        this.Imports = ["Engine", "Services", "Log"];
        this.Exports = [];

        this.Module = false;
    }
};