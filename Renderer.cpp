#include "Logic.h"
#include "Renderer.h"


Renderer::Renderer() {
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        throw std::runtime_error("Failed to load font");
    }
    scoreText.setFont(font);
    scoreText.setCharacterSize(15);
    scoreText.setFillColor(sf::Color::White);
}

void Renderer::render(sf::RenderWindow& window, Logic& logic, int blockSize) {
    window.clear(sf::Color::Black);

    // Render snake
    for (const auto& segment : logic.getSnake()) { // Use getter function
        sf::RectangleShape block(sf::Vector2f(static_cast<float>(blockSize), static_cast<float>(blockSize)));
        block.setPosition(static_cast<float>(segment.x) * blockSize, static_cast<float>(segment.y) * blockSize);
        block.setFillColor(sf::Color::Green);
        window.draw(block);
    }

    // Render apple
    sf::RectangleShape appleShape(sf::Vector2f(static_cast<float>(blockSize), static_cast<float>(blockSize)));
    appleShape.setPosition(static_cast<float>(logic.getApple().x) * blockSize, static_cast<float>(logic.getApple().y) * blockSize);
    appleShape.setFillColor(sf::Color::Yellow);
    window.draw(appleShape);

    // Render score
    scoreText.setString("Score: " + std::to_string(logic.getScore()));
    scoreText.setPosition(10, static_cast<float>(logic.getHeight()) * blockSize);
    window.draw(scoreText);

    window.display();
}

