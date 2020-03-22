#include <sstream>
#include <memory>

#include "./include/game.h"

int main() {
  float screenX{1920.0f};
  float screenY{1080.0f};
  sf::VideoMode vm(screenX, screenY);
  sf::RenderWindow window(vm, "Timber!!!");

  // Initialise game.
  std::unique_ptr<Game> game = std::make_unique<Game>(screenX, screenY);
  game->Run(window);

	return 0;
}