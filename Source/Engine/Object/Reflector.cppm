export module Object:Reflector;

export import :Concepts;
import :ObjectBase;

class NObject;

export
struct BismuthStaticObjectFactory {
        static std::map<std::string, NObject*>& GetRegistry() {
                static std::map<std::string, NObject*> registry;
                return registry;
        }

        template<BismuthProject ObjectType>
        static ObjectType* CreateStaticObjectProrotype() {
                ObjectType* PartiallyInitializedObject = new ObjectType();
                // Partially Initialize Base Object
                return PartiallyInitializedObject;
        }
}

export
template <BismuthObject ObjectType>
struct BismuthStaticObjectState {
	static inline const bool bRegistered;
};

export
template <BismuthObject ObjectType>
static inline bool DefferedBismuthStaticObjectRegister() {
        auto& registry = BismuthStaticObjectFactory::GetRegistry();
        registry[ObjectType::className] = BismuthStaticObjectFactory::CreateStaticObjectProrotype<ObjectType>();
        return true;
};