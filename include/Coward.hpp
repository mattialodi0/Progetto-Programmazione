// nemico che scappa
// probabilmente da implementare loot come artifatti e chiavi
#pragma once

#include "Enemy.hpp"

class Coward : public Enemy
{
public:
    Coward();
    Coward(int y, int x, int diff);
    void createProjectile(Board &board_win, Hero &hero, Direction dir);
    void checkProjectile(Board &board_win, Hero &hero);
    // va via da te
    void chooseDirection(Board &board_win, Hero &hero);
};