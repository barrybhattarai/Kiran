//
// Created by bhanu on 06-Feb-22.
//

#ifndef SAGE_VAO_H
#define SAGE_VAO_H
#include<glad/glad.h>
#include "VBO.h"

class VAO {
public:
GLuint ID;
VAO();
void bind();
void unbind();
void linkAttrib(VBO &vbo, GLuint layout, GLuint numOfValues,GLenum type, GLsizeiptr stride, void* offset);

};


#endif //SAGE_VAO_H
