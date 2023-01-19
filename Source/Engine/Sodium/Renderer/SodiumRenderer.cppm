export module Sodium:SodiumRenderer;

import :Loader;

import Log;

export class SodiumRenderer {
protected:
    ISodiumInstance* instance;
    ISodiumPhysicalDevice* physicalDevice;
    ISodiumDevice* device;
    ISodiumSurface* surface;
public:
    SodiumRenderer() {
        SodiumInstanceCreationInfo instanceInfo;
        instanceInfo.pApplicationName = "Bismuth";
        instanceInfo.pEngineName = "Bismuth";
        instanceInfo.vMajor = 0;
        instanceInfo.vMinor = 0;
        instanceInfo.vPatch = 1;
 
        instance = Sodium::CreateInstance(instanceInfo);
        if(!instance) {
            Logger::CriticalError("[SODIUM]: Was not able to create instance");
        }
        
        physicalDevice = instance->CreatePhysicalDevice();
        if(!physicalDevice) {
            Logger::CriticalError("[SODIUM]: Was not able to pick physical device");
        }

        SodiumDeviceCreationInfo deviceInfo;

        device = physicalDevice->CreateDevice(deviceInfo);
        if(!device) {
            Logger::CriticalError("[SODIUM]: Was not able to create device");
        }
    }

    void InitializeWithSurface(ESurfaceType type, void* handle) {
        SodiumSurfaceCreateInfo info;
        info.surfaceType = type;
        info.pHandle = handle;
        
        surface = instance->CreateSurface(info);
    }
};