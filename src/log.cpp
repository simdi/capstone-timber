#include "./include/log.h"

Log::Log(sf::Vector2f cords, std::string texturePath) {
  m_texture->loadFromFile(texturePath);
  m_sprite->setTexture(*m_texture);
  m_sprite->setPosition(cords.x, cords.y);
}

void Log::Move(float index, float dtSeconds) {
  std::cout << index << dtSeconds << std::endl;
  if (IsActive()) {
    m_sprite->setPosition(m_sprite->getPosition().x + (SpeedX() * dtSeconds), m_sprite->getPosition().y + (SpeedY() * dtSeconds));

    // Has the log reached the right hand edge?
    if (m_sprite->getPosition().x < -100 || m_sprite->getPosition().y > 2000) {
      // Set it up ready to a whole new log next frame
      IsActive(false);
      m_sprite->setPosition(810, 720);
    }
  }
}