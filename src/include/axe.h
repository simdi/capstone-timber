#ifndef AXE_H
#define AXE_H

#include "entity.h"

class Axe : public Entity {
private:
  float m_positionLeft{700};
  float m_positionRight{1075};
public:
  Axe(sf::Vector2f cords, std::string texturePath);
  float PositionLeft() const { return m_positionLeft; };
  float PositionRight() const { return m_positionRight; };
  void PositionLeft(float left) { m_positionLeft = left; };
  void PositionRight(float right) { m_positionRight = right; };
  void Move(float index, float dtSeconds);
};

#endif