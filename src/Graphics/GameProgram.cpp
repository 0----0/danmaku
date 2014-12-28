#include "GameProgram.hpp"
#include "Shader.hpp"
#include <iostream>

Program initProgram() {
        Shader vertShad(GL_VERTEX_SHADER, "./shaders/vert.glsl");
        Shader fragShad(GL_FRAGMENT_SHADER, "./shaders/frag.glsl");
        Program prog;

        glAttachShader(*prog, *vertShad);
        glAttachShader(*prog, *fragShad);

        glLinkProgram(*prog);

        glUseProgram(*prog);
        return prog;
}

template<typename T>
const GLuint GameProgram::getUniform(const T name) const {
        return glGetUniformLocation(**this, name);
}

GameProgram::GameProgram():
        Program(initProgram()),
        projection_matrix_uniform(getUniform("projection_matrix")),
        modelview_matrix_uniform(getUniform("modelview_matrix")){

}
