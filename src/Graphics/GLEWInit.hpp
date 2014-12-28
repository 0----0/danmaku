#include <GL/glew.h>
#include "initError.hpp"

class GLEWInitializer {
public:
        GLEWInitializer() {
                GLenum err = glewInit();
                if(GLEW_OK != err) {
                        throw initError(reinterpret_cast<const char*>(glewGetErrorString(err)));
                }
        }
};

class GLEWInit {
public:
        GLEWInit() {
                static GLEWInitializer init;
        }
};
