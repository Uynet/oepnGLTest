#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "renderer.h"

int main()
{
    Renderer::init();
    Renderer::render();
}
