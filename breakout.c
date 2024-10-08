#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "stdio.h"

#include "bo_window.h"
#include "bo_shader.h"
#include "bo_vertex_buffer.h"
#include "bo_vertex_array.h"
#include "bo_index_buffer.h"

#define WIDTH 800
#define HEIGHT 800

// clang-format off
float vertices[] = {
    // Position       
    -1.0f,  1.0f, 0.0f,
     1.0f,  1.0f, 0.0f,
    -1.0f, -1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,
};
unsigned int indices[] = {
    0, 1, 2,
    2, 3, 1,
};
// clang-format on

void bo_draw_program(GLuint program_id, bo_VertexArray vertex_array, bo_IndexBuffer index_buffer)
{
    bo_use_program(program_id);
    bo_bind_vertex_array(vertex_array);
    bo_bind_index_buffer(index_buffer);
    glDrawElements(GL_TRIANGLES, index_buffer.size, GL_UNSIGNED_INT, 0);
}

int main()
{

    bo_Window bw = {0};
    if (!bo_create_window(WIDTH, HEIGHT, "Breakout", &bw))
    {
        fprintf(stderr, "[ERROR]: Failed to create GLFW window\n");
        return 1;
    }

    GLuint vertex_shader;
    if (!bo_create_shader(bo_VertexShader, &vertex_shader, "triangle.vert"))
    {
        return 1;
    };

    GLuint fragment_shader;
    if (!bo_create_shader(bo_FragmentShader, &fragment_shader, "triangle.frag"))
    {
        return 1;
    };

    GLuint shader_program;
    if (!bo_create_program(&shader_program, vertex_shader, fragment_shader))
    {
        return 1;
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    GLuint attributes[] = {3};
    bo_VertexBuffer VBO = bo_create_vertex_buffer(vertices, sizeof(vertices));
    bo_VertexArray VAO = bo_create_vertex_array(VBO, attributes, sizeof(attributes));
    bo_IndexBuffer EBO = bo_create_index_buffer(indices, sizeof(indices));

    bo_unbind_vertex_array();
    bo_unbind_vertex_buffer();

    while (!glfwWindowShouldClose(bw.glfw_window))
    {
        bo_use_program(shader_program);
        bo_program_set_float(shader_program, "time", (float)glfwGetTime());
        bo_draw_program(shader_program, VAO, EBO);
        glfwSwapBuffers(bw.glfw_window);
        glfwPollEvents();
    }

    bo_delete_index_buffer(EBO);
    bo_delete_vertex_array(VAO);
    bo_delete_vertex_buffer(VBO);
    bo_delete_program(shader_program);

    glfwTerminate();
    return 0;
}