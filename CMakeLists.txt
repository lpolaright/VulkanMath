cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(VulkanMath)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

find_package(Vulkan REQUIRED)
find_package(GLFW3 REQUIRED)
message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")

add_executable(VulkanMath VulkanMath.cpp Debugging.h Foundation.cpp Foundation.h)

include_directories("glfw/include")
include_directories(include)

target_compile_definitions(VulkanMath PRIVATE VK_USE_PLATFORM_WIN32_KHR)
target_include_directories(VulkanMath PRIVATE Vulkan::Vulkan)

target_link_libraries(VulkanMath Vulkan::Vulkan)
target_link_libraries(VulkanMath glfw3)
