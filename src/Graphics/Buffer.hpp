#include <GL/glew.h>
#include "Handle.hpp"
#pragma once

class Buffer {
private:
        struct create { GLuint operator()() { GLuint a; glGenBuffers(1, &a); return a; } };
        struct destroy { void operator()(GLuint& buff) { glDeleteBuffers(1, &buff); } };
        Handle<create, destroy> buffer;
public:
        auto operator*() const {
                return *buffer;
        }
};
