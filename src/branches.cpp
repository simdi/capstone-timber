#include "./include/branches.h"

Branches::Branches(sf::Vector2f cords, std::string texturePath) {
  m_texture->loadFromFile(texturePath);
  m_sprite->setTexture(*m_texture);
  m_sprite->setPosition(cords.x, cords.y);
  // Set the sprite's origin to dead center
  // we can then spin it round without changing it's position
  m_sprite->setOrigin(220, 20);
}

void Branches::Move(float index, float dtSeconds) {
  // std::cout << index << dtSeconds << std::endl;
}