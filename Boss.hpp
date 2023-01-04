#pragma once
 
#include "Enemy.hpp"
#include "Hero.hpp"
 
class Boss : public Enemy
{
public:
   Boss();
   void createProjectile(Board &board_win, Character &hero, Direction dir) override;
   void checkProjectile(Board board_win, Character hero);
};