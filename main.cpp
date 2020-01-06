#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <string>

static GLFWwindow *aWindow;
static int aWidth = 640;
static int aHeight = 480;
static std::string aTitle = "Hello, OpenGL";

int main()
{
    // Initializes the GLFW library.
    if (!glfwInit())
    {
        std::cerr << "glfwInit failed." << std::endl;
        exit(EXIT_FAILURE);
    }
    // Creates a window and its associated context.
    aWindow = glfwCreateWindow(aWidth, aHeight, aTitle.c_str(), nullptr, nullptr);
    if (!aWindow)
    {
        std::cerr << "glfwCreateWindow failed." << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    // Makes the context of the specified window current for the calling thread.
    glfwMakeContextCurrent(aWindow);
    // Returns a string describing the compile-time configuration.
    std::cout << glfwGetVersionString() << std::endl;
    // glClear() で使用する色（RGBA）
    glClearColor(1, 1, 1, 1);

    // Checks the close flag of the specified window.
    while (!glfwWindowShouldClose(aWindow))
    {
        // 画面をクリア。
        glClear(GL_COLOR_BUFFER_BIT);

        // Swaps the front and back buffers of the specified window.
        glfwSwapBuffers(aWindow);
        // Processes all pending events.
        // マウスやキー入力のイベントはこの関数で監視する。
        glfwPollEvents();
    }
    // Terminates the GLFW library.
    glfwTerminate();

    return EXIT_SUCCESS;
}
