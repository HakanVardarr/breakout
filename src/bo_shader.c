#include "stdio.h"
#include "stdlib.h"

#include "bo_shader.h"

int bo_create_shader(bo_ShaderType shader_type, GLuint *shader_id, const char *shader_path)
{

    const char *shader_source;
    if (!bo_read_shader(shader_path, (char **)&shader_source))
    {
        fprintf(stderr, "[ERROR]: Failed to read fragment shader\n");
    }

    *shader_id = glCreateShader(shader_type == bo_FragmentShader ? GL_FRAGMENT_SHADER : GL_VERTEX_SHADER);
    glShaderSource(*shader_id, 1, &shader_source, NULL);
    glCompileShader(*shader_id);

    int success;
    glGetShaderiv(*shader_id, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        char info_log[512];
        glGetShaderInfoLog(*shader_id, 512, NULL, info_log);
        fprintf(stderr, "%s: %s", shader_path, info_log);
    }

    free((char *)shader_source);

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

    if (!success)
    {
        char info_log[512];
        glGetProgramInfoLog(*program_id, 512, NULL, info_log);
        fprintf(stderr, "%s", info_log);
    }

    return success;
}

int bo_read_shader(const char *shader_path, char **shader_source)
{
    FILE *fd;
    char *buffer;

    fd = fopen(shader_path, "rb");
    if (fd == NULL)
    {
        return 0;
    }

    fseek(fd, 0, SEEK_END);
    long length = ftell(fd);
    fseek(fd, 0, SEEK_SET);

    buffer = (char *)malloc(length);
    if (buffer == NULL)
    {
        return 0;
    }

    fread(buffer, 1, length, fd);

    *shader_source = buffer;
    fclose(fd);

    return 1;
}

void bo_use_program(GLuint program_id)
{
    glUseProgram(program_id);
}

void bo_delete_program(GLuint program_id)
{
    glDeleteProgram(program_id);
}

void bo_program_set_bool(GLuint program_id, const char *name, bool value)
{
    glUniform1i(glGetUniformLocation(program_id, name), (int)value);
}

void bo_program_set_int(GLuint program_id, const char *name, int value)
{
    glUniform1i(glGetUniformLocation(program_id, name), value);
}

void bo_program_set_float(GLuint program_id, const char *name, float value)
{
    glUniform1f(glGetUniformLocation(program_id, name), value);
}