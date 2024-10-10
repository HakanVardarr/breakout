#include "vertex_buffer.h"

VertexBuffer create_vertex_buffer(float *vertices, GLuint size)
{
    GLuint id;
    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    return (VertexBuffer){id};
}

void bind_vertex_buffer(VertexBuffer vertex_buffer)
{
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer.id);
}

void unbind_vertex_buffer()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void delete_vertex_buffer(VertexBuffer vertex_buffer)
{
    glDeleteBuffers(1, &vertex_buffer.id);
}