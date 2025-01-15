#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Logic.h"
#include "Renderer.h"

class GameController {
public:
    Logic logic;
    Renderer renderer;
    sf::RenderWindow window;
    int blockSize;

    GameController(int w, int h, int block);

    static void handleInput();
    void run();
};

#endif
