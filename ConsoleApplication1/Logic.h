#ifndef LOGIC_H
#define LOGIC_H

#include <deque>
#include <SFML/Graphics.hpp>
#include "Coordinates.h"
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
    sf::Clock clk;

    
    void wrapSnake();

public:
    const std::deque<SnakeBody>& getSnake() const { return snake; }
    const Fruit& getApple() const { return apple; }
    int getScore() const { return score; }
    int getHeight() const { return height; }
    int getWidth() const { return width; }
    int getRedFruitActive() const { return redFruitActive; }
    int getDirection() const { return direction; }
    void setDirection(char d) { direction = d; }
    void updateGame();
    void selfCollision();

    Logic(int width, int height, int blockSize);
   
};

#endif 
