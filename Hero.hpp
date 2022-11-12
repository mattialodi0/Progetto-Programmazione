// file che si occupa del personaggio
#pragma once

#include "Characters.hpp"
const int starting_x=3;
const int starting_y=3;

class Hero : public Characters
{
public:	
	Hero(int y, int x)
	{
	Characters(def,x,y,'P');
	}
	Hero()
	{
		Characters(def,starting_x,starting_y,'P');
	}


	// input
	void takeDirection(Board game_board)
	{
		chtype input = game_board.getInput();
		int old_timeout = game_board.getTimeout();
		switch (input)
		{
		case KEY_UP:
		case 'w':
			setDirection(up);
			break;
		case KEY_DOWN:
		case 's':
			setDirection(down);
			break;
		case KEY_RIGHT:
		case 'd':
			setDirection(dx);
			break;
		case KEY_LEFT:
		case 'a':
			setDirection(sx);
			break;
		case 'p':
			game_board.setTimeout(-1);
			while (game_board.getInput() != 'p')
				;
			game_board.setTimeout(old_timeout);
		default:
			setDirection(def); // per non forzare movimento
			break;
		}
	}
		void centerHero(Direction dir) {
	switch(dir){
	case(sx):
	this->x=1;
	this->y=BOARD_ROWS/2;
	break;
	case (dx):
	this->x=BOARD_COLS-2;
	this->y=BOARD_ROWS/2;
	break;
		case (up):
	this->x=BOARD_COLS/2;
	this->y=1;
	break;
		case (down):
	this->x=BOARD_COLS/2;
	this->y=BOARD_ROWS-2;
	break;
}
	}
};
