export module Services:ServiceManager;

export import :Service;
import Types;

export
class SServiceManager {
    static SServiceManager singleton;
    TArray<SService> services;
public:

    static SServiceManager& Get() {
        return singleton;
    }

    template <BismuthService T>
    bool Register() {
        services.Add(T());
        return true;
    }

    template <BismuthService T>
    bool Unregister() {
        return false;
    }
};

SServiceManager SServiceManager::singleton = SServiceManager();

export 
template <BismuthService ServiceType>
ServiceType* Service() {
    return nullptr;
}