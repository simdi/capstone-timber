#ifndef TREE_H
#define TREE_H

class Tree {
private:
  std::shared_ptr<sf::Sprite> m_sprite = std::make_shared<sf::Sprite>();
  std::shared_ptr<sf::Texture> m_texture = std::make_shared<sf::Texture>();
  // bool isActive{false};
  // float speed{0.0f};
public:
  Tree(sf::Vector2f cords, std::string texturePath);
  std::shared_ptr<sf::Sprite> getSprite() const;
};

#endif