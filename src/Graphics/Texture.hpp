#include <GL/glew.h>
#include "Handle.hpp"
#pragma once

class Texture {
private:
        struct create { GLuint operator()() { GLuint a; glGenTextures(1, &a); return a; } };
        struct destroy { void operator()(GLuint& buff) { glDeleteTextures(1, &buff); } };
        Handle<create, destroy> texture;
public:
        auto operator*() const {
                return *texture;
        }
};
