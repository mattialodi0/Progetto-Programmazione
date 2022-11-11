#include "Drawable.hpp"
Drawable::Drawable(){}
		Drawable::Drawable(int y, int x, chtype ch) // parent di hero
	{
		this->y =y;
		this->x =x;
		this->icon = ch;
	}
	
	int Drawable::gety()
	{
		return this->y;
	}
	int Drawable::getx()
	{
		return this->x;
	}
	chtype Drawable::getIcon()
	{
		return this->icon;
		}