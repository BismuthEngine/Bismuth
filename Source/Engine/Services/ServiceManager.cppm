export module Services:ServiceManager;

export import :Service;

export
class SServiceManager {
    static const SServiceManager& singleton;
public:
    static const SServiceManager& Get() {return singleton;}
};

const SServiceManager& SServiceManager::singleton = SServiceManager();

export 
template <BismuthService ServiceType>
ServiceType* Service() {
    return nullptr;
}