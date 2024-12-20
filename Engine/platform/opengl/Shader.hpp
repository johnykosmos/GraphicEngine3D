
#pragma once

#include <string>
#include <glm/mat4x4.hpp>
#include "Typedefs.hpp"


namespace eng {

    /**
     * @enum ShaderType
     * @brief Enum representing the type of shader (vertex or fragment).
     */
    enum ShaderType {
        NONE = -1,      
        VERTEX = 0,     
        FRAGMENT = 1    
    };
    
    /**
     * @class Shader
     * @brief A class for loading, compiling, and using OpenGL shaders.
     *
     * This class is used to load and compile shaders from source files, 
     * create an OpenGL shader program, and bind/unbind the shader program
     * for rendering. It handles both vertex and fragment shaders.
     */
    class Shader {
    private:
        unsigned int id;               
        std::string vertexSource;     
        std::string fragmentSource;  

    private:
        /**
         * @brief Loads the shader source code from a file.
         * 
         * This function reads the contents of the shader source file
         * and splits it into the vertex and fragment shader parts based
         * on the #shader directives in the file.
         * 
         * @param source The path to the shader source file.
         * @return true if the shader source was successfully loaded.
         * @return false if there was an error opening or reading the file.
         */
        bool getShaderContent(const std::string& source); 

        /**
         * @brief Compiles a shader of a given type (vertex/fragment).
         * 
         * This function takes the shader source code and compiles it using
         * OpenGL's shader compilation function.
         * 
         * @param type The type of shader to compile (either GL_VERTEX_SHADER or GL_FRAGMENT_SHADER).
         * @param source The shader source code to compile.
         * @return The OpenGL shader ID if compilation was successful.
         * @return 0 if compilation failed.
         */
        unsigned int compileShader(unsigned int type, const std::string& source);

        /**
         * @brief Creates an OpenGL shader program from vertex and fragment shaders.
         * 
         * This function compiles both the vertex and fragment shaders, attaches them to
         * a shader program, and links the program. It returns the program ID if successful.
         * 
         * @param source The path to the shader source file.
         * @return The OpenGL shader program ID if creation was successful.
         * @return 0 if program creation failed.
         */
        unsigned int createShaderProgram(const std::string& source);

    public:
        /**
         * @brief Constructs a shader program from the given source file.
         * 
         * This constructor loads the shader source, compiles the shaders, and creates
         * an OpenGL shader program. The program is automatically bound to the `id` member.
         * 
         * @param source The path to the shader source file.
         */
        explicit Shader(const std::string& source);

        /**
         * @brief Destructor that deletes the OpenGL shader program.
         */
        ~Shader();

        /**
         * @brief Binds the shader program for use in OpenGL.
         * 
         * This function binds the shader program to the OpenGL context, making it active
         * for rendering operations.
         */
        void bind() const;

        /**
         * @brief Unbinds the current shader program.
         * 
         * This function unbinds the shader program, effectively disabling it in the OpenGL context.
         */
        void unbind() const;

        /**
         * @brief Sets a uniform matrix variable in the shader program.
         * 
         * @param uniform The name of the uniform variable in the shader source.
         * @param value The Mat4 value to pass to the uniform variable.
         */
        void setUniformMat4(const char* uniform, const glm::mat4& value) const; 

        /**
         * @brief Sets a uniform vector variable in the shader program.
         * 
         * @param uniform The name of the uniform variable in the shader source.
         * @param value The Vec3 value to pass to the uniform variable.
         */
        void setUniformVec3(const char* uniform, const Vec3& value) const;

        /**
         * @brief Sets a uniform 1i variable in the shader program.
         * 
         * @param uniform The name of the uniform variable in the shader source.
         * @param value The int value to pass to the uniform variable.
         */
        void setUniform1i(const char* uniform, const int value) const;
    }; 

}


