#include <GL/glew.h>
#include "Handle.hpp"
#pragma once

class Program {
private:
        struct create { GLuint operator()() { return glCreateProgram(); } };
        struct destroy { void operator()(GLuint prog) { glDeleteProgram(prog); } };
        Handle<create, destroy> program;
public:
        auto operator*() const {
                return *program;
        }
};
