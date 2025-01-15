#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "Logic.h"

class Renderer {
public:
    sf::Font font;
    sf::Text scoreText;

    Renderer();
    void render(sf::RenderWindow& window, Logic& logic, int blockSize);

    
};
/*void Renderer::render(sf::RenderWindow& window, Logic& logic, int blockSize) {
        window.clear(sf::Color::Black);

        // Access snake via getter
        for (const auto& segment : logic.getSnake()) {
            sf::RectangleShape block(sf::Vector2f(static_cast<float>(blockSize), static_cast<float>(blockSize)));
            block.setPosition(static_cast<float>(segment.x) * blockSize, static_cast<float>(segment.y) * blockSize);
            block.setFillColor(sf::Color::Green);
            window.draw(block);
        }

        // Access apple via getter
        sf::RectangleShape appleShape(sf::Vector2f(static_cast<float>(blockSize), static_cast<float>(blockSize)));
        appleShape.setPosition(static_cast<float>(logic.getApple().x) * blockSize, static_cast<float>(logic.getApple().y) * blockSize);
        appleShape.setFillColor(sf::Color::Yellow);
        window.draw(appleShape);

        // Access score and height via getters
        scoreText.setString("Score: " + std::to_string(logic.getScore()));
        scoreText.setPosition(10, static_cast<float>(logic.getHeight()) * blockSize);
        window.draw(scoreText);

        window.display();
    }*/

#endif
