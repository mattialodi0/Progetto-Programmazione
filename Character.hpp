#pragma once

#include "Direction.hpp"
#include "Board.hpp"
#include <ncurses.h>


class Character : public Drawable
{	
protected:
	Direction cur_direction;
public:
	Character();
	Character(Direction dir, int x, int y, chtype ch);

	void setDirection(Direction newdir);
	Direction getDirection();
	void moveCharacter();

	bool checkCollision(Board board_win);
};