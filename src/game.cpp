#include "./include/game.h"

Game::Game(float x, float y) : m_screenX(x), m_screenY(y),
  m_player({580.0f, 720.0f}, "graphics/player.png"),
  m_rip({600.0f, 860.0f}, "graphics/rip.png"),
  m_axe({700.0f, 830.0f}, "graphics/axe.png"),
  m_log({810.0f, 720.0f}, "graphics/log.png") {
  std::cout << "Game initialised" << std::endl;
  std::cout << "Screen X: " << m_screenX << " Screen Y: " << m_screenY << std::endl;
  m_textureBackground->loadFromFile("graphics/background.png");
  m_spriteBackground->setTexture(*m_textureBackground);
  m_spriteBackground->setPosition(0, 0);

  // TimeBar
  m_timeBar.setSize(sf::Vector2f(TIMEBAR_START_WIDTH, TIMEBAR_HEIGHT));
  m_timeBar.setFillColor(sf::Color::Red);
  m_timeBar.setPosition((m_screenX/2) - TIMEBAR_START_WIDTH/2, 980);
}

void Game::init() {
  // Init clouds
  for(std::size_t i = 0; i < NO_OF_CLOUDS; i++) {
    // Create cloud with default x and y coordinates.
    Cloud cloud({0.0f, static_cast<float>((i)*250)}, "graphics/cloud.png");
    m_clouds.emplace_back(std::move(cloud));
  }
  // Init trees
  for(std::size_t i = 0; i < NO_OF_TREES; i++) {
    // Create tree with default x and y coordinates.
    Tree tree({static_cast<float>((i)*810), 0.0f}, "graphics/tree.png");
    m_trees.emplace_back(std::move(tree));
  }

  // Set the texture for each branch sprite
  for(std::size_t i = 0; i < NO_OF_BRANCHES; i++) {
    Branches branch({-2000.0f, -2000.0f}, "graphics/branch.png");
    m_branches.emplace_back(std::move(branch));
  }

  // Init trees
  for(std::size_t i = 0; i < NO_OF_BEES; i++) {
    // Create cloud with default x and y coordinates.
    float x = 0.0f;
    float y = static_cast<float>((i)*150);
    Bee bee({x, y}, "graphics/bee.png");
    m_bees.emplace_back(std::move(bee));
  }
}

void Game::Run(sf::RenderWindow &window, Controller &controller) {
  // Initialize all sprites and textures.
  init();

  while (window.isOpen()) {
    /* 
    *********************************************************
    Handle user input
    *********************************************************
    */
		controller.HandleInput(window, m_event, m_paused, m_acceptInput);

    /* 
    *********************************************************
    Update game scene
    *********************************************************
    */
    move();
    
    // Clear everything from the last frame
		window.clear();

    /* 
    *********************************************************
    Draw the game scene
    *********************************************************
    */
    // Call the draw function to draw all entities
    draw(window);

    window.display();
  }
}

void Game::move() {
  if (!m_paused) {
    // Measure the time that has elapsed since the clock started
    sf::Time dt = m_clock.restart();
    // // Substract from the amount of time remaining
    // timeRemaining -= dt.asSeconds();
    // // Set up the time bar
    // timeBar.setSize(sf::Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));

    // if (timeRemaining <= 0.0f) {
    //   // Pause the game.
    //   m_paused = true;
    // }
    // // Move bees
    for(Bee &bee : m_bees) {
      float index = static_cast<float>(&bee - &m_bees[0]);
      float timeElapsed = dt.asSeconds() + (index / 10000);
      bee.Move(index, timeElapsed);
    }
    // Move Cloud
    for(Cloud &cloud : m_clouds) {
      float index = static_cast<float>(&cloud - &m_clouds[0]);
      // float timeElapsed = dt.asSeconds() + (index / 10000);
      cloud.Move(index, dt.asSeconds());
    }
  }
}

void Game::draw(sf::RenderWindow &window) {
  // Draw the sprite
  window.draw(*m_spriteBackground);

  // Draw all cloud sprites
  for(const Cloud &cloud : m_clouds) {
    window.draw(*cloud.getSprite());
  }
  // Draw all tree sprites
  for(const Tree &tree : m_trees) {
    window.draw(*tree.getSprite());
  }
  // Draw all branches sprites
  for(const Branches &branches : m_branches) {
    window.draw(*branches.getSprite());
  }

  // Draw player sprite
  window.draw(*m_player.getSprite());
  // Draw rip sprite
  window.draw(*m_rip.getSprite());
  // Draw axe sprite
  window.draw(*m_axe.getSprite());
  // Draw log sprite
  window.draw(*m_log.getSprite());

  // Draw all bee sprites
  for(const Bee &bee : m_bees) {
    window.draw(*bee.getSprite());
  }
  
  // Draw the time bar
  window.draw(m_timeBar);
}