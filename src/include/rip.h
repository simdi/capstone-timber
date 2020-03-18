#ifndef RIP_H
#define RIP_H

#include "entity.h"

class Rip : public Entity {
private:
public:
  Rip(sf::Vector2f cords, std::string texturePath);
  void Move(float index, float dtSeconds);
};

#endif