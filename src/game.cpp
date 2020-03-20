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

  // Choose a font
  m_font.loadFromFile("fonts/KOMIKAP_.ttf");
  // Set font to the message
  m_messageText.setFont(m_font);
  m_scoreText.setFont(m_font);
  m_scoreText.setString("Score = 0");
  // Set the size
  m_messageText.setCharacterSize(55);
  m_scoreText.setCharacterSize(75);
  // Set color of the texts
  m_messageText.setFillColor(m_textColor);
  m_scoreText.setFillColor(m_textColor);
  // Assign the actual text
  setMessageText("Press Enter to start");
  // Position the texts
  m_scoreText.setPosition(20, 20);

  // Sounds
  m_ootBuffer.loadFromFile("sound/out_of_time.wav");
  m_deathBuffer.loadFromFile("sound/death.wav");
  m_chopBuffer.loadFromFile("sound/chop.wav");
  m_outOfTime.setBuffer(m_ootBuffer);
  m_death.setBuffer(m_deathBuffer);
  m_chop.setBuffer(m_chopBuffer);
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

void Game::Run(sf::RenderWindow &window) {
  // Initialize all sprites and textures.
  init();

  while (window.isOpen()) {
    /* 
    *********************************************************
    Handle user input
    *********************************************************
    */
    handleInput(window);
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

void Game::handleInput(sf::Window &window) {
  while (window.pollEvent(m_event)) {
    if (m_event.type == sf::Event::Closed)
      window.close();

    if (m_event.type == sf::Event::KeyReleased && !m_paused) {
      // Listen for key pressed again
      m_acceptInput = true;

      // Hide the axe
      (*m_axe.getSprite()).setPosition(2000, (*m_axe.getSprite()).getPosition().y);
    }
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
    m_paused = false;
    // Reset the time and the score
    m_score = 0;
    m_timeRemaining = 5;

    // Make all branches disappear
    for (std::size_t i = 1; i < NO_OF_BRANCHES; i++) {
      m_branchPositions[i] = side::NONE;
    }
    // Make sure the gravestone is hidden
    (*m_rip.getSprite()).setPosition(675, 2000);
    // Move player into position
    (*m_player.getSprite()).setPosition(580, 720);
    m_acceptInput = true;
  }

  // wrap the player control to make sure we are accepting user input
  if (m_acceptInput) {
    // Handle pressing the right cursor key
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      // Make sure the player is on the right
      m_playerSide = side::RIGHT;
      m_score++;

      // Add to the amount of time remaining
      m_timeRemaining += (2 / m_score) * .15;

      (*m_axe.getSprite()).setPosition(m_axe.PositionRight(), (*m_axe.getSprite()).getPosition().y);
      (*m_player.getSprite()).setPosition(1200, 720);

      // Update the branch
      updateBranches(m_score);

      // Set the log flying to the left
      (*m_log.getSprite()).setPosition(810, 720);
      m_log.SpeedX(-5000);
      m_log.IsActive(true);

      m_acceptInput = false;

      // Play sound
      m_chop.play();
    }

    // Handle pressing the left cursor key
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      // Make sure the player is on the right
      m_playerSide = side::LEFT;
      m_score++;

      // Add to the amount of time remaining
      m_timeRemaining += (2 / m_score) * .15;

      (*m_axe.getSprite()).setPosition(m_axe.PositionLeft(), (*m_axe.getSprite()).getPosition().y);
      (*m_player.getSprite()).setPosition(580, 720);

      // Update the branch
      updateBranches(m_score);

      // Set the log flying to the left
      (*m_log.getSprite()).setPosition(810, 720);
      m_log.SpeedX(5000);
      m_log.IsActive(true);

      m_acceptInput = false;
      // Play sound
      m_chop.play();
    }
  }
}

void Game::move() {
  if (!m_paused) {
    // Measure the time that has elapsed since the clock started
    sf::Time dt = m_clock.restart();
    // Substract from the amount of time remaining
    m_timeRemaining -= dt.asSeconds();
    // Set up the time bar
    m_timeBar.setSize(sf::Vector2f(m_timeBarWidthPerSecond * m_timeRemaining, TIMEBAR_HEIGHT));

    if (m_timeRemaining <= 0.0f) {
      // Pause the game.
      m_paused = true;
      // Change the message shown to the player
      setMessageText("Out of time!!");
      // Play the sound for out of time.
      m_outOfTime.play();
    }

    // Move bees
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

    // Update the score text
    std::stringstream ss;
    ss << "Score = " << m_score;
    m_scoreText.setString(ss.str());

    // Handle a flying log
    m_log.Move(0.0f, dt.asSeconds());

    if (m_branchPositions[5] == m_playerSide) {
      // Death
      m_paused = true;
      m_acceptInput = false;

      // Draw the gravestone
      (*m_rip.getSprite()).setPosition(525, 760);
      // Hide the player
      (*m_player.getSprite()).setPosition(2000, 660);
      // Change the text of the message
      setMessageText("SQUISHED!!");

      // Play death sound
      m_death.play();
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
  // Draw the score text
  window.draw(m_scoreText);
  if(m_paused) {
    // Draw message text.
    window.draw(m_messageText);
  }
}

void Game::updateBranches(int seed) {
  // Move all branches down one place
  for (int j = NO_OF_BRANCHES-1; j > 0; j--) {
    m_branches[j] = m_branches[j-1];
  }
  // Spawn a new branch at the top of the tree
  // LEFT, RIGHT, NONE
  srand((int)time(0) + seed);
  int r = (rand() % 5);
  switch (r) {
  case 0:
    m_branchPositions[0] = side::LEFT;
    break;
  case 1:
    m_branchPositions[0] = side::RIGHT;
    break;
  default:
    m_branchPositions[0] = side::NONE;
    break;
  }
}

void Game::setMessageText(std::string text) {
  m_messageText.setString(text);
  // Center it on the screen
  sf::FloatRect textRect = m_messageText.getLocalBounds();
  m_messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  m_messageText.setPosition(m_screenX/2.0f, m_screenY/2.0f);
}