#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <sstream>

#include "./cloud.h"
#include "./tree.h"
#include "./bee.h"
#include "./player.h"
#include "./rip.h"
#include "./axe.h"
#include "./log.h"
#include "./branches.h"

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
  sf::Font m_font;
  sf::Color m_textColor{sf::Color::White};
  int m_score{0};
  sf::Text m_messageText;
  sf::Text m_scoreText;
  sf::RectangleShape m_timeBar;
  sf::Time m_gameTimeTotal;
  float m_timeRemaining{6.0f};
  static constexpr float TIMEBAR_START_WIDTH{400.0f};
  static constexpr float TIMEBAR_HEIGHT{80};
  float m_timeBarWidthPerSecond{TIMEBAR_START_WIDTH/m_timeRemaining};
  // Track weather the game is running
  bool m_paused{true};
  // Control player input
  bool m_acceptInput{false};
  void init();
  void move();
  void handleInput(sf::Window &window);
  void draw(sf::RenderWindow &window);
  void setMessageText(std::string text);
  void updateBranches(int seed);
  static constexpr std::size_t NO_OF_CLOUDS{3};
  static constexpr std::size_t NO_OF_TREES{3};
  static constexpr std::size_t NO_OF_BEES{3};
  static constexpr std::size_t NO_OF_BRANCHES{6};
  enum side { LEFT, RIGHT, NONE };
  side m_branchPositions[NO_OF_BRANCHES];
  side m_playerSide = side::LEFT;
  // Prepare sound
  // Chop buffer
  sf::SoundBuffer m_chopBuffer;
  sf::Sound m_chop;
  // Death Buffer
  sf::SoundBuffer m_deathBuffer;
  sf::Sound m_death;
  // Out of time Buffer
  sf::SoundBuffer m_ootBuffer;
  sf::Sound m_outOfTime;

public:
  Game(float x, float y);
  void Run(sf::RenderWindow &window);
};

#endif