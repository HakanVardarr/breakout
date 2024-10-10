#include "texture.h"

int create_texture(const char *image_path, GLuint *texture_id)
{
    int width, height, nr_channels;
    stbi_set_flip_vertically_on_load(1);
    unsigned char *data = stbi_load(image_path, &width, &height, &nr_channels, 0);

    if (data == NULL)
    {
        fprintf(stderr, "[ERROR]: cannot find container.jph\n");
        return 0;
    }

    glGenTextures(1, texture_id);
    glBindTexture(GL_TEXTURE_2D, *texture_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);

    return 1;
}