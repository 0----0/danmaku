#include <array>
#include "Graphics/Texture2d.hpp"
#include "Graphics/Graphics.hpp"

class Player {
private:
        std::array<float, 2> position;
        Texture2d texture;
public:
        Player():
                position({{200.f, 200.f}}),
                texture("./knight.png") {}
        void render(Graphics& graphics) {
                texture.setActive();
                graphics.setTransform(position, {{64.f, 64.f}});
                graphics.draw();
        }
};
