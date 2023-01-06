
module.exports = class FiberModule {
    constructor(target) {
        this.Name = "Fiber";
        this.Imports = ["Sodium"];
        this.Exports = [];
        // Fiber is not intended for in-editor use, no need in reflecion
        this.useBMT = false;
    }
};