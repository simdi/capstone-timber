#ifndef BRANCHES_H
#define BRANCHES_H

#include "entity.h"

class Branches : public Entity {
private:
public:
  Branches(sf::Vector2f cords, std::string texturePath);
  void Move(float index, float dtSeconds);
};

#endif