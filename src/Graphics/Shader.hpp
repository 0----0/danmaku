#include <GL/glew.h>
#include "Handle.hpp"
#pragma once

class Shader {
public:
        struct create { GLuint operator()(GLenum type) { return glCreateShader(type); } };
        struct destroy { void operator()(GLuint shad) { glDeleteShader(shad); } };
        Handle<create, destroy> shader;
public:
        auto operator*() const {
                return *shader;
        }
        Shader(GLenum type) :
                shader(type) {}
        Shader(const GLenum type, const std::string fileName);
};
