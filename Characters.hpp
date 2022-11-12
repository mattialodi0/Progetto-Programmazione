// classe che si occupa dei drawable con direzione e movimento
#pragma once

#include "Board.hpp"
#include <ncurses.h>


// direzioni possibili
enum Direction
{
	up = -2,
	down = 2,
	sx = -1,
	dx = 1,
	def = 0
};
class Characters : public Drawable
{	
	protected:
	Direction cur_direction;
public:

	Characters(int y, int x, chtype ch);
	void setDirection(Direction newdir);
	// move
	Direction getDirection();
	// collisione
	void moveCharacter();
	bool checkCollision(Board board_win);
	};