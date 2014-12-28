#include "Graphics/Graphics.hpp"
#include "Graphics/Texture2d.hpp"
#include "Player.hpp"
#include "BulletArray.hpp"

class Game {
private:
        Graphics graphics;
        Player player;
        BulletArray bulletArray;

        void update();
        void render();
public:
        void mainLoop();
};
