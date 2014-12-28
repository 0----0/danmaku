#include <memory>

class ImageLoadException : public std::exception {
private:
        const std::string error;
public:
        virtual const char* what() const noexcept override {
                return error.c_str();
        }
        ImageLoadException(const std::string filename):
                error("Error loading image file: " + filename) {}
};

class ImageFile {
private:
        struct deleter { void operator()(unsigned char* ptr); };
        int x, y;
        std::unique_ptr<unsigned char, deleter> imagePtr;
        ImageFile() { }
public:
        auto getX() const { return x; }
        auto getY() const { return y; }
        auto get() const { return imagePtr.get(); }
        friend ImageFile loadImageFile(const std::string filename);
};

ImageFile loadImageFile(const std::string filename);
