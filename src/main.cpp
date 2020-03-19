#include <sstream>
#include "Platform/PlatformHelper.hpp"

#include "./include/game.h"

int main() {
	PlatformHelper platform;
  sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
  float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
  float screenX{1920.0f * screenScalingFactor};
  float screenY{1080.0f * screenScalingFactor};
  sf::VideoMode vm(screenX, screenY);

	window.create(vm, "Timber!!!");
	platform.setIcon(window.getSystemHandle());

  // Initialise Controller
  Controller controller;
  // Initialise game.
  Game game(screenX, screenY);
  game.Run(window, controller);

	return 0;
}