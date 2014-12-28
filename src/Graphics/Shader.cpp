#include "Shader.hpp"
#include "fileio/text.hpp"
#include "initError.hpp"

Shader::Shader(const GLenum type, const std::string fileName):
Shader(type) {
        std::string shaderText(loadTextFile(fileName));
        const char* temp = shaderText.c_str();
        glShaderSource(*shader, 1, &temp, NULL);
        glCompileShader(*shader);

        GLint status;
        glGetShaderiv(*shader, GL_COMPILE_STATUS, &status);

        if(status == GL_FALSE) {
                GLint size;
                glGetShaderiv(*shader, GL_INFO_LOG_LENGTH, &size);

                std::string infolog;
                infolog.resize(size);
                glGetShaderInfoLog(*shader, size, NULL, &infolog[0]);
                throw initError(infolog);
        }
}
