#include "Window.hpp"
#include "GLEWInit.hpp"
#include "GameProgram.hpp"
#include "VertexBuffer.hpp"
#pragma once

class Graphics {
private:
        Window window;
        GLEWInit _glewinit;
        GameProgram program;
        VertexBuffer vertexBuffer;
public:
        auto operator*() const { return *window; }
        bool processWindow();
        void setTransform(const std::array<float, 2> position, const std::array<float,2> scale);
        void clear();
        void draw();
        Graphics();
};
