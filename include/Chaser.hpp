// nemico che ti segue
#pragma once

#include "Enemy.hpp"
#include "Hero.hpp"
class Chaser : public Enemy
{
public:
    Chaser();
    Chaser(int y, int x,int diff);
    //sprite diverso ma uguale
    void createProjectile(Board &board_win, Hero &hero, Direction dir);
    //uguale a shooter ma meno range
    void checkProjectile(Board &board_win, Hero &hero);
    //ti viene vicino e spara un piccolo proiettile e viene stunnato
    void chooseDirection(Board &board_win, Hero &hero);
};