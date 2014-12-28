#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "GLFWInit.hpp"

class Window {
private:
        GLFWInit init;
        GLFWwindow* window;
public:
        GLFWwindow* operator*() const {
                return window;
        }
        Window();
};
