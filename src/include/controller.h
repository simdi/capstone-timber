#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

struct Controller {
private:

public:
  Controller();
  void HandleInput(sf::Window &window, sf::Event &event, bool paused, bool accpetInput);
};

#endif