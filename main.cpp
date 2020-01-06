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
    renderer.test();
    if (!glfwInit())
    {
        std::cerr << "glfwInit failed." << std::endl;
        exit(EXIT_FAILURE);
    }
    aWindow = glfwCreateWindow(aWidth, aHeight, aTitle.c_str(), nullptr, nullptr);
    if (!aWindow)
    {
        std::cerr << "glfwCreateWindow failed." << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(aWindow);
    std::cout << glfwGetVersionString() << std::endl; // Returns a string describing the compile-time configuration.
    glClearColor(1, 1, 1, 1);

    while (!glfwWindowShouldClose(aWindow))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(aWindow); // Swaps the front and back buffers of the specified window.
        glfwPollEvents();         //input
    }
    glfwTerminate();

    return EXIT_SUCCESS;
}
