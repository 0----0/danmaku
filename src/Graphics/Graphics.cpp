#include "Graphics.hpp"

const std::array<vertex,4> quad = {{
        {{0.5f, -0.5f, 0.f}, {1.f, 1.f}},
        {{-0.5f, -0.5f, 0.f}, {0.f, 1.f}},
        {{-0.5f, 0.5f, 0.f}, {0.f, 0.f}},
        {{0.5f, 0.5f, 0.f}, {1.f, 0.f}}
}};

void Graphics::setTransform(const std::array<float, 2> position, const std::array<float, 2> scale) {
        const float matrix[4][4] = {
                {scale[0], 0.f, 0.f, 0.f},
                {0.f, scale[1], 0.f, 0.f},
                {0.f, 0.f, 1.f, 0.f},
                {position[0], position[1], 0.f, 1.f}
        };
        glUniformMatrix4fv(program.modelview_matrix_uniform, 1, 0, &matrix[0][0]);
}

void init() {
        glfwSwapInterval(0);
        glClearColor(1.f, 1.f, 1.f, 1.f);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

bool Graphics::processWindow() {
        glfwSwapBuffers(*window);
        glfwPollEvents();
        return !glfwWindowShouldClose(*window);
}

void Graphics::draw() {
        glDrawArrays(GL_QUADS, 0, 4);
}

void Graphics::clear() {
        glClear(GL_COLOR_BUFFER_BIT);
}

Graphics::Graphics():
        vertexBuffer(quad, program) {
        init();
}
