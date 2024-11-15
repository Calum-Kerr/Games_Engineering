#include "Game.h"

Game::Game() : window(sf::VideoMode::getDesktopMode(), "SFML works!"), gravity(2.f) {
    floor.setSize(sf::Vector2f(window.getSize().x, 50.f));
    floor.setFillColor(sf::Color::Red);
    floor.setPosition(0.f, window.getSize().y - 50.f);
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

float Game::getFloorLevel() const {
    return floor.getPosition().y;
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
    player.handleInput();
}

void Game::update() {
    player.update(gravity, getFloorLevel());
}

void Game::render() {
    window.clear();
    window.draw(floor);
    player.draw(window);
    window.display();
}