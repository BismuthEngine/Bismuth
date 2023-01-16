
module.exports = class ApplicationModule {
    constructor(rules) {
        this.Name = "Application";
        this.Imports = ["Engine", "Fiber"];
        this.Exports = [];

        this.Module = true;
    }
};