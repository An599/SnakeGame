#include <cstdlib> 
#include <utility>
#include <iostream>
#include <deque>
#include "Logic.h"
#include "Fruit.h"
#include "Body.h"
#include "Renderer.h"
#include "GameController.h"
#include "SFML/Graphics.hpp"
using namespace std;

/*void menu() {
	cout << "Game Menu" << endl;
	cout << "1. Start Game" << endl;
	cout << "2. Go Back" << endl;
}
*/

/*menu();
int choice = 0;
cin >> choice;

while (1) {
	switch (choice){
	case 1:
	{
		void create();
		return 0;
	}
		case 2:
			exit(1);
	}

}*/



/*struct Fruit {
	int x;
	int y;
	Fruit(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
};
Fruit genFruit(int width, int height, const deque<SnakeBody>& snake) {
	bool valid_position = false;
	Fruit apple(0, 0);

	while (!valid_position) {
		apple.x = rand() % (width - 2) + 1;
		apple.y = rand() % (height - 2) + 1;

		valid_position = true;

		for (const auto& element : snake) {
			if (apple.x == element.x && apple.y == element.y) {
				valid_position = false;
				break;
			}
		}
	}
	return apple;
}*/




/*static void field(int width, int height, std::deque<SnakeBody>& snake, const Fruit& apple) {
	system("cls");
	for (int j = 0; j < width - 1; j++)
		std::cout << "--";
	std::cout << "-" << std::endl;

	for (int i = 1; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (j == 0 || j == width - 1) {
				std::cout << "| ";
			}
			else {
				bool isBody = false;
				for (const auto& el : snake) {
					if (el.x == j && el.y == i) {
						isBody = true;
						break;
					}
				}
				if (isBody) {
					std::cout << "[]";
				}
				else if (apple.x == j && apple.y == i) {
					std::cout << "##";
				}
				else {
					std::cout << "  ";
				}
			}
		}
		std::cout << std::endl;
	}
	for (int j = 0; j < width - 1; j++)
		std::cout << "--";
	std::cout << "-" << std::endl;
}*/

/*char moveDir(char current_dir) {
	if (_kbhit()) {
		char move_to = _getch();
		switch (move_to) {
		case 'w':
			if (current_dir != 's')
				return 'w';
			break;

		}
		case 's':
		{
			if (current_dir != 'w')
				return 's';
			break;
		}
		case 'a':
		{
			if (current_dir != 'd')
				return 'a';
			break;
		}
		case 'd':
		{
			if (current_dir != 'a')
				return 'd';
			break;
		}

		}
	}
	return current_dir;
}*/





