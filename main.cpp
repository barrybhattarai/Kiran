#include "MainWindow.h"
#include <cstdlib>
#include<fstream>
#include <iostream>
#include <config.h>
#include "VBO.h"
#include "VAO.h"
#include "Shader.h"
#include "EBO.h"
#include "Camera.h"
#include <string>
#include <glm/matrix.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void getFPS(int &fpsCounter, double &previousTime, int &fps) {

    double currentTime = glfwGetTime();

    auto timeDiff = currentTime - previousTime;

    fpsCounter++;
    if (timeDiff >= 0.5) {
        fps = (int) fpsCounter / timeDiff;
        fpsCounter = 0;
        previousTime = currentTime;

    }
}

int main() {
    std::cout << "Sage v" << Sage_VERSION_MAJOR << "." << Sage_VERSION_MINOR << std::endl;
    MainWindow window(512, 512, "Sage");
    window.makeCurrentContext();
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    GLfloat vertices[] = {
            // front
            -1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
            -1.0, 1.0, 1.0,
            // back
            -1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, -1.0,
            -1.0, 1.0, -1.0
    };

    GLfloat colorData[] = {
            // front colors
            1.0, 0.0, 0.0,
            0.0, 1.0, 0.0,
            0.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
            // back colors
            1.0, 0.0, 0.0,
            0.0, 1.0, 0.0,
            0.0, 0.0, 1.0,
            1.0, 1.0, 1.0
    };

    GLuint indices[] = {
            // front
            0, 1, 2,
            2, 3, 0,
            // right
            1, 5, 6,
            6, 2, 1,
            // back
            7, 6, 5,
            5, 4, 7,
            // left
            4, 0, 3,
            3, 7, 4,
            // bottom
            4, 5, 1,
            1, 0, 4,
            // top
            3, 2, 6,
            6, 7, 3
    };

    Shader shader("vertex_shader.glsl", "fragment_shader.glsl");

    VAO vao;
    vao.bind();

    VBO vbo(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    VBO colors(GL_ARRAY_BUFFER, sizeof(colorData), colorData, GL_STATIC_DRAW);
    EBO ebo(sizeof(indices), indices);
    ebo.bind();

    vao.linkAttrib(vbo, 0, 3, GL_FLOAT, 0, nullptr);
    vao.linkAttrib(colors, 1, 3, GL_FLOAT, 0, nullptr);


    glClearColor(0.5, 0.5, 0.5, 1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glfwSwapInterval(1);
    //transform matrix
    glm::mat4 transform = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4 (1.0);
    glm::mat4 rotate = glm::rotate(glm::radians(30.0f), glm::vec3(1,0,0));
    glm::mat4 translate = glm::mat4(1.0);
    glm::mat4 modelMatrix = translate * rotate * scale;
    Camera camera(glm::vec3(0, 0, 4),
                  glm::vec3(0, 0, 0),
                  glm::vec3(0, 1, 0));

    GLint transformLoc = glGetUniformLocation(shader.ID, "transform");

    int fps;
    int fpsCounter = 0;
    double previousTime = 0;
    while (!window.shouldClose()){
        getFPS(fpsCounter, previousTime, fps);
        glfwSetWindowTitle(window.instance, std::to_string(fps).append(" Sage").c_str());
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shader.use();
        GLint w, h;
        glfwGetFramebufferSize(window.instance, &w, &h);
        glm::mat4 projectionMatrix = glm::perspective(glm::radians(60.0f), (float) w / (float) h, 0.1f, 100.0f);
        modelMatrix = translate * rotate * scale;

        transform = projectionMatrix * camera.getViewMatrix() * modelMatrix;
//        camera.position = camera.position + glm::vec3 (0.1, 0,0);
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, NULL);
        window.swapBuffer();
        glfwPollEvents();
    }

    window.destroy();
    glfwTerminate();
    std::cout << "Closing";
    exit(EXIT_SUCCESS);
}
