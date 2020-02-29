#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>

#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>
#include "Debugging.h"
#include "Foundation.h"

#define GLFW_INCLUDE_VULKAN

static const int WIDTH = 1024;
static const int HEIGHT = 768;


class VulkanMath {
 public:
  int main() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
    return EXIT_SUCCESS;
  }

 private:
  void initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(WIDTH, HEIGHT, APP_TITLE, nullptr, nullptr);
  };

  void initVulkan() {
    foundation = Foundation();
  };

  void mainLoop() {};

  void cleanup() {
    debugger.cleanup(foundation.instance);
    glfwDestroyWindow(window);
    glfwTerminate();
  };

  GLFWwindow *window;
  Foundation foundation;
  vk::DispatchLoaderDynamic dynamicDispatch;
  Debugging debugger;
};

int main() {
  auto a = VulkanMath();
  a.main();
}