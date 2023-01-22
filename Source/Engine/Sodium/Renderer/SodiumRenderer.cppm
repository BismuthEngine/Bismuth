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
        if(!instance || !instance->IsValid()) {
            Logger::CriticalError("[SODIUM]: Was not able to create instance");
        }
        
        physicalDevice = instance->CreatePhysicalDevice();
        if(!physicalDevice || !physicalDevice->IsValid()) {
            Logger::CriticalError("[SODIUM]: Was not able to pick physical device");
        }

        Logger::Log("[SODIUM]: Picked physical device");

        SodiumDeviceCreationInfo deviceInfo;

        device = physicalDevice->CreateDevice(deviceInfo);
        if(!device || !device->IsValid()) {
            Logger::CriticalError("[SODIUM]: Was not able to create device");
        }

        Logger::Log("[SODIUM]: Created device");
    }

    void InitializeWithSurface(ESurfaceType type, void* handle) {
        SodiumSurfaceCreateInfo info;
        info.surfaceType = type;
        info.pHandle = handle;
        
        surface = instance->CreateSurface(info);
    }
};