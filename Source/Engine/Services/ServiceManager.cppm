export module Services:ServiceManager;

export
class SServiceManager {
    static SServiceManager singleton;
public:
    const SServiceManager& Get() {return singleton;}
};