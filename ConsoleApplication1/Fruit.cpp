#include "Fruit.h"
#include <cstdlib>

Fruit::Fruit(){
	x = 0;
	y = 0;
}

Fruit::Fruit(int xCoord, int yCoord) {
	x = xCoord;
	y = yCoord;
}

Fruit Fruit::genFruit(int width, int height, const std::deque<SnakeBody>& snake) {
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
}