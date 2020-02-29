//
// Created by Daniel on 25-Feb-20.
//

#ifndef VULKANMATH__FOUNDATION_H_
#define VULKANMATH__FOUNDATION_H_

#include <vulkan/vulkan.hpp>
#include <optional>
#include "Debugging.h"

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

#define VULKAN_HPP_DISPATCH_LOADER_DYNAMIC 1

VULKAN_HPP_DEFAULT_DISPATCH_LOADER_DYNAMIC_STORAGE;

static const char *const APP_TITLE = "Vulkan";

struct QueueIndices {
  std::optional<uint32_t> graphicsFamily;
  std::optional<uint32_t> presentFamily;

  bool isComplete() {
    return graphicsFamily.has_value() && presentFamily.has_value();
  };
};

class Foundation {
 public:
  Foundation();

  vk::Instance instance;
  vk::PhysicalDevice physDevice;
  vk::Device device;
  QueueIndices queueIndices;
  vk::Queue graphicsQueue;
  vk::Queue presentQueue;
 private:
  vk::Instance constructInstance();
  vk::PhysicalDevice pickPhysical(vk::Instance givenInstance);
  QueueIndices findQueueIndices(vk::PhysicalDevice physicalDevice);

  vk::DispatchLoaderDynamic dynamicDispatch;
  Debugging debugger;

  const std::vector<const char *> validationLayers = {
      "VK_LAYER_KHRONOS_validation"
  };
};

#endif //VULKANMATH__FOUNDATION_H_
