#ifndef __BO_INDEX_BUFFER_H
#define __BO_INDEX_BUFFER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

typedef struct
{
    GLuint id;
    GLuint size;

} bo_IndexBuffer;

bo_IndexBuffer bo_create_index_buffer(GLuint *indices, GLuint size);

void bo_bind_index_buffer(bo_IndexBuffer index_buffer);
void bo_unbind_index_buffer();
void bo_delete_index_buffer(bo_IndexBuffer index_buffer);

#endif