#include <GLFW/glfw3.h>
#include "Foundation.h"

Foundation::Foundation() {
  instance = constructInstance();

  // Debugging & CPP bindings for vulkan
  debugger.setupDebugMessenger(instance);
  dynamicDispatch.init(instance, &vkGetInstanceProcAddr);

}

vk::Instance Foundation::constructInstance() {
  auto appInfo = vk::ApplicationInfo("Daniel inc.");
  uint32_t glfwExtensionCount = 0;
  const char **glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  std::vector<const char *> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);
  extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

  auto createInfo = vk::InstanceCreateInfo(
      {},
      &appInfo,
      static_cast<uint32_t>(validationLayers.size()),
      validationLayers.data(),
      static_cast<uint32_t>(extensions.size()),
      extensions.data()
  );

  vk::Instance tempInstance;
  if (vk::createInstance(&createInfo, nullptr, &tempInstance) != vk::Result::eSuccess) {
    throw std::runtime_error("Could not create instance!");
  }

  return tempInstance;
}
vk::PhysicalDevice Foundation::pickPhysical() {
  return vk::PhysicalDevice();
}
