#ifndef LOGIC_H
#define LOGIC_H

#include <deque>
#include <SFML/Graphics.hpp>
#include "Body.h"
#include "Fruit.h"

class Logic {
private:
    int width;
    int height;
    int score;
    int k;
    bool redFruitActive;
    int blockSize;
    char direction;
    std::deque<SnakeBody> snake;
    Fruit apple;

    

    void updateGame();
    void wrapSnake();
    void handleCollision();

public:
    //Getter
    Logic(int w, int h);
    const std::deque<SnakeBody>& getSnake() const { return snake; }
    const Fruit& getApple() const { return apple; }
    int getScore() const { return score; }
    int getHeight() const { return height; }

    Logic(int width, int height, int blockSize);
    void run();
};

#endif 
