#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "./include/controller.h"
#include "./include/cloud.h"
#include "./include/tree.h"
#include "./include/bee.h"
#include "./include/player.h"
#include "./include/rip.h"
#include "./include/axe.h"
#include "./include/log.h"
#include "./include/branches.h"

class Game {
private:
  std::unique_ptr<sf::Sprite> m_spriteBackground = std::make_unique<sf::Sprite>();
  std::unique_ptr<sf::Texture> m_textureBackground = std::make_unique<sf::Texture>();
  std::vector<Cloud> m_clouds;
  std::vector<Bee> m_bees;
  std::vector<Tree> m_trees;
  std::vector<Branches> m_branches;
  float m_screenX;
  float m_screenY;
  Player m_player;
  Rip m_rip;
  Axe m_axe;
  Log m_log;
  sf::Event m_event;
  sf::Clock m_clock;
  sf::RectangleShape m_timeBar;
  static constexpr float TIMEBAR_START_WIDTH{400.0f};
  static constexpr float TIMEBAR_HEIGHT{80};
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
  static constexpr std::size_t NO_OF_BRANCHES{6};
  enum side { LEFT, RIGHT, NONE };
  // side branchPositions[NO_OF_BRANCHES];

public:
  Game(float x, float y);
  void Run(sf::RenderWindow &window, Controller &controller);
};

#endif