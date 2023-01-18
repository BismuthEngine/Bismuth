export module Object:NObject;

export import :ObjectBase;
export import :Reflector;

export import :Concepts;

export class NObject : public ObjectBase { 
protected:
    NObject* Parent;
    
public:
    static inline SString className = "Object";
    static const ObjectBase* prototype;
public:

    // Returns firsst parent object of type (NObject by default)
    template <BismuthObject ObjectType = NObject>
    ObjectType* GetParentObject() {return nullptr;}
};

// Register NObject to ObjectFactory
const ObjectBase* NObject::prototype = DefferedBismuthStaticObjectRegister<NObject>();

// Utilities

export
template <BismuthObject To, BismuthObject From>
To* Cast(From* object) {
    return dynamic_cast<To>(object);
}