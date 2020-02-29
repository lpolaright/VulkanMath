# Commit #1 - This is the beginning

In fact, this is a lie, this is the first commit I put unto github. But before that I had already created this project. 
I started over because I realised I didn't really understand all the terms.
This journal should help me understand a little bit better what I'm writing.

## CMake

I borrowed one of the Cmake scripts to find the GLFW library, it seems it's a little bit more cumbersome then just plugging
it into `CMakeLists.txt`. This is the first time I'm working with a c++ build system.
It seems like in C++ some libraries might already exist on the machine of the user, so you can link them dynamically.
I guess that is what the [`target_link_libraries`](https://cmake.org/cmake/help/latest/command/target_link_libraries.html) is for.
While the `find_package`, seems to be related to variables and of that sort.

## Win32

You will also notice that I'm building the project in Win32.
I know, I'm making life more difficult for myself. But given that this is the target platform for my vulkan app, I think
I'm doing fine. Apart from CLion not really working with the limited amount of RAM I have.

## Foundation

Then there's the actual coding, I've put a file called `Foundation`, in the hopes to put all the foundational libraries
for preparation. Things such as the Vulkan instance, GLFW window, physical device picking, and logical device creation.
