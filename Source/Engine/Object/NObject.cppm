export module Object:NObject;

export import :ObjectBase;
import :Reflector;

export class NObject : public ObjectBase { 
public:
    static std::string className = "Object";

};

// Register NObject to ObjectFactory
export
template<> 
const bool BismuthStaticObjectState<NObject>::bRegistered = DefferedBismuthStaticObjectRegister<NObject>();