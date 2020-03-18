#ifndef CLOUD_H
#define CLOUD_H

#include "entity.h"

class Cloud : public Entity {
private:
public:
  Cloud(sf::Vector2f cords, std::string texturePath);
  void Move(float index, float dtSeconds);
};

#endif