
module.exports = class LogModule {
    constructor(target) {
        this.Name = "Log";
        this.Imports = ["Types", "Services"];
        this.Exports = [];
        this.Exclude = [];
        // Logger is not intended for in-editor use, no need in reflecion
        this.useBMT = false;
    }
};