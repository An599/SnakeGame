#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu {
public:
    Menu(int , int );
    void draw(sf::RenderWindow& );
    void moveUp();
    void moveDown();
    int getSelectedOption() const;

private:
    int selectedOption;
    sf::Font font;
    std::vector<sf::Text> options;
};

#endif