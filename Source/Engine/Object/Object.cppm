export module Object;

//import Module;
import Services;

export import :NObject;
export import :Library;

/*export class ObjectModuleEntry : public ModuleEntry {
public:
    static inline SString moduleName = "ObjectModule";
    static const bool bRegistered;

    virtual void Initialize() override 
    {
        SServiceManager::Get().Register<SAssetManager>();
    }

    virtual void Deinitialize() override 
    {

    }
};*/

//const bool ObjectModuleEntry::bRegistered = DefferedBismuthModuleRegister<ObjectModuleEntry>();