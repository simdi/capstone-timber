#ifndef ENTITY_H
#define ENTITY_H

class Entity {
protected:
  std::shared_ptr<sf::Sprite> m_sprite = std::make_shared<sf::Sprite>();
  std::shared_ptr<sf::Texture> m_texture = std::make_shared<sf::Texture>();
  bool m_isActive{false};
  float m_speed{0.0f};
public:
  virtual void Move(float index, float dtSeconds) = 0;
  std::shared_ptr<sf::Sprite> getSprite() const { return m_sprite; };
  virtual ~Entity() { /* std::cout << "Deleted" << std::endl; */ };
};

#endif