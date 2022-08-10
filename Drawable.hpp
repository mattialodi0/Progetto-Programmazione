#include <ncurses.h>

class Drawable
{
public:
	Drawable()																				// parent di hero
	{ 
		int y = x = 0;
		chtype icon = ' ';
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

protected:
	int y, x;
	chtype icon;
};