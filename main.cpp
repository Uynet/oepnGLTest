#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "renderer.h"

static GLFWwindow *aWindow;
static int aWidth = 640;
static int aHeight = 480;
static std::string aTitle = "Hello, OpenGL";

int main()
{
    Renderer renderer = Renderer();
    renderer.render();
}
