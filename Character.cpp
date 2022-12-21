#include "Character.hpp"


Character::Character()
{
	setDirection(def);
	hp=0; ac=0; dmg=0; speed=0; reload_time=0; range=0;
}

Character::Character(Direction dir, int x, int y, chtype ch) : Drawable(y,x,ch)
{
	//Drawable(y,x,ch);
	hp=0; ac=0; dmg=0; speed=0; reload_time=0; range=0;
	setDirection(dir);
}

void Character::setDirection(Direction newdir)
{
	cur_direction = newdir;
}

Direction Character::getDirection()
{
    return cur_direction;
}

void Character::moveCharacter()
{
	switch (cur_direction)
	{
	case down:
		this->y++;
		break;
	case up:
		this->y--;
		break;
	case sx:
		this->x--;
		break;
	case dx:
		this->x++;
		break;
	default:
		break;
	}
}

bool Character::checkCollision(Board &board_win)
{
	int offsety = 0, offsetx = 0;
	if (cur_direction == up || cur_direction == down)
	{
		// offset per row e col per collisione
		offsety = cur_direction / 2;
	}
	else
	{
		if (cur_direction == dx || cur_direction == sx)
		{
			offsetx = cur_direction;
		}
	}
	switch (board_win.getCharAt(y + offsety, x + offsetx))
	{
	case ' ':
	case 'F':
	case 'H':	
		return true;
		break;
	default:
		return false;
		break;
	}
	return false;
}
