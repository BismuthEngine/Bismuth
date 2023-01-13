export module Object:Reflector;

import :Concepts;
import :ObjectBase;

export import Types;

export
struct BismuthStaticObjectFactory {
        static TMap<SString, ObjectBase*>& GetRegistry() {
                static TMap<SString, ObjectBase*> registry;
                return registry;
        }

        template <BismuthObject ObjectType>
        static ObjectBase* CreateStaticObjectProrotype() {
                ObjectType* PartiallyInitializedObject = new ObjectType();
                // Partially Initialize Base Object
                return PartiallyInitializedObject;
        }
};

export
template <BismuthObject ObjectType>
ObjectBase* DefferedBismuthStaticObjectRegister() {
        auto& registry = BismuthStaticObjectFactory::GetRegistry();
        auto SOP = BismuthStaticObjectFactory::CreateStaticObjectProrotype<ObjectType>();
        registry.Set(ObjectType::className, SOP);
        return SOP;
};