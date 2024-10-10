#ifndef __VERTEX_BUFFER_H
#define __VERTEX_BUFFER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

typedef struct
{
    GLuint id;
} VertexBuffer;

VertexBuffer create_vertex_buffer(float *vertices, GLuint size);

void bind_vertex_buffer(VertexBuffer vertex_buffer);
void unbind_vertex_buffer();
void delete_vertex_buffer(VertexBuffer vertex_buffer);

#endif