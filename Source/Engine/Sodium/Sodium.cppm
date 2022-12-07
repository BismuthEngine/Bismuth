export module Sodium;

#include "SodiumDevice.h"
#include "SodiumPhysicalDevice.h"
#include "Commands/SodiumCmdBuffer.h"

#include "../Platform/platformdefs.h"

// Import platform implementations
import SodiumVulkan;

#if PLATFORM_WINDOWS != 0
//import SodiumDX12;
#endif

#if PLATFORM_APPLE != 0
import SodiumMetal;
#endif


export enum ESodiumAPI {
	None,
	Vulkan,
	DirectX12,
	Metal
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
		case Metal:
			#if PLATFORM_APPLE
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


	// Creates specified API's Logical Device
	static ISodiumDevice* CreateDevice(SodiumDeviceCreationInfo createInfo) {
		switch (SAPI) {
		case Vulkan:
			//VulkanSodiumDevice* device = new VulkanSodiumDevice();
			//device->Initialize(createInfo);
			return nullptr;
			break;
		case DirectX12:
#if PLATFORM_WINDOWS

#endif
		case Metal:
#if PLATFORM_APPLE

#endif
		default:
			//TODO Log errorr
			break;
		};

		return nullptr;
	}

	// Creates specified API's Physical Device
	static void CreatePhysicalDevice() {

	}
};

ESodiumAPI Sodium::SAPI = ESodiumAPI::None;
bool Sodium::bDeviceCreated = false;