
module.exports = class EngineModule {
    constructor(rules) {
        this.Name = "Engine";
        this.Imports = ["Sodium", "Mixture", "Delegate", "World", "Log"];
        this.Exports = [];
    }
};