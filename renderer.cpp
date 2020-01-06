#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "renderer.h"

using namespace std;

static GLFWwindow *glWindow;
static int width = 640;
static int height = 480;
static std::string title = "Hello, OpenGL";

Renderer::Renderer()
{

    if (!glfwInit())
    {
        std::cerr << "glfwInit failed." << std::endl;
        exit(EXIT_FAILURE);
    }
    glWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!glWindow)
    {
        std::cerr << "glfwCreateWindow failed." << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(glWindow);
    std::cout << glfwGetVersionString() << std::endl; // Returns a string describing the compile-time configuration.
    glClearColor(1, 1, 1, 1);
}
void Renderer::test()
{
    cout << "debugLog" << endl;
}
void Renderer::render()
{
    while (!glfwWindowShouldClose(glWindow))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(glWindow); // Swaps the front and back buffers of the specified window.
        glfwPollEvents();          //input
    }
    glfwTerminate();
}