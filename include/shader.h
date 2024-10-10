#ifndef __SHADER_H
#define __SHADER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stdbool.h"

typedef enum
{
    VertexShader,
    FragmentShader,
} ShaderType;

int create_shader(ShaderType shader_type, GLuint *shader_id, const char *shader_source);
int create_program(GLuint *program_id, GLuint vertex_shader, GLuint fragment_shader);
int read_shader(const char *shader_path, char **shader_source);

void use_program(GLuint program_id);
void delete_program(GLuint program_id);

void program_set_bool(GLuint program_id, const char *name, bool value);
void program_set_int(GLuint program_id, const char *name, int value);
void program_set_float(GLuint program_id, const char *name, float value);

#endif