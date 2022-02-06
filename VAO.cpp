//
// Created by bhanu on 06-Feb-22.
//

#include "VAO.h"

VAO::VAO() {
    glGenVertexArrays(1, &ID);
}

void VAO::bind() {
    glBindVertexArray(ID);
}

void VAO::unbind() {
    glBindVertexArray(0);
}

void VAO::linkAttrib(VBO &vbo, GLuint layout, GLuint numOfValues,GLenum type, GLsizeiptr stride, void* offset) {
    vbo.bind();
    glVertexAttribPointer(layout, numOfValues, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);
    vbo.unbind();
}
