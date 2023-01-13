export module World:WorldObject;

export import :Level;

import Object;

export class NWorld : public NObject {
    static inline SString className = "World";
    static const ObjectBase* prototype;
};

// Register NActor to ObjectFactory
const ObjectBase* NWorld::prototype = DefferedBismuthStaticObjectRegister<NWorld>();