//
// Created by bhanu on 06-Feb-22.
//

#include "Shader.h"
#include "util.h"
#include <vector>

Shader::Shader(const char *vertexShaderPath, const char *fragmentShaderPath) {
    std::string vString = readFileIntoString(vertexShaderPath);
    std::string fString = readFileIntoString(fragmentShaderPath);
    const char *vSource = vString.c_str();
    const char *fSource = fString.c_str();
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vSource, nullptr);
    glCompileShader(vertexShader);
    compileStatus(vertexShader);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fSource, nullptr);
    glCompileShader(fragmentShader);
    compileStatus(fragmentShader);
    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);
    detach(vertexShader);
    detach(fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

}

void Shader::use() {
    glUseProgram(ID);
}

void Shader::detach(GLuint shader) {
    glDetachShader(ID, shader);
}

void Shader::compileStatus(GLuint shader) {
    GLint success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLint maxLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
        std::string log(maxLength, ' ');
        GLsizei written;
        glGetShaderInfoLog(shader, maxLength, &written, &log[0]);
        std::cerr << "Shader compilation: " << log;
    }
}
