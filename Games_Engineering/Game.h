#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class Game {
public:
    Game();
    void run();
    float getFloorLevel() const; // Add this method

private:
    void processEvents();
    void update();
    void render();
    sf::RenderWindow window;
    Player player;
    sf::RectangleShape floor;
    float gravity;
};

#endif // GAME_H