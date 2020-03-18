#include "./include/cloud.h"

Cloud::Cloud(sf::Vector2f cords, std::string texturePath) {
  m_texture->loadFromFile(texturePath);
  m_sprite->setTexture(*m_texture);
  m_sprite->setPosition(cords.x, cords.y);
}

std::shared_ptr<sf::Sprite> Cloud::getSprite() const {
  return m_sprite;
};