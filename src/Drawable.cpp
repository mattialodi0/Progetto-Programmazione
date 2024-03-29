#include "Drawable.hpp"

Drawable::Drawable() // parent di hero
{
	this->y = this->x = 0;
	this->icon = ' ';
}

Drawable::Drawable(int y, int x, chtype ch)
{
	this->y = y;
	this->x = x;
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
void Drawable::sety(int y)
{
	this->y = y;
}

void Drawable::setx(int x)
{
	this->x = x;
}

void Drawable::setIcon(chtype icon)
{
	this->icon = icon;
}