#ifndef __VERTEX_ARRAY_H
#define __VERTEX_ARRAY_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "vertex_buffer.h"

typedef struct
{
    GLuint id;
} VertexArray;

VertexArray create_vertex_array(VertexBuffer vertex_buffer, GLuint *attributes, GLuint size);

void bind_vertex_array(VertexArray vertex_array);
void unbind_vertex_array();
void delete_vertex_array(VertexArray vertex_array);

#endif