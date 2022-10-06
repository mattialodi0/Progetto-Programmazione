//file che si occupa del personaggio

#pragma once
#include <ncurses.h>
#include "Drawable.hpp"
#include "Board.hpp"

enum Direction
{ 																							// direzioni
	up = -2,
	down = 2,
	sx = -1,
	dx = 1,
	def = 0
};

class Hero : public Drawable
{
public:
	Direction cur_direction;

	Hero()
	{
		this->y = this->x = 0;
		this->icon = 'P';
	}

	Hero(int y, int x)
	{
		this->y = y;
		this->x = x;
		this->icon = 'P';
	}

	Direction getDirection()
	{
		return cur_direction;
	}

	void setDirection(Direction newdir)
	{
		cur_direction = newdir;
	}

	void centerHero() {
		this->y = BOARD_ROWS/2;
		this->x = BOARD_COLS/2;
	}

	void moveHero()
	{ 																							// movimento in se
		int row = Drawable::gety();
		int col = Drawable::getx();
		switch (cur_direction)
		{
		case down:
			row++;
			break;
		case up:
			row--;
			break;
		case sx:
			col--;
			break;
		case dx:
			col++;
			break;
		default:
			break;
		}
		this->y = row;
		this->x = col;
	}

	int getx()
	{
		return Drawable::getx();
	}
	int gety()
	{
		return Drawable::gety();
	}
	int getIcon()
	{
		return Drawable::getIcon();
	}
	void addHero(int y, int x, Board game_board)
	{ 																								// add e remove
		game_board.addAt(y, x, 'P');
	}

	void removeHero(Board game_board)
	{
		game_board.addAt(gety(), getx(), ' ');
	}
};
