#include "./include/axe.h"

Axe::Axe(sf::Vector2f cords, std::string texturePath) {
  m_texture->loadFromFile(texturePath);
  m_sprite->setTexture(*m_texture);
  m_sprite->setPosition(cords.x, cords.y);
}

void Axe::Move(float index, float dtSeconds) {}