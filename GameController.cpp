#include "GameController.h"

GameController::GameController(int w, int h, int block)
    : logic(w, h), blockSize(block),
    window(sf::VideoMode(w* block, h* block), "Snake Game") {
    window.setFramerateLimit(10);
}

static void GameController::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && logic.direction != 's') logic.direction = 'w';
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && logic.direction != 'w') logic.direction = 's';
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && logic.direction != 'd') logic.direction = 'a';
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && logic.direction != 'a') logic.direction = 'd';
}

void GameController::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        handleInput();
        logic.updateGame();
        renderer.render(window, logic, blockSize);
    }
}
