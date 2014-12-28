#include <array>
#include <vector>
#include "Graphics/Graphics.hpp"
#include "Graphics/Texture2d.hpp"

class Bullet {
public:
        std::array<float, 2> position;
        std::array<float, 2> velocity;
        bool update();
};

class BulletArray {
private:
        Texture2d bulletTexture{"./bullet.png"};
        std::vector<Bullet> bulletArray;
        float angle = 0.f;
        void deleteBullet(decltype(bulletArray)::iterator);
public:
        void render(Graphics& graphics);
        void update();
        BulletArray();
};
