#include "Buffer.hpp"
#include "Program.hpp"
#include "vertex.hpp"
#include <array>
#pragma once

class VertexBuffer: public Buffer {
private:
        void initAttribs(const Program& program) {
                GLint position = glGetAttribLocation(*program, "position");
                glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE,
                sizeof(vertex), reinterpret_cast<void*>(offsetof(vertex, position)));
                glEnableVertexAttribArray(position);

                GLint texCoords = glGetAttribLocation(*program, "texCoords");
                glVertexAttribPointer(texCoords, 2, GL_FLOAT, GL_FALSE,
                sizeof(vertex), reinterpret_cast<void*>(offsetof(vertex, texCoords)));
                glEnableVertexAttribArray(texCoords);
        }
public:
        template<std::size_t N>
        VertexBuffer(const std::array<vertex,N>& vertices, const Program& program) {
                glBindBuffer(GL_ARRAY_BUFFER, **this);
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
                                vertices.data(), GL_STATIC_DRAW);
                initAttribs(program);
        }
};
