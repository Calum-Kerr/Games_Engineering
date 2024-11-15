#include "Player.h"

Player::Player() : velocityY(0.f), velocityX(0.3f), isJumping(false), frameCounter(0), jumpFrameCounter(0), frameSpeed(60), frameCount(7), jumpFrameCount(6), jumpFrameSpeed(120) {
    if (!runTexture.loadFromFile("Player_Sword_Run_48x48.png")) {
        // Handle error
    }
    if (!jumpTexture.loadFromFile("player_jump_left_48x48-sheet_1.png")) {
        // Handle error
    }
    sprite.setTexture(runTexture);
    currentFrame = sf::IntRect(0, 0, 48, 41); // Adjust the frame size as per your sprite sheet
    sprite.setTextureRect(currentFrame);
    sprite.setPosition(0.f, 902.f); // Initial position to touch the floor
}

void Player::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping) {
        velocityY = -10.f; // Adjusted for a slower jump
        isJumping = true;
        sprite.setTexture(jumpTexture);
        currentFrame = sf::IntRect(0, 0, 48, 41); // Reset to the first frame of the jump sprite
        sprite.setTextureRect(currentFrame);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sprite.move(-velocityX, 0.f);
        sprite.setScale(-1.f, 1.f); // Flip the sprite horizontally
        if (!isJumping) {
            frameCounter++;
            if (frameCounter >= frameSpeed) {
                frameCounter = 0;
                currentFrame.left += 48; // Move to the next frame
                if (currentFrame.left >= 48 * frameCount) {
                    currentFrame.left = 0; // Loop back to the first frame
                }
                sprite.setTextureRect(currentFrame);
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sprite.move(velocityX, 0.f);
        sprite.setScale(1.f, 1.f); // Reset the sprite to its original orientation
        if (!isJumping) {
            frameCounter++;
            if (frameCounter >= frameSpeed) {
                frameCounter = 0;
                currentFrame.left += 48; // Move to the next frame
                if (currentFrame.left >= 48 * frameCount) {
                    currentFrame.left = 0; // Loop back to the first frame
                }
                sprite.setTextureRect(currentFrame);
            }
        }
    }
}

void Player::update(float gravity, float floorLevel) {
    velocityY += gravity * 1.f; // Adjusted gravity effect for a slower jump
    sprite.move(0.f, velocityY);
    if (sprite.getPosition().y + sprite.getGlobalBounds().height >= floorLevel) {
        sprite.setPosition(sprite.getPosition().x, floorLevel - sprite.getGlobalBounds().height);
        velocityY = 0.f;
        isJumping = false;
        sprite.setTexture(runTexture); // Switch back to the run texture
        currentFrame = sf::IntRect(0, 0, 48, 41); // Reset to the first frame of the run sprite
        sprite.setTextureRect(currentFrame);
    }
    else if (isJumping) {
        jumpFrameCounter++;
        if (jumpFrameCounter >= jumpFrameSpeed) {
            jumpFrameCounter = 0;
            currentFrame.left += 48; // Move to the next frame
            if (currentFrame.left >= 48 * jumpFrameCount) {
                currentFrame.left = 0; // Loop back to the first frame
            }
            sprite.setTextureRect(currentFrame);
        }
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
