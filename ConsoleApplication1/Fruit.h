#ifndef FRUIT_H
#define FRUIT_H

#include <deque>
#include "Coordinates.h"

class Fruit {
public:
    int x, y;
    Fruit();
    Fruit(int xCoord, int yCoord);
    static Fruit genFruit(int width, int height, const std::deque<SnakeBody>& snake);
};

#endif // FRUIT_H
