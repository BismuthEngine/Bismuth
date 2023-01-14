export module Module:ModuleEntry;

import Types;

export class ModuleEntry {
public:
    static inline SString moduleName = "ModuleEntry";
    static const bool bRegistered;

    TArray<SString> Dependencies;

    virtual void Initialize() {}
    virtual void Deinitialize() {}
};

const bool ModuleEntry::bRegistered = false;