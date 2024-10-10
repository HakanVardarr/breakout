#ifndef __INDEX_BUFFER_H
#define __INDEX_BUFFER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

typedef struct
{
    GLuint id;
    GLuint size;

} IndexBuffer;

IndexBuffer create_index_buffer(GLuint *indices, GLuint size);

void bind_index_buffer(IndexBuffer index_buffer);
void unbind_index_buffer();
void delete_index_buffer(IndexBuffer index_buffer);

#endif