#include "./include/game.h"

Game::Game() {
  std::cout << "Game initialised" << std::endl;
  m_textureBackground->loadFromFile("graphics/background.png");
  m_spriteBackground->setTexture(*m_textureBackground);
  m_spriteBackground->setPosition(0, 0);
}

void Game::Run(sf::RenderWindow &window, Controller &controller, std::size_t clouds, std::size_t trees) {
  std::cout << "No of trees: " << trees << std::endl;
  // Init clouds
  for(std::size_t i = 0; i < clouds; i++) {
    // Create cloud with default x and y coordinates.
    // sf::Vector2f cords{0.0f, 0.0f};
    Cloud cloud({0.0f, static_cast<float>((i)*250)}, "graphics/cloud.png");
    m_clouds.emplace_back(cloud);
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

    // Draw all cloud sprites
    for(const Cloud &cloud : m_clouds) {
      window.draw(*cloud.getSprite());
    }

    window.display();
  }
}