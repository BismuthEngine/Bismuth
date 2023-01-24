export module SodiumAPI:SodiumSwapchain;

export import :SodiumObject;

class ISodiumSurface;
class ISodiumPhysicalDevice;

export enum class EImageFormat : unsigned int {
    B8G8R8A8_SRGB
};

export enum class EColorSpace : unsigned int {
    SRGB_NONLINEAR
};

export struct SodiumSwapchainCreateInfo {
    ISodiumSurface* surface;
    ISodiumPhysicalDevice* physicalDevice;

    unsigned int minImageCount;
    unsigned int imageFormat;
 
    unsigned int width, height;

    unsigned int imageArrayLayers;
};

export class ISodiumSwapchain : public ISodiumObject {

};