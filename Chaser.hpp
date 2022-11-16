// nemico che ti segue
#pragma once

#include "Enemy.hpp"
#include "Hero.hpp"

class Chaser : public Enemy
{
public:
    Chaser();
    //sprite diverso ma uguale
    void createProjectile(Direction dir) override;
    //uguale a shooter ma meno range
    void checkProjectile(Board board_win, Character hero);
    //ti viene vicino e spara un piccolo proiettile e viene stunnato
    void ChooseDirection(Board board_win, Character &hero) override;
};