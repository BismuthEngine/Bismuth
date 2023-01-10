export module Package:PackageService;

import Services;

export class NPackageService : public NService {
public:
    static std::string className = "PackageService";
};

// Register NPackageService to ObjectFactory
export
template<> 
const bool BismuthStaticObjectState<NPackageService>::bRegistered = DefferedBismuthStaticObjectRegister<NPackageService>();