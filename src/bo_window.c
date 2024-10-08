#include "stdio.h"
#include "assert.h"
#include "bo_window.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    bo_Window *bo_window = (bo_Window *)glfwGetWindowUserPointer(window);
    if (bo_window)
    {
        bo_window->height = height;
        bo_window->width = width;
        glViewport(0, 0, width, height);
    }
}

void error_callback(int error, const char *description)
{
    fprintf(stderr, "GLFW Error (%d): %s\n", error, description);
}

int bo_create_window(int width, int height, const char *title, bo_Window *bw)
{
    if (!glfwInit())
    {
        return 0;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GL_FALSE);
    glfwSetErrorCallback(error_callback);

    GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        return 0;
    }

    bw->glfw_window = window;
    bw->width = width;
    bw->height = height;

    glfwMakeContextCurrent(bw->glfw_window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return 0;
    }

    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetWindowUserPointer(window, bw);

    return 1;
}