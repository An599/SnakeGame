#include "Logic.h"
#include "Menu.h"
#include "Renderer.h"
#include <iostream>>


void Renderer::renderMenu(sf::RenderWindow& window, Menu& menu) {
    window.clear(sf::Color::Black);
    menu.draw(window);
    window.display();
}


Renderer::Renderer() {
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        throw std::runtime_error("Failed to load font");
    }
}

void Renderer::render(sf::RenderWindow& window, Logic& logic, int blockSize) {
    window.clear(sf::Color::Black);

    scoreText.setFont(font);
    scoreText.setCharacterSize(15);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, logic.getHeight() * blockSize);

    
    //for (const auto& segment : logic.getSnake()) { 
    //    sf::RectangleShape block(sf::Vector2f(static_cast<float>(blockSize), static_cast<float>(blockSize)));
    //    block.setPosition(static_cast<float>(segment.x) * blockSize, static_cast<float>(segment.y) * blockSize);
    //    block.setFillColor(sf::Color::Green);
    //    window.draw(block);
    //}

   
    //sf::RectangleShape appleShape(sf::Vector2f(static_cast<float>(blockSize), static_cast<float>(blockSize)));
    //appleShape.setPosition(static_cast<float>(logic.getApple().x) * blockSize, static_cast<float>(logic.getApple().y) * blockSize);
    //appleShape.setFillColor(logic.getRedFruitActive()? sf::Color::Red : sf::Color::Yellow);
    //window.draw(appleShape);

    sf::CircleShape appleShape(static_cast<float>(blockSize) / 2.0f); // Set radius to half the blockSize
    appleShape.setPosition(
        static_cast<float>(logic.getApple().x) * blockSize , 
        static_cast<float>(logic.getApple().y) * blockSize 
    );
    appleShape.setFillColor(logic.getRedFruitActive() ? sf::Color::Red : sf::Color::Yellow);
    window.draw(appleShape);

    for (const auto& segment : logic.getSnake()) {
        sf::RectangleShape block(sf::Vector2f(static_cast<float>(blockSize), static_cast<float>(blockSize)));
        block.setPosition(static_cast<float>(segment.x) * blockSize, static_cast<float>(segment.y) * blockSize);
        block.setFillColor(sf::Color::Green);
        window.draw(block);
    }



    sf::RectangleShape border(sf::Vector2f(logic.getWidth() * blockSize, blockSize * 2)); 
    border.setPosition(0, logic.getHeight() * blockSize);
    border.setFillColor(sf::Color::Black); 
    border.setOutlineColor(sf::Color::White); 
    border.setOutlineThickness(2);
    window.draw(border);

    // Display the score within the border
    scoreText.setString("Score: " + std::to_string(logic.getScore()));
    window.draw(scoreText);

    window.display();
}

