#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "./include/controller.h"
#include "./include/cloud.h"
#include "./include/tree.h"
#include "./include/bee.h"
#include "./include/player.h"

class Game {
private:
  std::unique_ptr<sf::Sprite> m_spriteBackground = std::make_unique<sf::Sprite>();
  std::unique_ptr<sf::Texture> m_textureBackground = std::make_unique<sf::Texture>();
  std::vector<Cloud> m_clouds;
  std::vector<Bee> m_bees;
  std::vector<Tree> m_trees;
  Player m_player;
  sf::Event m_event;
  sf::Clock m_clock;
  // Track weather the game is running
  bool m_paused{true};
  // Control player input
  bool m_acceptInput{false};
  void init();
  void move();
  void draw(sf::RenderWindow &window);
  static constexpr std::size_t NO_OF_CLOUDS{3};
  static constexpr std::size_t NO_OF_TREES{3};
  static constexpr std::size_t NO_OF_BEES{3};

public:
  Game();
  void Run(sf::RenderWindow &window, Controller &controller);
};

#endif