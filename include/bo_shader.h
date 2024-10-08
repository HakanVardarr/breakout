#ifndef __BO_SHADER_H
#define __BO_SHADER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stdbool.h"

typedef enum
{
    bo_VertexShader,
    bo_FragmentShader,
} bo_ShaderType;

int bo_create_shader(bo_ShaderType shader_type, GLuint *shader_id, const char *shader_source);
int bo_create_program(GLuint *program_id, GLuint vertex_shader, GLuint fragment_shader);
int bo_read_shader(const char *shader_path, char **shader_source);

void bo_use_program(GLuint program_id);
void bo_delete_program(GLuint program_id);

void bo_program_set_bool(GLuint program_id, const char *name, bool value);
void bo_program_set_int(GLuint program_id, const char *name, int value);
void bo_program_set_float(GLuint program_id, const char *name, float value);

#endif