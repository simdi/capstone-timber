#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "entity.h"

class Tree : public Entity {
private:
public:
  Tree(sf::Vector2f cords, std::string texturePath);
  void Move(float index, float dtSeconds);
};

#endif