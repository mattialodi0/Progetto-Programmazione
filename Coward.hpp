// nemico che scappa
// probabilmente da implementare loot come artifatti e chiavi
#pragma once

#include "Enemy.hpp"

class Coward : public Enemy
{
public:
    Coward();
    void createProjectile(Board &board_win, Character &hero, Direction dir)override;
    void checkProjectile(Board &board_win, Character &hero);
    // va via da te
    void chooseDirection(Board &board_win, Character &hero) override;
   
};