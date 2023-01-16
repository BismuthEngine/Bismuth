
module.exports = class ServicesModule {
    constructor(target) {
        this.Name = "Services";
        this.Imports = ["Types"];
        this.Exports = [];
        // This is system module, should never be exposed to editor
        this.useBMT = false;
    }
};