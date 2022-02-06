#include "MainWindow.h"
#include <cstdlib>
#include<fstream>
#include <iostream>
#include <config.h>
#include "VBO.h"
#include "VAO.h"
#include "util.h"
#include "Shader.h"


int main() {
    std::cout << "Sage v" << Sage_VERSION_MAJOR << std::endl;
    MainWindow window(512, 512, "Sage");
    window.makeCurrentContext();

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    VAO vao;
    vao.bind();
    float vertices[] = {
            -0.5f, (-0.5f * sqrtf(3) / 3), 1, 0, 0,
            0.5f, (-0.5f * sqrtf(3) / 3), 0, 1, 0,
            0.0f, (0.5f * sqrtf(3) * 2 / 3), 0, 0, 1
    };


    VBO vertex_buffer(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    Shader shader("vertex_shader.glsl", "fragment_shader.glsl");


    glEnableVertexAttribArray(0);
    vertex_buffer.bind();
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            2,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            sizeof(float) * 5,                  // stride
            (void *) 0            // array buffer offset
    );
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(
            1,
            3,
            GL_FLOAT,
            GL_TRUE,
            sizeof(float) * 5,
            (void *) (sizeof(float) * 2)

    );
    glClearColor(0.5, 0.5, 0.5, 1);
    while (!window.shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT);
        shader.use();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        window.swapBuffer();
        glfwPollEvents();
    }

    window.destroy();
    glfwTerminate();
    std::cout << "closing";
    exit(EXIT_SUCCESS);
}
