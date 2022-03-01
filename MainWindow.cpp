//
// Created by bhanu on 06-Feb-22.
//

#include "MainWindow.h"

MainWindow::MainWindow(int width, int height, const char *title) {
    init();
    instance = glfwCreateWindow(width, height, title, nullptr, nullptr);
    setWidth(width);
    setHeight(height);
    if (!instance) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwSetKeyCallback(instance, key_callback);
    glfwSetErrorCallback(error_callback);
    glfwSetFramebufferSizeCallback(instance, framebuffer_size_callback);
}

void MainWindow::init() {
    if (!glfwInit()) exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);


}

void MainWindow::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    if (key == GLFW_KEY_UP && action == GLFW_PRESS) {

    }
}

void MainWindow::error_callback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}

void MainWindow::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void MainWindow::makeCurrentContext() const {
    glfwMakeContextCurrent(instance);
}

void MainWindow::swapBuffer() {
    glfwSwapBuffers(instance);

}

void MainWindow::destroy() {
    glfwDestroyWindow(instance);

}

bool MainWindow::shouldClose() {
    return glfwWindowShouldClose(instance);
}

int MainWindow::getWidth() const {
    return width;
}

void MainWindow::setWidth(int width) {
    this->width = width;
}

int MainWindow::getHeight() const {
    return height;
}

void MainWindow::setHeight(int height) {
    this->height = height;
}
