export module SodiumVulkan:SodiumSurface;

import SodiumAPI;
import :vulka;

export class VkSodiumSurface : public ISodiumSurface {
    vk::SurfaceKHR surface;
public:
    VkSodiumSurface(vk::SurfaceKHR _surface) {
        surface = _surface;
    }

    vk::SurfaceKHR GetSurfaceKHR() const {
        return surface;
    }

    virtual bool IsValid() const override {
        return surface != nullptr;
    }
};