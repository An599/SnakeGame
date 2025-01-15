#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Logic.h"

class Renderer {
public:
    sf::Font font;
    sf::Text scoreText;
    int blockSize;

    Renderer();
    void render(sf::RenderWindow& window, Logic& logic, int blockSize);
    void renderMenu(sf::RenderWindow& , Menu&);

    
};


#endif
