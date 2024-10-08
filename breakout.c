#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "assert.h"
#include "stdio.h"

#include "bo_window.h"
#include "bo_shader.h"

#define WIDTH 800
#define HEIGHT 600

const char *vertex_shader_source = "#version 330 core\n"
                                   "layout (location = 0) in vec3 aPos;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                   "}\0";
const char *fragment_shader_source = "#version 330 core\n"
                                     "out vec4 FragColor;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   FragColor = vec4(0.0f, 1.0f, 0.5f, 1.0f);\n"
                                     "}\n\0";

// clang-format off
float vertices[] = {
    // positions
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f,  0.5f, 0.0f,  // top left
    -0.5f, -0.5f, 0.0f   // bottom left
};
unsigned int indices[] = {  // note that we start from 0!
    0, 1, 2,   // first triangle
    1, 3, 2    // second triangle
};
// clang-format on

int main()
{

    bo_Window bw = {0};
    if (!bo_create_window(WIDTH, HEIGHT, "Breakout", &bw))
    {
        fprintf(stderr, "Failed to create GLFW window\n");
        return 1;
    }

    GLuint vertex_shader;
    if (!bo_create_shader(bo_VertexShader, &vertex_shader, vertex_shader_source))
    {
        fprintf(stderr, "Failed to create vertex shader\n");
        return 1;
    };

    GLuint fragment_shader;
    if (!bo_create_shader(bo_FragmentShader, &fragment_shader, fragment_shader_source))
    {
        fprintf(stderr, "Failed to create fragment shader\n");
        return 1;
    };
    ;

    GLuint shader_program;
    if (!bo_create_program(&shader_program, vertex_shader, fragment_shader))
    {
        fprintf(stderr, "Failed to create shader program\n");
        return 1;
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLuint EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(bw.glfw_window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader_program);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(bw.glfw_window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shader_program);

    glfwTerminate();
    return 0;
}