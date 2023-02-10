#pragma once

// spara in tutte le direzioni

#include "Enemy.hpp"

class Turret : public Enemy
{
public:
    Turret();
    Turret(int y, int x, int diff);
    // per creare proiettili
    void createProjectile(Board &board_win, Hero &hero, Direction dir);
    // per movimento proiettili e check di colpito o out of range
    void checkProjectile(Board &board_win, Hero &hero);
    // va a una tua stessa linea o colonna per spararti e spara
    void chooseDirection(Board &board_win, Hero &hero);
};