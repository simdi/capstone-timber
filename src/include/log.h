#ifndef LOG_H
#define LOG_H

#include "entity.h"

class Log : public Entity {
private:
public:
  Log(sf::Vector2f cords, std::string texturePath);
  void Move(float index, float dtSeconds);
};

#endif