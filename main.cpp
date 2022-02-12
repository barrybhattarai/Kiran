#include "MainWindow.h"
#include <cstdlib>
#include<fstream>
#include <iostream>
#include <config.h>
#include "VBO.h"
#include "VAO.h"
#include "Shader.h"
#include "EBO.h"
#include <string>

int main() {
    std::cout << "Sage v" << Sage_VERSION_MAJOR << std::endl;
    MainWindow window(512, 512, "Sage");
    window.makeCurrentContext();
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    float vertices[] = {
            -0.5f, 0.5, 0, 1, 00.5, 0,
            -0.5f, -0.5, 0, 0, 1, 00.5,
            0.5f, -0.5, 0, 0, 0, 1,
            0.5, 0.5, 0, 1, 0.7, 1

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
    double currentTime = 0, previousTime = 0, timeDiff;
    unsigned int fpsCounter = 0;
    glClearColor(0.5, 0.5, 0.5, 1);
    glfwSwapInterval(1);
    while (!window.shouldClose()) {
        currentTime = glfwGetTime();
        timeDiff = currentTime - previousTime;
        fpsCounter++;
        if (timeDiff >= 0.5) {
            std::string FPS = std::to_string((unsigned  int)( fpsCounter/timeDiff));
            std::string newTitle = "Sage " + FPS + " FPS";
            glfwSetWindowTitle(window.instance, newTitle.c_str());
            previousTime = currentTime;
            fpsCounter = 0;
        }
        glClear(GL_COLOR_BUFFER_BIT);
        shader.use();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        window.swapBuffer();
        glfwPollEvents();
    }

    window.destroy();
    glfwTerminate();
    std::cout << "Closing";
    exit(EXIT_SUCCESS);
}
