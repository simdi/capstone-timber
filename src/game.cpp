#include "./include/game.h"
#include "./include/tree.h"
#include "./include/bee.h"

Game::Game() {
  std::cout << "Game initialised" << std::endl;
  m_textureBackground->loadFromFile("graphics/background.png");
  m_spriteBackground->setTexture(*m_textureBackground);
  m_spriteBackground->setPosition(0, 0);
}

void Game::Run(sf::RenderWindow &window, Controller &controller, std::size_t clouds, std::size_t trees, std::size_t bees) {
  std::cout << "No of trees: " << trees << std::endl;
  // Init clouds
  for(std::size_t i = 0; i < clouds; i++) {
    // Create cloud with default x and y coordinates.
    Cloud cloud({0.0f, static_cast<float>((i)*250)}, "graphics/cloud.png");
    m_clouds.emplace_back(cloud);
  }
  // Init trees
  for(std::size_t i = 0; i < trees; i++) {
    // Create cloud with default x and y coordinates.
    Tree tree({static_cast<float>((i)*810), static_cast<float>((i)*5)}, "graphics/tree.png");
    m_trees.emplace_back(tree);
  }

  // Init trees
  for(std::size_t i = 0; i < bees; i++) {
    // Create cloud with default x and y coordinates.
    Bee bee({0.0f, static_cast<float>((i)*150)}, "graphics/bee.png");
    m_bees.emplace_back(bee);
  }
  // Track weather the game is running
  bool paused{true};
  // Control player input
  bool acceptInput{false};

  sf::Event event;
  while (window.isOpen()) {
    /* 
    *********************************************************
    Handle user input
    *********************************************************
    */
		controller.HandleInput(window, event, paused, acceptInput);

    // Clear everything from the last frame
		window.clear();

    // Draw the sprite
    window.draw(*m_spriteBackground);

    // Draw all tree sprites
    for(const Tree &tree : m_trees) {
      window.draw(*tree.getSprite());
    }
    // Draw all cloud sprites
    for(const Cloud &cloud : m_clouds) {
      window.draw(*cloud.getSprite());
    }
    // Draw all bee sprites
    for(const Bee &bee : m_bees) {
      window.draw(*bee.getSprite());
    }

    window.display();
  }
}