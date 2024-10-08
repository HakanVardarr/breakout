#include "bo_shader.h"

int bo_create_shader(bo_ShaderType shader_type, GLuint *shader_id, const char *shader_source)
{
    *shader_id = glCreateShader(shader_type == bo_FragmentShader ? GL_FRAGMENT_SHADER : GL_VERTEX_SHADER);
    glShaderSource(*shader_id, 1, &shader_source, NULL);
    glCompileShader(*shader_id);

    int success;
    glGetShaderiv(*shader_id, GL_COMPILE_STATUS, &success);

    return success;
}

int bo_create_program(GLuint *program_id, GLuint vertex_shader, GLuint fragment_shader)
{
    *program_id = glCreateProgram();
    glAttachShader(*program_id, vertex_shader);
    glAttachShader(*program_id, fragment_shader);
    glLinkProgram(*program_id);

    int success;
    glGetProgramiv(*program_id, GL_LINK_STATUS, &success);

    return success;
}