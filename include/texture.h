#ifndef __TEXTURE_H
#define __TEXTURE_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "stb_image.h"

int create_texture(const char *image_path, GLuint *texture_id);

#endif