//
// Created by bhanu on 06-Feb-22.
//

#ifndef SAGE_MAINWINDOW_H
#define SAGE_MAINWINDOW_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <cstdio>

class MainWindow {
public:
    GLFWwindow *instance;

    MainWindow(int width, int height, const char *title);

    void makeCurrentContext() const;

    void swapBuffer();

    void destroy();

    bool shouldClose();

private:
    static void init();

    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    static void error_callback(int error, const char *description);

    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

    int width, height;
public:
    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);
};


#endif //SAGE_MAINWINDOW_H
