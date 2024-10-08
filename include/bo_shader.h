#ifndef __BO_SHADER_H
#define __BO_SHADER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

typedef enum
{
    bo_VertexShader,
    bo_FragmentShader,
} bo_ShaderType;

int bo_create_shader(bo_ShaderType shader_type, GLuint *shader_id, const char *shader_source);
int bo_create_program(GLuint *program_id, GLuint vertex_shader, GLuint fragment_shader);

#endif