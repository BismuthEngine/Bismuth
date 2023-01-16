export module Platform:GenericPlatform;

export class IGenericPlatform {
    static IGenericPlatform& singleton;

    friend class SApplication;
public:
    IGenericPlatform() {}
    static IGenericPlatform& Get() {return IGenericPlatform::singleton;}

};