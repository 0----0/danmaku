#include "image.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void ImageFile::deleter::operator()(unsigned char* ptr) {
        stbi_image_free(ptr);
}

ImageFile loadImageFile(const std::string filename) {
        ImageFile retVal;
        retVal.imagePtr = std::unique_ptr<unsigned char, ImageFile::deleter>{
                stbi_load(filename.c_str(), &retVal.x, &retVal.y, nullptr, 4)};
        if(!retVal.imagePtr) {
                throw ImageLoadException(filename);
        }
        return retVal;
}
