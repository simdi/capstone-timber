#include <sstream>
#include "Platform/PlatformHelper.hpp"

#include "./include/game.h"

int main() {
	PlatformHelper platform;
  sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
  float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
  sf::VideoMode vm(1920.0f * screenScalingFactor, 1080.0f * screenScalingFactor);

	window.create(vm, "Timber!!!");
	platform.setIcon(window.getSystemHandle());

  constexpr std::size_t noOfClouds{3};
  constexpr std::size_t noOfTrees{3};
  constexpr std::size_t noOfBees{3};

  // Initialise Controller
  Controller controller;
  // Initialise game.
  Game game;
  game.Run(window, controller, noOfClouds, noOfTrees, noOfBees);

	return 0;
}