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

void Renderer::init()
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
}
/*
** シェーダーのソースプログラムをメモリに読み込む
*/
int readShaderSource(GLuint shader, const char *file)
{
    FILE *fp;
    const GLchar *source;
    GLsizei length;
    int ret;

    fp = fopen(file, "rb");
    if (fp == NULL)
    {
        perror(file);
        return -1;
    }

    fseek(fp, 0L, SEEK_END);
    length = ftell(fp);

    source = (GLchar *)malloc(length);
    if (source == NULL)
    {
        fprintf(stderr, "Could not allocate read buffer.\n");
        return -1;
    }

    fseek(fp, 0L, SEEK_SET);
    ret = fread((void *)source, 1, length, fp) != (size_t)length;
    fclose(fp);

    if (ret)
        fprintf(stderr, "Could not read file: %s.\n", file);
    else
        glShaderSource(shader, 1, &source, &length);

    free((void *)source);

    return ret;
}
/*
** シェーダの情報を表示する
*/
void printShaderInfoLog(GLuint shader)
{
    cout << "shader" << endl;
    GLsizei bufSize;

    /* シェーダのコンパイル時のログの長さを取得する */
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &bufSize);

    if (bufSize > 1)
    {
        GLchar *infoLog = (GLchar *)malloc(bufSize);

        if (infoLog != NULL)
        {
            GLsizei length;

            /* シェーダのコンパイル時のログの内容を取得する */
            glGetShaderInfoLog(shader, bufSize, &length, infoLog);
            cout << "infoLog:" << infoLog << endl;
            free(infoLog);
        }
        else
            fprintf(stderr, "Could not allocate InfoLog buffer.\n");
    }
}
void Renderer::render()
{
    //vertex shader
    GLuint vShaderId = glCreateShader(GL_VERTEX_SHADER);
    if (readShaderSource(vShaderId, "simple.vert"))
        exit(1);
    else
        glCompileShader(vShaderId);

    //fragment shader
    GLuint fShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    if (readShaderSource(fShaderId, "simple.frag"))
        exit(1);
    else
        glCompileShader(fShaderId);
    //プログラムオブジェクトの作成
    GLuint programId = glCreateProgram();
    glAttachShader(programId, vShaderId);
    glAttachShader(programId, fShaderId);

    // リンク
    glLinkProgram(programId);
    glUseProgram(programId);

    printShaderInfoLog(vShaderId);
    printShaderInfoLog(fShaderId);

    while (!glfwWindowShouldClose(glWindow))
    {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        // 頂点データ
        float vertex_position[] = {
            0.0,
            0.5,
            0.4,
            -0.25,
            -0.4,
            -0.25,
        };

        int attLocation = glGetAttribLocation(programId, "position");
        glColor3f(0, 0, 1);
        glEnableVertexAttribArray(attLocation);                                     // attribute属性を有効にする
        glVertexAttribPointer(attLocation, 2, GL_FLOAT, false, 0, vertex_position); // OpenGLからシェーダに頂点情報を渡す
        glDrawArrays(GL_TRIANGLES, 0, 3);                                           // モデルの描画

        glfwSwapBuffers(glWindow); // Swaps the front and back buffers of the specified window.
        glfwPollEvents();          //input
    }
    glfwTerminate();
}