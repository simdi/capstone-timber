#include <sstream>

#include "./include/game.h"

int main() {
  float screenX{1920.0f};
  float screenY{1080.0f};
  sf::VideoMode vm(screenX, screenY);
  sf::RenderWindow window(vm, "Timber!!!");

  // Initialise game.
  Game game(screenX, screenY);
  game.Run(window);

	return 0;
}