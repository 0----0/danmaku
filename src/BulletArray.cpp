#include "BulletArray.hpp"
#include <cmath>

bool Bullet::update() {
        position[0] += velocity[0];
        position[1] += velocity[1];
        return position[0] > 800.f || position[1] > 600.f || position[0] < 0.f || position[1] < 0.f;
        // return 0;
}

inline void BulletArray::deleteBullet(decltype(bulletArray)::iterator iter) {
        *iter = bulletArray.back();
        bulletArray.pop_back();
}

// void BulletArray::update() {
//         // static float angle = 0.f;
//         // float velx = cos(angle) * 2.f;
//         // float vely = sin(angle) * 2.f;
//         // angle += 0.1f;
//         // bulletArray.push_back({{{400.f, 300.f}}, {{velx, vely}}});
//         for(float angle = 0.f; angle < 1.f; angle += 0.001f) {
//                 float velx = cos(angle*2*M_PI) * 2.f;
//                 float vely = sin(angle*2*M_PI) * 2.f;
//                 bulletArray.push_back({{{400.f, 300.f}}, {{velx, vely}}});
//         }
//         for(auto bullet = bulletArray.begin(); bullet != bulletArray.end(); bullet++) {
//                 bool del = bullet->update();
//                 if(del) {
//                         deleteBullet(bullet);
//                         bullet--;
//                 }
//         }
// }

// void BulletArray::render(Graphics& graphics) {
//         bulletTexture.setActive();
//         for(auto &bullet : bulletArray) {
//                 graphics.setTransform(bullet.position, {{16.f, 16.f}});
//                 graphics.draw();
//         }
// }

void BulletArray::render(Graphics& graphics) {
        bulletTexture.setActive();
        auto vel = [](const float angle) {
                float velx = cos(angle*2*M_PI) * 1.5f;
                float vely = sin(angle*2*M_PI) * 1.5f;
                return std::array<float,2>{{velx, vely}};
        };
        angle += 0.02f;
        if(angle > 1.f) angle -= 1.f;
        bulletArray.push_back({{{400.f, 300.f}}, vel(angle)});
        bulletArray.push_back({{{400.f, 300.f}}, vel(angle + 0.25f)});
        bulletArray.push_back({{{400.f, 300.f}}, vel(angle + 0.5f)});
        bulletArray.push_back({{{400.f, 300.f}}, vel(angle - 0.25f)});
        for(auto bullet = bulletArray.begin(); bullet != bulletArray.end(); bullet++) {
                bool del = bullet->update();
                if(del) {
                        deleteBullet(bullet);
                        bullet--;
                }
                else {
                        graphics.setTransform(bullet->position, {{16.f, 16.f}});
                        graphics.draw();
                }
        }
}

BulletArray::BulletArray() {
}
