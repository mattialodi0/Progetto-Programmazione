#pragma once

//nemico che spara

#include "Enemy.hpp"


class Shooter : public Enemy
{
public:
    Shooter();
    Shooter(int y,int x,int diff);
    //per creare proiettili
     void createProjectile(Board &board_win, Character &hero, Direction dir)override;
     //per movimento proiettili e check di colpito o out of range
     void checkProjectile(Board &board_win, Character &hero);
     //va a una tua stessa linea o colonna per spararti e spara
     void chooseDirection(Board &board_win, Character &hero) override;
    
};