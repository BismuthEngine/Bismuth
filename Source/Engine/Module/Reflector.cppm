export module Module:Reflector;

import :ModuleEntry;

export import Types;

export
struct BismuthModuleFactory {
        static TMap<SString, ModuleEntry*>& GetRegistry() {
                static TMap<SString, ModuleEntry*> registry;
                return registry;
        }
};

export
template <class ObjectType>
bool DefferedBismuthModuleRegister() {
        BismuthModuleFactory::GetRegistry().Set(ObjectType::moduleName, new ObjectType());
        return true;
};