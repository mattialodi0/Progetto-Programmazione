// nemico che esplode
#pragma once

#include "Enemy.hpp"
#include "Hero.hpp"

class Boom : public Enemy
{
    protected:
    bool die=false;
    int dying_timer=boom_range+1;
    
public:
    Boom();
    Boom(int y,int x,int diff);
    //sprite diverso ma uguale
    void createProjectile(Board &board_win, Character &hero, Direction dir)override;
    //uguale a chaser ma esplode
    void checkProjectile(Board &board_win, Hero &hero);
    //ti viene vicino e esplode
    void chooseDirection(Board &board_win, Character &hero)override;
};