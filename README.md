# OpenGL with Dear ImGui TEMPLATE

### ABOUT

This is a Visual Studio 2022 project template for [OpenGL](https://www.opengl.org) applications that use [Dear ImGui](https://github.com/ocornut/imgui) for simple User-Interface rendering. It is made simple as a starting point. Using GLFW for the window and input handling, GLEW for the GL functions, and Dear ImGui for rendering the user interface. The program starts off with a GLFWwindow with a custom defined class and ready-to-go update/render calls with variable tick rates and a fixed framerate with togglable Vertical Sync, and has a custom-made class for a 3D Scene renderer where shader building, vertex buffer initializing, and render calls are made, with another separate class for the ImGui calls. The main root class is the window class. Each of the three classes is made per one instance, using a Singleton template class which can be used further.

### Required
- `C++20`
- `Visual Studio 2022` (Not tested with earlier versions)
- [Dear ImGui](https://github.com/ocornut/imgui)
- [GLFW](https://www.glfw.org)
- [GLEW](https://glew.sourceforge.net)

### How to build

The template is ready to use for further coding, simply open the .sln file in Visual Studio; However three libraries are required to be added before it can be used.
> TODO: CMake and vcpkg
> 
> TODO: ImGui backends handling with CMake?

- `#1` Download the libraries [Dear ImGui](https://github.com/ocornut/imgui), [GLFW](https://www.glfw.org), and [GLEW](https://glew.sourceforge.net)
- `#2` In the [root of the project](https://github.com/mconicx/OpenGL-With-DearImGui-Template/tree/master/OpenGL-With-DearImGui) create a new folder called `lib`, paths are already referenced in the project settings
- `#3` Extract GLFW and GLEW (The root folders from the archive) in the new `lib` folder
- `#4` In the same folder where the `lib` is created, create a new folder called `imgui`
- `#5` From Dear ImGui source archive, extract the [backends](https://github.com/ocornut/imgui/tree/master/backends) to the new `imgui` folder. Note that not all of the source files (especially not from the vulkan folder) are required, but add them all just in case
- `#6` Open the project in Visual Studio (Before or after these steps)
- `#7` To use the ImGui backends, they need to be included within the project. Add the sources that have been extracted to the `imgui` folder to the project.
- `#8` From the GLFW and GLEW binary Release folders, copy both .dlls to your project's root folder where the `lib` and `imgui` folders are, in order to be able to use them effectively.

### Have fun coding!

Changes, pushes, comments are always welcome. Fork and use at your own convenience. The Singleton class is not mine, neither can I find the original author. Possibly from a stackoverflow thread I found only a few years ago, since it works with C++20 only.
