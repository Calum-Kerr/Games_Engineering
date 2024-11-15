
#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    void handleInput();
    void update(float gravity, float floorLevel);
    void draw(sf::RenderWindow& window);

private:
    sf::Sprite sprite;
    sf::Texture runTexture;
    sf::Texture jumpTexture;
    sf::IntRect currentFrame;
    float velocityY;
    float velocityX;
    bool isJumping;
    int frameCounter;
    int frameSpeed;
    int frameCount;
    int jumpFrameCount;
	int jumpFrameSpeed;
    int jumpFrameCounter;
};

#endif // PLAYER_H