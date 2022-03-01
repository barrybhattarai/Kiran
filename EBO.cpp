//
// Created by bhanu on 06-Feb-22.
//

#include "EBO.h"

EBO::EBO(GLsizeiptr size, const void *indices) {

    glGenBuffers(1, &ID);
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
    unbind();
}

void EBO::bind() {

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}


GLuint ebo;
