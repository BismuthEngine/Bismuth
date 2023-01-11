module;

#include <map>
#include <string>

export module Object:Reflector;

import :Concepts;
import :ObjectBase;

class NObject;

export
struct BismuthStaticObjectFactory {
        static std::map<std::string, ObjectBase*>& GetRegistry() {
                static std::map<std::string, ObjectBase*> registry;
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
struct BismuthStaticObjectState {
	static inline bool bRegistered;
};

export
template <BismuthObject ObjectType>
bool DefferedBismuthStaticObjectRegister() {
        auto& registry = BismuthStaticObjectFactory::GetRegistry();
        registry[ObjectType::className] = BismuthStaticObjectFactory::CreateStaticObjectProrotype<ObjectType>();
        return true;
};