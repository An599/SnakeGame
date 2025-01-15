#include "Menu.h"
#include <SFML/Graphics.hpp>

Menu::Menu(int width, int height) : selectedOption(0) {
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        throw std::runtime_error("Failed to load font");
    }

    std::vector<std::string> menuOptions = {"Start Game", "Exit"};
    for (size_t i = 0; i < menuOptions.size(); ++i) {
        sf::Text option;
        option.setFont(font);
        option.setString(menuOptions[i]);
        option.setCharacterSize(30);
        option.setFillColor(i == 0 ? sf::Color::Red : sf::Color::White);
        option.setPosition(width / 2 - 75, height / 2.5 + i * 35);
        options.push_back(option);
    }
}

void Menu::draw(sf::RenderWindow& window) {
    for (const auto& option : options) {
        window.draw(option);
    }
}

void Menu::moveUp() {
    if (selectedOption > 0) {
        options[selectedOption].setFillColor(sf::Color::White);
        selectedOption--;
        options[selectedOption].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown() {
    if (selectedOption < static_cast<int>(options.size()) - 1) {
        options[selectedOption].setFillColor(sf::Color::White);
        selectedOption++;
        options[selectedOption].setFillColor(sf::Color::Red);
    }
}

int Menu::getSelectedOption() const {
    return selectedOption;
}