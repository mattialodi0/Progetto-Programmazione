// nemico che va a caso
#pragma once

#include "Enemy.hpp"


class Drunk : public Enemy
{
public:
	Drunk();
	    //sprite diverso ma uguale
    void createProjectile(Direction dir) override;
    //uguale a shooter ma meno range
    void checkProjectile(Board &board_win, Character &hero);
	// override di characters
	void chooseDirection(Board &board_win, Character &hero) override;
};