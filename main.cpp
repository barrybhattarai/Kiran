#include "MainWindow.h"
#include <cstdlib>
#include<fstream>
#include <iostream>
#include <config.h>
#include "VBO.h"
#include "VAO.h"
#include "Shader.h"
#include "EBO.h"

int main() {
    std::cout << "Sage v" << Sage_VERSION_MAJOR << std::endl;
    MainWindow window(512, 512, "Sage");
    window.makeCurrentContext();
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    float vertices[] = {
            -0.5f, 0.5, 0, 1, 0, 0,
            -0.5f, -0.5, 0, 0, 1, 0,
            0.5f, -0.5, 0, 0, 0, 1,
            0.5, 0.5, 0, 1, 1, 1

    };

    GLuint indices[] = {
            0, 1, 2,
            0, 2, 3
    };
    Shader shader("vertex_shader.glsl", "fragment_shader.glsl");

    VAO vao;
    vao.bind();


    VBO vbo(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    EBO ebo(sizeof(indices), indices);
    ebo.bind();

    vao.linkAttrib(vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), nullptr);
    vao.linkAttrib(vbo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *) (3 * sizeof(float)));

    glClearColor(0.5, 0.5, 0.5, 1);
    while (!window.shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT);
        shader.use();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        window.swapBuffer();
        glfwPollEvents();
    }

    window.destroy();
    glfwTerminate();
    std::cout << "Closing";
    exit(EXIT_SUCCESS);
}
