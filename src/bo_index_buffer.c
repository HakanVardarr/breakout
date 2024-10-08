#include "bo_index_buffer.h"

bo_IndexBuffer bo_create_index_buffer(GLuint *indices, GLuint size)
{
    GLuint id;
    glGenBuffers(1, &id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);

    return (bo_IndexBuffer){id, size};
}

void bo_bind_index_buffer(bo_IndexBuffer index_buffer)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer.id);
}

void bo_unbind_index_buffer()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void bo_delete_index_buffer(bo_IndexBuffer index_buffer)
{
    glDeleteBuffers(1, &index_buffer.id);
}