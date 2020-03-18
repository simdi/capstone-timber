#ifndef BEE_H
#define BEE_H

#include "entity.h"

class Bee : public Entity {
private:
public:
  Bee(sf::Vector2f cords, std::string texturePath);
  void Move(float index, float dtSeconds);
};

#endif