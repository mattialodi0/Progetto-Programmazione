#pragma once

// file che si occupa dei drawables
// base disegnabile senza direzione

#include <ncurses.h>


class Drawable
{
public:
	int y;
	int x;
	chtype icon;

	Drawable() // parent di hero
	{
		this->y = this->x =0;
		this->icon = ' ';
	}
	Drawable(int y, int x, chtype ch)
	{
		this->y = y;
		this->x = x;
		this->icon = ch;
	}
	int gety()
	{
		return y;
	}
	int getx()
	{
		return x;
	}
	chtype getIcon()
	{
		return icon;
		}
		};
		class Door : public Drawable {
public:
	Door(int y, int x) : Drawable(y, x,'O')
	{
	}
};

class Wall : public Drawable {
public:
	Wall(int y, int x) : Drawable(y, x,'X')
	{
	}
};

