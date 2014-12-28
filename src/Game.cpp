#include "Game.hpp"
#include <chrono>
#include <thread>
#include <iostream>

auto getStart() {
        return std::chrono::steady_clock::now();
}

template<typename T>
void wait(T start) {
        const auto end = std::chrono::steady_clock::now();
        const auto wait = start - end + std::chrono::microseconds(16666);
        if(wait.count() > 0) {
                std::this_thread::sleep_for(wait);
        }
}

void Game::update() {
        // bulletArray.update();
}

void Game::render() {
        graphics.clear();
        bulletArray.render(graphics);
        player.render(graphics);
}

void Game::mainLoop() {
        while(true) {
                const auto start = getStart();
                update();
                render();
                bool cont = graphics.processWindow();
                if(!cont) return;
                wait(start);
        }
}
