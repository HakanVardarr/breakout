#ifndef __BO_VERTEX_ARRAY_H
#define __BO_VERTEX_ARRAY_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "bo_vertex_buffer.h"

typedef struct
{
    GLuint id;
} bo_VertexArray;

bo_VertexArray bo_create_vertex_array(bo_VertexBuffer vertex_buffer, GLuint *attributes, GLuint size);

void bo_bind_vertex_array(bo_VertexArray vertex_array);
void bo_unbind_vertex_array();
void bo_delete_vertex_array(bo_VertexArray vertex_array);

#endif