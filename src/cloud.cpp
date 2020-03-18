#include "./include/cloud.h"

Cloud::Cloud(sf::Vector2f cords, std::string texturePath) {
  m_texture->loadFromFile(texturePath);
  m_sprite->setTexture(*m_texture);
  m_sprite->setPosition(cords.x, cords.y);
}

void Cloud::Move(float index, float dtSeconds) {
  std::cout << index << dtSeconds << std::endl;
}