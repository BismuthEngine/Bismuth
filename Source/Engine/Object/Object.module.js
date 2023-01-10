
module.exports = class ObjectModule {
    constructor(target) {
        this.Name = "Object";
        this.Imports = ["Package"];
        this.Exports = [];
        // This is BMT functionality provider, we can't address it to BMT
        this.useBMT = false;
    }
};