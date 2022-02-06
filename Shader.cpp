//
// Created by bhanu on 06-Feb-22.
//

#include "Shader.h"
#include "util.h"

Shader::Shader(const char *vertexShaderPath, const char *fragmentShaderPath) {
    std::string vString = readFileIntoString(vertexShaderPath);
    std::string fString = readFileIntoString(fragmentShaderPath);
    const char* vSource = vString.c_str();
    const char* fSource = fString.c_str();
    GLuint  vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1, &vSource, nullptr );
    glCompileShader(vertexShader);
    GLuint  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1, &fSource, nullptr );
    glCompileShader(fragmentShader);
    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

}

void Shader::use() {
    glUseProgram(ID);
}
