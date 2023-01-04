// nemico che va a caso
#pragma once

#include "Enemy.hpp"


class Drunk : public Enemy
{
public:
	Drunk();
	Drunk(int y, int x);
	    //sprite diverso ma uguale
    void createProjectile(Board &board_win, Character &hero, Direction dir) override;
    //uguale a shooter ma meno range
    void checkProjectile(Board &board_win, Character &hero);
	// override di characters
	void chooseDirection(Board &board_win, Character &hero) override;
};