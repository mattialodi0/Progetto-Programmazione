#pragma once

#include "Direction.hpp"
#include "Board.hpp"
#include <ncurses.h>


class Character : public Drawable
{	
protected:
	Direction cur_direction;
	int ac;
	int standardDmg;
	int dmg;
	int reload;
	int maxReload;
	int standardRange;
	int range;
	int difficulty;
	int hp;
	int maxHp;
public:
	
	Character();
	Character(Direction dir, int x, int y, chtype ch);

	void setDirection(Direction newdir);
	Direction getDirection();
	void moveCharacter(Board &game_board);
	Direction getRandomDirection();
	bool checkCollision(Board &board_win);
	bool checkFlyerCollision(Board &board_win);
	void reduceHealth(int Damage);
	void setHp (int hp);
    int getHp ();
	void setRange (int hp);
    int getRange ();
	void setDmg (int hp);
    int getDmg ();
	void setMaxHp (int maxHp);
    int getMaxHp ();
	void setReload (int reload);
	void dimReload();
    int getReload ();
	void setMaxReload (int reload);
    int getMaxReload ();
};