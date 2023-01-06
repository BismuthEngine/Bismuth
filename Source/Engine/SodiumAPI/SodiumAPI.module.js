
module.exports = class SodiumAPIModule {
    constructor(target) {
        this.Name = "SodiumAPI";
        this.Imports = [];
        this.Exports = [];
        // Sodium is not intended for in-editor use, no need in reflecion
        this.useBMT = false;
    }
};