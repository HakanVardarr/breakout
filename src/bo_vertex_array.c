#include "bo_vertex_array.h"

#include "stdio.h"

bo_VertexArray bo_create_vertex_array(bo_VertexBuffer vertex_buffer, GLuint *attributes, GLuint size)
{
    bo_bind_vertex_buffer(vertex_buffer);

    GLuint id;
    glGenVertexArrays(1, &id);
    glBindVertexArray(id);

    GLuint count = 0;
    for (GLuint i = 0; i < size / sizeof(GLuint); i++)
    {
        count += attributes[i];
    }

    int last = 0;
    for (GLuint i = 0; i < size / sizeof(GLuint); i++)
    {
        glVertexAttribPointer(i, attributes[i], GL_FLOAT, GL_FALSE, count * sizeof(float), (void *)(last * sizeof(float)));
        glEnableVertexAttribArray(i);

        last += attributes[i];
    }

    return (bo_VertexArray){id};
}

void bo_bind_vertex_array(bo_VertexArray vertex_array)
{
    glBindVertexArray(vertex_array.id);
}

void bo_unbind_vertex_array()
{
    glBindVertexArray(0);
}

void bo_delete_vertex_array(bo_VertexArray vertex_array)
{
    glDeleteVertexArrays(1, &vertex_array.id);
}
