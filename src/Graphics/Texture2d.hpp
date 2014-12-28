#include "Texture.hpp"
#pragma once

class Texture2d {
private:
        Texture texture;
public:
        auto operator*() const {
                return *texture;
        }
        void setActive() const { glBindTexture(GL_TEXTURE_2D, *texture); }
        Texture2d(const std::string filepath);
};
