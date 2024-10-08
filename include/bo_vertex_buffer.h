#ifndef __BO_VERTEX_BUFFER_H
#define __BO_VERTEX_BUFFER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

typedef struct
{
    GLuint id;
} bo_VertexBuffer;

bo_VertexBuffer bo_create_vertex_buffer(float *vertices, GLuint size);

void bo_bind_vertex_buffer(bo_VertexBuffer vertex_buffer);
void bo_unbind_vertex_buffer();
void bo_delete_vertex_buffer(bo_VertexBuffer vertex_buffer);

#endif