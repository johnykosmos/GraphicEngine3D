#include "Shader.hpp"

#include "glad/glad.h"
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <fstream>
#include <sstream>


namespace eng {
    bool Shader::getShaderContent(const std::string& source) {
        std::ifstream stream(source);
        if (!stream.is_open()) {
            std::cerr << "Error: Could not open shader file " << source << std::endl;
            return false;
        }

        std::string line;
        std::stringstream ss[2];
        ShaderType type = NONE;

        while (getline(stream, line)) {
            if (line.find("#shader") != std::string::npos) {
                if (line.find("vertex") != std::string::npos) {
                    type = VERTEX; 
                } else if (line.find("fragment") != std::string::npos) {
                    type = FRAGMENT; 
                } 
            }else {
                if (type == VERTEX) {
                    ss[VERTEX] << line << '\n';
                } else if (type == FRAGMENT) {
                    ss[FRAGMENT] << line << '\n';
                }
            }
        }
        vertexSource = ss[VERTEX].str();
        fragmentSource = ss[FRAGMENT].str();

          std::cout << "Vertex Shader:\n" << ss[VERTEX].str() << std::endl;
    std::cout << "Fragment Shader:\n" << ss[FRAGMENT].str() << std::endl;

        return true;
    }

    unsigned int Shader::compileShader(unsigned int type, const std::string& sourcePath) {
        unsigned int shader = glCreateShader(type);
        const char* source = sourcePath.c_str();
        glShaderSource(shader, 1, &source, nullptr);
        glCompileShader(shader);

        int success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            std::cerr << "Shader Compilation Error: " << infoLog << std::endl;
            glDeleteShader(shader);
            return 0;
        }

        return shader;
    }

    unsigned int Shader::createShaderProgram(const std::string& source) {
        if (!getShaderContent(source)) {
            return 0;
        }
        unsigned int program = glCreateProgram();
        unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexSource);
        unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentSource);

        glAttachShader(program, vs);
        glAttachShader(program, fs);
        glLinkProgram(program);

        int success;
        glGetProgramiv(program, GL_LINK_STATUS, &success);

        glDetachShader(program, vs);
        glDetachShader(program, fs);

        if (!success) {
            char infoLog[512];
            glGetProgramInfoLog(program, 512, nullptr, infoLog);
            std::cerr << "Shader Linking Error: " << infoLog << std::endl;
            glDeleteShader(vs);
            glDeleteShader(fs);
            glDeleteProgram(program);
            return 0;
        }

        glDeleteShader(vs);
        glDeleteShader(fs);

        return program;
    }

    Shader::Shader(const std::string& source){
        unsigned int program = createShaderProgram(source);
        if (!program) {
            return;
        }
        id = program;
    }

    Shader::~Shader(){
        glDeleteProgram(id);
    }

    void Shader::bind() const {
        glUseProgram(id);
    }

    void Shader::setUniform4fv(const char* uniform, const glm::mat4& value) const{
        auto location = glGetUniformLocation(id, uniform); 
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
    }

    void Shader::setUniform1i(const char* uniform, const int value) const{
        auto location = glGetUniformLocation(id, uniform); 
        glUniform1i(location, value);
    }

    void Shader::unbind() const {
        glUseProgram(0);
    }
}
