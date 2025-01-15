#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "SFML/Graphics.hpp"
#include "Logic.h"
#include "Renderer.h"


class GameController {
private:
    Menu menu;
    bool inMenu;
public:
    
    sf::RenderWindow window;
    int blockSize;
    Logic logic;
    Renderer renderer;

    GameController(int w, int h, int block);

    void handleInput();
    void run(); 
};

#endif
