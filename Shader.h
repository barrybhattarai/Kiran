//
// Created by bhanu on 06-Feb-22.
//

#ifndef SAGE_SHADER_H
#define SAGE_SHADER_H

#include <glad/glad.h>

class Shader {
public:
    GLuint ID;

    Shader(const char *vertexShaderPath, const char *fragmentShaderPath);

    void use();

private:
    void detach(GLuint shader);

    void compileStatus(GLuint shader);

};


#endif //SAGE_SHADER_H
