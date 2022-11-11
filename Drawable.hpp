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
	Drawable();
		Drawable(int y, int x, chtype ch) // parent di hero
	;
	int gety();
	int getx();
	chtype getIcon();
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

