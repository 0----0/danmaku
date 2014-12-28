#include "Window.hpp"

Window::Window() {
        window = glfwCreateWindow(800, 600, "danmaku v000", NULL, NULL);
        if(!window) {
                throw;
        }
        glfwMakeContextCurrent(window);
}
