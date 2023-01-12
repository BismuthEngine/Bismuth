export module Services:ServiceManager;

export import :Service;

export
class SServiceManager {
    static SServiceManager singleton;
public:
    const SServiceManager& Get() {return singleton;}
};

export 
template <BismuthService ServiceType>
ServiceType* Service() {
    return nullptr;
}