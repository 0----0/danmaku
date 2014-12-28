#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "initError.hpp"

class GLFWInitializer {
public:
        GLFWInitializer() {
                if(!glfwInit()) {
                        throw initError("glfw init failed!");
                }
        }
        ~GLFWInitializer() {
                glfwTerminate();
        }
};

class GLFWInit {
public:
        GLFWInit() {
                static GLFWInitializer init;
        }
};
