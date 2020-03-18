#ifndef AXE_H
#define AXE_H

#include "entity.h"

class Axe : public Entity {
private:
public:
  Axe(sf::Vector2f cords, std::string texturePath);
  void Move(float index, float dtSeconds);
};

#endif