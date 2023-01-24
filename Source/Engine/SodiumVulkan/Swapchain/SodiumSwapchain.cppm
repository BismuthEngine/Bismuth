export module SodiumVulkan:SodiumSwapchain;

import SodiumAPI;
import :vulka;

export class VkSodiumSwapchain : public ISodiumSwapchain {
    vk::SwapchainKHR swapchain;
public:
    VkSodiumSwapchain(vk::SwapchainKHR swp) {
        swapchain = swp;
    }
};