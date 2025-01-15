#include "Logic.h"
#include "Menu.h"
#include "GameController.h"

int main() {
    GameController gc(25, 12, 20);
    gc.run();
    return 0;
}
