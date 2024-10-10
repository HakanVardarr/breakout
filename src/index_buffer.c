#include "index_buffer.h"

IndexBuffer create_index_buffer(GLuint *indices, GLuint size)
{
    GLuint id;
    glGenBuffers(1, &id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);

    return (IndexBuffer){id, size};
}

void bind_index_buffer(IndexBuffer index_buffer)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer.id);
}

void unbind_index_buffer()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void delete_index_buffer(IndexBuffer index_buffer)
{
    glDeleteBuffers(1, &index_buffer.id);
}