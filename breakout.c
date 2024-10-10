#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "stdio.h"

#include "window.h"
#include "shader.h"
#include "vertex_buffer.h"
#include "vertex_array.h"
#include "index_buffer.h"

#define WIDTH 800
#define HEIGHT 800

#define RETURN_IF_FAILED(value, return_code) \
    if (value)                               \
    {                                        \
        return return_code;                  \
    }

// clang-format off
float vertices[] = {
    // Position       
     0.0f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
     0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
};
unsigned int indices[] = {
    0, 1, 2,
};
// clang-format on

void draw_program(GLuint program_id, VertexArray vertex_array, IndexBuffer index_buffer)
{
    use_program(program_id);
    bind_vertex_array(vertex_array);
    bind_index_buffer(index_buffer);
    glDrawElements(GL_TRIANGLES, index_buffer.size, GL_UNSIGNED_INT, 0);
}

int main()
{

    Window bw = {0};
    RETURN_IF_FAILED(!create_window(WIDTH, HEIGHT, "Brekout", &bw), 1);

    GLuint vertex_shader;
    RETURN_IF_FAILED(!create_shader(VertexShader, &vertex_shader, "first.vert"), 1);

    GLuint fragment_shader;
    RETURN_IF_FAILED(!create_shader(FragmentShader, &fragment_shader, "first.frag"), 1);

    GLuint shader_program;
    RETURN_IF_FAILED(!create_program(&shader_program, vertex_shader, fragment_shader), 1);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    GLuint attributes[] = {3, 3};
    VertexBuffer VBO = create_vertex_buffer(vertices, sizeof(vertices));
    VertexArray VAO = create_vertex_array(VBO, attributes, sizeof(attributes));
    IndexBuffer EBO = create_index_buffer(indices, sizeof(indices));

    unbind_vertex_array();
    unbind_vertex_buffer();

    while (!glfwWindowShouldClose(bw.glfw_window))
    {
        use_program(shader_program);
        program_set_float(shader_program, "time", (float)glfwGetTime());
        draw_program(shader_program, VAO, EBO);

        glfwSwapBuffers(bw.glfw_window);
        glfwPollEvents();
    }

    delete_index_buffer(EBO);
    delete_vertex_array(VAO);
    delete_vertex_buffer(VBO);
    delete_program(shader_program);

    glfwTerminate();
    return 0;
}