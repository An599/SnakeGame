#include "GameController.h"
#include "Menu.h"
#include <iostream>

// Initialize the new variables in the constructor
GameController::GameController(int w, int h, int block)
    : logic(w, h, block), blockSize(block),
    window(sf::VideoMode(w* block, (h + 1)* block), "Snake Game"),
    menu(w * block, h * block), inMenu(true) {
    window.setFramerateLimit(15);
}

// Modify handleInput to include menu logic


void GameController::handleInput() {
    if (inMenu) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) menu.moveUp();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) menu.moveDown();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            if (menu.getSelectedOption() == 0) inMenu = false; // Start game
            if (menu.getSelectedOption() == 1) window.close(); // Exit
        }
    }
    else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && logic.getDirection() != 's' || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
            && logic.getDirection() != 's' && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) logic.setDirection('w');
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && logic.getDirection() != 'w' || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
            && logic.getDirection() != 'w' && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) logic.setDirection('s');
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && logic.getDirection() != 'd' || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
            && logic.getDirection() != 'd' && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) logic.setDirection('a');
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && logic.getDirection() != 'a' || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
            logic.getDirection() != 'a' && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) logic.setDirection('d');
    }
} 


//GameController::GameController(int w, int h, int block)
//    : logic(w, h, block), blockSize(block),
//    window(sf::VideoMode(w * block, (h + 1) * block), "Snake Game") {
//    window.setFramerateLimit(10);
//}

//void GameController::handleInput() {
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && logic.getDirection() != 's' || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
//        && logic.getDirection() != 's' && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
//        !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) logic.setDirection('w');
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && logic.getDirection() != 'w' || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
//        && logic.getDirection() != 'w' && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
//        !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) logic.setDirection('s') ;
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && logic.getDirection() != 'd' || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
//        && logic.getDirection() != 'd' && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
//        !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) logic.setDirection('a')  ;
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && logic.getDirection() != 'a' || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
//        logic.getDirection() != 'a' && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
//        !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) logic.setDirection('d') ;
//}

//void GameController::run() {
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) window.close();
//        }
//        handleInput();
//        logic.updateGame();
//        renderer.render(window, logic, blockSize);
//    }
//
//}
void GameController::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        handleInput();

        if (inMenu) {
            // Render the menu
            renderer.renderMenu(window, menu);
        }
        else {
            // Update and render the game
            logic.updateGame();
            renderer.render(window, logic, blockSize);
        }
    }
}
