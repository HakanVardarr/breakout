#ifndef __BO_WINDOW_H
#define __BO_WINDOW_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

typedef struct
{
    int width;
    int height;
    GLFWwindow *glfw_window;

} bo_Window;

int bo_create_window(int width, int heigth, const char *title, bo_Window *bo_window);

#endif
