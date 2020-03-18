#include "./include/player.h"

Player::Player(sf::Vector2f cords, std::string texturePath) {
  m_texture->loadFromFile(texturePath);
  m_sprite->setTexture(*m_texture);
  m_sprite->setPosition(cords.x, cords.y);
}

void Player::Move(float index, float dtSeconds) {
  std::cout << index << dtSeconds << std::endl;
  // if(!m_isActive) {
  //   // How far is the Player
  //   srand((int)time(0) * (index + 1) * 10);
  //   m_speed = (rand() % 200);
  //   // How high is the Player
  //   srand((int)time(0) * (index + 1) * 10);
  //   float height = ( rand() % ( static_cast<int>(index+1) * 200 ) ) - ((index+1)*50);
  //   m_sprite->setPosition(-200, height);
  //   m_isActive = true;
  // } else
  // // Move the Player
  // {
  //   m_sprite->setPosition(m_sprite->getPosition().x + (m_speed * dtSeconds), m_sprite->getPosition().y);
  //   // has the Player reached the right hand edge of the screen?
  //   if (m_sprite->getPosition().x > 1920) {
  //     // Set it up to be a whole new Player next frame
  //     m_isActive = false;
  //   }
  // }
}