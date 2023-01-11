
module.exports = class TypesModule {
    constructor(target) {
        this.Name = "Types";
        this.Imports = [];
        this.Exports = [];
        // This is BMT functionality provider, we can't address it to BMT
        this.useBMT = false;
    }
};