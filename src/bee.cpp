#include "./include/bee.h"

Bee::Bee(sf::Vector2f cords, std::string texturePath) {
  m_texture->loadFromFile(texturePath);
  m_sprite->setTexture(*m_texture);
  m_sprite->setPosition(cords.x, cords.y);
}

void Bee::Move(float index, float dtSeconds) {
  if(!m_isActive) {
    // How far is the bee
    srand((int)time(0) * 10);
    m_speed = (rand() % 200) + 200;
    // How high is the bee
    srand((int)time(0) * 10);
    float height = (rand() % 500) + 500;
    float x = 2000.0f;
    float y = static_cast<float>(height + (index * 50));
    m_sprite->setPosition(x, y);
    m_isActive = true;
  } else
  // Move the bee
  {
    m_sprite->setPosition(m_sprite->getPosition().x - (m_speed * dtSeconds), m_sprite->getPosition().y);
    // has the bee reached the right hand edge of the screen?
    if (m_sprite->getPosition().x < -100) {
      // Set it up to be a whole new cloud next frame
      m_isActive = false;
    }
  }
}