#include "./include/controller.h"

Controller::Controller() {
  std::cout << "Controller has been initialised" << std::endl;
}

void Controller::HandleInput(sf::Window &window, sf::Event &event, bool paused, bool acceptInput) {
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window.close();

    if (event.type == sf::Event::KeyReleased && !paused) {
      // Listen for key pressed again
      acceptInput = true;

      // Hide the axe
      // spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
    }
  }
}