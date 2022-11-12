// file che si occupa del personaggio
#pragma once

#include "Characters.hpp"
const int starting_x=BOARD_COLS/2;
const int starting_y=BOARD_ROWS/2;
class Hero : public Characters
{
public:	
	Hero(int y, int x);

	Hero();



	// input
	void takeDirection(Board game_board);
	void centerHero(Direction dir) ;
};
