export module World:Level;

import Object;

export import :Actor;

export class NLevel : public NObject {
    static inline SString className = "Level";
    static const ObjectBase* prototype;
};

// Register NActor to ObjectFactory
//const ObjectBase* NLevel::prototype = DefferedBismuthStaticObjectRegister<NLevel>();