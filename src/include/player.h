#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity {
private:
public:
  Player(sf::Vector2f cords, std::string texturePath);
  void Move(float index, float dtSeconds);
};

#endif