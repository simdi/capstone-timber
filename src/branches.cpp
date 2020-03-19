#include "./include/branches.h"

Branches::Branches(sf::Vector2f cords, std::string texturePath) {
  std::cout << "Branch Initialized." << std::endl;
  m_texture->loadFromFile(texturePath);
  m_sprite->setTexture(*m_texture);
  m_sprite->setPosition(cords.x, cords.y);
  // Set the sprite's origin to dead center
  // we can then spin it round without changing it's position
  m_sprite->setOrigin(220, 20);
}

void Branches::Move(float index, float dtSeconds) {
  std::cout << index << dtSeconds << std::endl;
}

// void updateBranches(int seed) {
//   // Move all branches down one place
//   for (int j = NUM_BRANCHES-1; j > 0; j--) {
//     branches[j] = branches[j-1];
//   }

//   // Spawn a new branch at the top of the tree
//   // LEFT, RIGHT, NONE
//   srand((int)time(0) + seed);
//   int r = (rand() % 5);
//   switch (r) {
//   case 0:
//     branchPositions[0] = side::LEFT;
//     break;
//   case 1:
//     branchPositions[0] = side::RIGHT;
//     break;
//   default:
//     branchPositions[0] = side::NONE;
//     break;
//   }
// }