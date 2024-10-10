#ifndef __WINDOW_H
#define __WINDOW_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

typedef struct
{
    int width;
    int height;
    GLFWwindow *glfw_window;

} Window;

int create_window(int width, int heigth, const char *title, Window *bo_window);

#endif
