//
// Created by bhanu on 06-Feb-22.
//

#ifndef SAGE_EBO_H
#define SAGE_EBO_H

#include<glad/glad.h>
class EBO {
public:
    GLuint  ID;
    EBO(GLsizeiptr size, const void* indices);
    void bind();
    void unbind();
};


#endif //SAGE_EBO_H
