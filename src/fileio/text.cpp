#include "text.hpp"
#include <fstream>

std::string loadTextFile(const std::string filename) {
        std::ifstream file(filename, std::ios::in | std::ios::binary);
        std::string contents;
        file.seekg(0, std::ios::end);
        contents.resize(file.tellg());
        file.seekg(0, std::ios::beg);
        file.read(&contents[0], contents.size());
        file.close();
        return(contents);
}
