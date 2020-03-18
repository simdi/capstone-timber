#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "./include/controller.h"
#include "./include/cloud.h"

class Game {
private:
  std::unique_ptr<sf::Sprite> m_spriteBackground = std::make_unique<sf::Sprite>();
  std::unique_ptr<sf::Texture> m_textureBackground = std::make_unique<sf::Texture>();
  std::vector<Cloud> m_clouds;

public:
  Game();
  void Run(sf::RenderWindow &window, Controller &controller, std::size_t clouds, std::size_t trees);
};

#endif