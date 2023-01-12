export module Object:NObject;

export import :ObjectBase;
import :Reflector;

import Types;

export class NObject : public ObjectBase { 
public:
    static inline SString className = "Object";
    static const ObjectBase* prototype;
public:

};

// Register NObject to ObjectFactory
const ObjectBase* NObject::prototype = DefferedBismuthStaticObjectRegister<NObject>();