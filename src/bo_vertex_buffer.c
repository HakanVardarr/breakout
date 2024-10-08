#include "bo_vertex_buffer.h"

bo_VertexBuffer bo_create_vertex_buffer(float *vertices, GLuint size)
{
    GLuint id;
    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    return (bo_VertexBuffer){id};
}

void bo_bind_vertex_buffer(bo_VertexBuffer vertex_buffer)
{
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer.id);
}

void bo_unbind_vertex_buffer()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void bo_delete_vertex_buffer(bo_VertexBuffer vertex_buffer)
{
    glDeleteBuffers(1, &vertex_buffer.id);
}