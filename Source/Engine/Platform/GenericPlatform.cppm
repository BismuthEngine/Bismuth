export module Platform:GenericPlatform;

export class IGenericPlatform {
    static IGenericPlatform& singleton;

    friend class SApplication;
public:
    static IGenericPlatform& Get() {return IGenericPlatform::singleton;}

};