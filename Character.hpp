#pragma once

#include "Direction.hpp"
#include "Board.hpp"
#include <ncurses.h>


class Character : public Drawable
{	
protected:
	Direction cur_direction;
	int ac;
	int dmg;
	int speed;
	int reload_time;
	int range;
	int difficulty;
public:
	int hp;
	Character();
	Character(Direction dir, int x, int y, chtype ch);

	void setDirection(Direction newdir);
	Direction getDirection();
	void moveCharacter(Board &game_board);
	Direction getRandomDirection();
	bool checkCollision(Board &board_win);
	bool checkFlyerCollision(Board &board_win);
};