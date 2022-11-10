#pragma once

// file che si occupa dei drawables
// base disegnabile senza direzione

#include <ncurses.h>


class Drawable
{
protected:
	int y;
	int x;
	chtype icon;
public:
	Drawable(){}
		Drawable(int y, int x, chtype ch) // parent di hero
	{
		this->y =y;
		this->x =x;
		this->icon = ch;
	}
	
	int gety()
	{
		return this->y;
	}
	int getx()
	{
		return this->x;
	}
	chtype getIcon()
	{
		return this->icon;
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

