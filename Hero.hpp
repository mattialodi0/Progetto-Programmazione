#pragma once

#include "Character.hpp"

const int herostartx = (BOARD_COLS/2)+1;
const int herostarty= (BOARD_ROWS/2)+1;

class Hero : public Character
{
public:	
    Hero();
	Hero(int y, int x);
	
	void Const(int y, int x);

	void centerHero(Direction dir);
};