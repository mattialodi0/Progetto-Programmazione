#pragma once

#include <ncurses.h>


class Drawable
{
protected:
	int y;
	int x;
	chtype icon;
public:
    Drawable();
	Drawable(int y, int x, chtype ch);
	
	int gety();
	int getx();
	chtype getIcon();
	void setx(int x);
	void sety(int y);
	void setIcon(chtype icon);
};
