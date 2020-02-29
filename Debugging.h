//
// Created by Daniel on 25-Feb-20.
//

#ifndef VULKANMATH__DEBUGGING_H_
#define VULKANMATH__DEBUGGING_H_

#include <vulkan/vk_platform.h>
#include <vulkan/vulkan.hpp>
#include <iostream>

class Debugging {
 public:
  VkDebugUtilsMessengerEXT debugMessenger;

  static VKAPI_ATTR vk::Bool32 VKAPI_CALL debugCallback(
      VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
      VkDebugUtilsMessageTypeFlagsEXT messageType,
      const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
      void *pUserData) {

    std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

    return VK_FALSE;
  }

  static VkResult CreateDebugUtilsMessengerEXT(VkInstance instance,
                                               const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo,
                                               const VkAllocationCallbacks *pAllocator,
                                               VkDebugUtilsMessengerEXT *pDebugMessenger) {
    auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
    if (func != nullptr) {
      return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
    } else {
      return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
  }

  static void DestroyDebugUtilsMessengerEXT(VkInstance instance,
                                            VkDebugUtilsMessengerEXT debugMessenger,
                                            const VkAllocationCallbacks *pAllocator) {
    auto
        func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
    if (func != nullptr) {
      func(instance, debugMessenger, pAllocator);
    }
  }

  void setupDebugMessenger(vk::Instance instance) {
    auto createInfo = vk::DebugUtilsMessengerCreateInfoEXT();
    createInfo.messageSeverity =
        vk::DebugUtilsMessageSeverityFlagBitsEXT::eError | vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning
            | vk::DebugUtilsMessageSeverityFlagBitsEXT::eInfo | vk::DebugUtilsMessageSeverityFlagBitsEXT::eVerbose;
    createInfo.messageType =
        vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation | vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance
            | vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral;
    createInfo.pfnUserCallback =
        reinterpret_cast<PFN_vkDebugUtilsMessengerCallbackEXT>(debugCallback);
    if (CreateDebugUtilsMessengerEXT(instance,
                                     reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT *>(&createInfo),
                                     nullptr,
                                     &debugMessenger) != VK_SUCCESS) {
      throw std::runtime_error("failed to set up debug messenger!");
    }
  }

  void cleanup(vk::Instance instance) {
    DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
  }
};

#endif //VULKANMATH__DEBUGGING_H_
