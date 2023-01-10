export module Services:Service;

import Object;

export class NService : public NObject {
public:
    static std::string className = "Service";
};

// Register NService to ObjectFactory
export
template<> 
const bool BismuthStaticObjectState<NService>::bRegistered = DefferedBismuthStaticObjectRegister<NService>();