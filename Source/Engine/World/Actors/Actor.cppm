export module World:Actor;

import Object;

export class NActor : public NObject {
    static inline SString className = "Actor";
    static const ObjectBase* prototype;
};

// Register NActor to ObjectFactory
//const ObjectBase* NActor::prototype = DefferedBismuthStaticObjectRegister<NActor>();