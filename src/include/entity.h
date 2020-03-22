#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Entity {
protected:
  std::shared_ptr<sf::Sprite> m_sprite = std::make_shared<sf::Sprite>();
  std::shared_ptr<sf::Texture> m_texture = std::make_shared<sf::Texture>();
  bool m_isActive{false};
  float m_speed{0.0f};
public:
  virtual void Move(float index, float dtSeconds) = 0;
  std::shared_ptr<sf::Sprite> getSprite() const { return m_sprite; };
  bool IsActive() const { return m_isActive; };
  float Speed() const { return m_speed; };
  void IsActive(bool active) { m_isActive = active; };
  void Speed(float speed) { m_speed = speed; };
  virtual ~Entity() { /* std::cout << "Deleted" << std::endl; */ };
};

#endif