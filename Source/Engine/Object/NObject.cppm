export module Object:NObject;

export import :ObjectBase;
export import :Reflector;

export import :Concepts;

export class NObject : public ObjectBase { 
public:
    static inline SString className = "Object";
    static const ObjectBase* prototype;
public:

    template <BismuthObject ObjectType>
    ObjectType* GetParentObject() {return nullptr;}
};

// Register NObject to ObjectFactory
const ObjectBase* NObject::prototype = DefferedBismuthStaticObjectRegister<NObject>();