/*int main() {
	srand(static_cast<unsigned>(time(0)));
	int width = 25;
	int height = 12;
	const int blockSize = 20;
	bool eaten = false;
	int k = 1;
	bool redFruitActive = false;
	int score = 0;

	sf::RenderWindow window(sf::VideoMode(width * blockSize, height * blockSize), "Snake Game");
	window.setFramerateLimit(10);

	std::deque<SnakeBody> snake;
	snake.push_back(SnakeBody(width / 2, height - 1));
	Fruit apple = genFruit(width, height, snake);

	char direction = 'd';

	sf::Clock clock;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear(sf::Color::Black);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && direction != 's' || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction != 's' && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) direction = 'w';
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && direction != 'w' || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction != 'w' && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) direction = 's';
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && direction != 'd' || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction != 'd' && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) direction = 'a';
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && direction != 'a' || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != 'a' && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) direction = 'd';

		SnakeBody head = snake.front();


		if (k ==  5) {
			sf::Time elapsed = clock.getElapsedTime();
			//cout << elapsed.asSeconds() << endl;
			if (elapsed.asSeconds() < 2.5) {
				redFruitActive = true;
				sf::CircleShape fruitBlock1(static_cast<float>(blockSize) / 2);
				fruitBlock1.setOrigin(fruitBlock1.getRadius(), fruitBlock1.getRadius());
				fruitBlock1.setPosition(static_cast<float>(apple.x) * blockSize + blockSize / 2, static_cast<float>(apple.y) * blockSize + blockSize / 2);
				fruitBlock1.setFillColor(sf::Color::Red);
				window.draw(fruitBlock1);
			}
			else {
				redFruitActive = false;
				k = 0;
			}
		}
		else {
			sf::RectangleShape fruitBlock2(sf::Vector2f(static_cast<float>(blockSize), static_cast<float>(blockSize)));
			fruitBlock2.setPosition(static_cast<float>(apple.x) * blockSize, static_cast<float>(apple.y) * blockSize);
			fruitBlock2.setFillColor(sf::Color::Yellow);
			window.draw(fruitBlock2);
		}
		
		

		switch (direction) {
		case 'w':
		{
			head.y--;
			break;
		}
		case 's':
		{
			head.y++;
			break;
		}
		case 'a':
		{
			head.x--;
			break;
		}
		case 'd':
		{
			head.x++;
			break;
		}

		}

		snake.push_front(head);

		for (auto i = snake.begin() + 1; i != snake.end(); ++i) {
			if ((i->y != 1 || i->y != 25) && (i->x != 1 || i->y != 12) && head.x == i->x && head.y == i->y) {
				cout << "GAME OVER" << endl;
				window.close();
			}
		}
		if (head.x == apple.x && head.y == apple.y)
		{
			if (redFruitActive == true)
			{
				score += 10;
			}
			else {
				score += 2;
			}
			cout << "Current Score=" << score << endl;
			apple = genFruit(width, height, snake);
			k++;
			clock.restart();
		}
		else { snake.pop_back(); }

		for (const auto& segment : snake) {
			sf::RectangleShape block(sf::Vector2f(static_cast<float>(blockSize), static_cast<float>(blockSize)));
			block.setPosition(static_cast<float>(segment.x * blockSize), static_cast<float>(segment.y * blockSize));
			block.setFillColor(sf::Color::Green);
			window.draw(block);
		}



		if (head.x == 25 && direction == 'd')
		{
			snake.push_front(SnakeBody(0, head.y));
		}
		if (head.x == 1 && direction == 'a')
		{
			snake.push_front(SnakeBody(24, head.y));
		}
		if (head.y == 1 && direction == 'w')
		{
			snake.push_front(SnakeBody(head.x, 11));
		}
		if (head.y == 12 && direction == 's')
		{
			snake.push_front(SnakeBody(head.x, 0));
		}

		window.display();
		std::string filenamse = "Records";

	}
	return 0;
}
*/

Logic::Logic(int w, int h) : width(w), height(h), score(0), k(1), redFruitActive(false), direction('d') {
	snake.push_back(SnakeBody(width / 2, height - 1));
	apple = Fruit::genFruit(width, height, snake);
}

void Logic::updateGame() {
	SnakeBody head = snake.front();

	switch (direction) {
	case 'w': head.y--; break;
	case 's': head.y++; break;
	case 'a': head.x--; break;
	case 'd': head.x++; break;
	}

	snake.push_front(head);

	if (head.x == apple.x && head.y == apple.y) {
		score += redFruitActive ? 10 : 2;
		apple = Fruit::genFruit(width, height, snake);
		k++;
		redFruitActive = (k % 5 == 0);
	}
	else {
		snake.pop_back();
	}

	handleCollision();
	wrapSnake();
}

void Logic::handleCollision() {
	SnakeBody head = snake.front();
	for (auto it = snake.begin() + 1; it != snake.end(); ++it) {
		if (head.x == it->x && head.y == it->y) {
			std::cout << "GAME OVER" << std::endl;
			exit(0);
		}
	}
}

void Logic::wrapSnake() {
	SnakeBody head = snake.front();
	if (head.x < 0) head.x = width - 1;
	else if (head.x >= width) head.x = 0;
	if (head.y < 0) head.y = height - 1;
	else if (head.y >= height) head.y = 0;

	snake.front() = head;
}

void Logic::run() {
	sf::RenderWindow window(sf::VideoMode(width * blockSize, (height + 1) * blockSize), "Snake Game");

	// Create instances of the Renderer and Logic (Model) classes
	Renderer renderer;

	// Game Loop
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close(); // Close the window when the event is closed
			}
		}

		// Handle user input (Controller)
		GameController::handleInput();

		// Update game state (Model)
		updateGame();

		// Render the updated state to the window (View)
		renderer.render(window, *this, blockSize);  // Pass the Logic as 'this'

		// Limit frame rate to 10 FPS (for the snake game)
		window.setFramerateLimit(10);
	}
}
