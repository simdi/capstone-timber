#ifndef LOG_H
#define LOG_H

#include <iostream>
#include "entity.h"

class Log : public Entity {
private:
  float speedX{1000.0f};
  float speedY{-1500.0f};
public:
  Log(sf::Vector2f cords, std::string texturePath);
  void Move(float index, float dtSeconds);
  float SpeedX() const { return speedX; };
  float SpeedY() const { return speedY; };
  void SpeedX(float x) { speedX = x; };
  void SpeedY(float y) { speedY = y; };
};

#endif