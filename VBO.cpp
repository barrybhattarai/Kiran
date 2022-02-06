//
// Created by bhanu on 06-Feb-22.
//

#include "VBO.h"

VBO::VBO(GLenum type , GLsizeiptr size, const void *data, GLenum usage) {
 glGenBuffers(1, &ID);
 this->type = type;
 this->usage = usage;
 bind();
 glBufferData(this->type, size, data, usage);
 unbind();

}

void VBO::bind() {
glBindBuffer(type, ID );
}

void VBO::unbind() {
glBindBuffer(type, 0);
}
