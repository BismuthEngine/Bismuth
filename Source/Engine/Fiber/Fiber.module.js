
module.exports = class FiberModule {
    constructor(target) {
        this.Name = "Fiber";
        this.Imports = ["Sodium", "Log"];
        this.Exports = [];
        this.Exclude = [];
        // Fiber is not intended for in-editor use, no need in reflecion
        this.useBMT = false;

        if(target.platform != "Win32") {
            this.Exclude.push("Win32FiberWindow");
        }
        if(target.platform != "Unix") {
            this.Exclude.push("X11FiberWindow");
            this.Exclude.push("WaylandFiberWindow");
        }
        if(target.platform != "Mach") {
            this.Exclude.push("AppkitFiberWindow");
        }
    }
};