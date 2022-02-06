//
// Created by bhanu on 06-Feb-22.
//

#ifndef SAGE_VAO_H
#define SAGE_VAO_H
#include<glad/glad.h>

class VAO {
public:
GLuint ID;
VAO();
void bind();
void unbind();

};


#endif //SAGE_VAO_H
