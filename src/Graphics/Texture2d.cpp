#include "Texture2d.hpp"
#include "fileio/image.hpp"

Texture2d::Texture2d(const std::string filename) {
        glBindTexture(GL_TEXTURE_2D, *texture);

        auto image = loadImageFile(filename);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getX(), image.getY(), 0,
                     GL_RGBA, GL_UNSIGNED_BYTE, image.get());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}
