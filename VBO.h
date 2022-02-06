//
// Created by bhanu on 06-Feb-22.
//

#ifndef SAGE_VBO_H
#define SAGE_VBO_H
#include<glad/glad.h>

class VBO {
public:
    GLuint ID;
    GLenum  type, usage;
    VBO(GLenum type,GLsizeiptr size, const void* data, GLenum usage);
    void bind();
    void unbind();

private:
    struct Vertex{
        float x;
        float y;
        float z;
        float r;
        float g;
        float b;
    };

};


#endif //SAGE_VBO_H
