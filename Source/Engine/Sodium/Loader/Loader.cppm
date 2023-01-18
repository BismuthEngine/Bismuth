export module Sodium:Loader;

export import SodiumAPI;

// Import platform implementations
#ifndef PLATFORM_WEBASM
    #define SUPPORTED_VULKAN
    import SodiumVulkan;

    #if PLATFORM_WINDOWS
        #define SUPPORTED_DX12
        
    #endif
#endif

export enum ESodiumAPI {
	None,
	Vulkan,
	DirectX12,
	GLES
};

// Sodium API's Factory
// Creates objects and watches their state
export class Sodium {
protected:
	static ESodiumAPI SAPI;
	static bool bDeviceCreated;

	static bool DoesSupportAPI(ESodiumAPI api) {
		switch (api) {
		case DirectX12:
			#if PLATFORM_WINDOWS
				return true;
			#else
				return false;
			#endif
		case Vulkan:
			return true;
		default:
			return false;
		}
	}
public:

	static void SetAPI(ESodiumAPI api) {
		if (bDeviceCreated == false && DoesSupportAPI(api))
		{
			Sodium::SAPI = api;
		}
	}


	// Creates specified API's Instance
	static ISodiumInstance* CreateInstance(SodiumInstanceCreationInfo createInfo) {
		if(SAPI == ESodiumAPI::Vulkan) {
			return new VkSodiumInstance(createInfo);
		}

		return nullptr;
	}
};

ESodiumAPI Sodium::SAPI = ESodiumAPI::Vulkan;
bool Sodium::bDeviceCreated = false;