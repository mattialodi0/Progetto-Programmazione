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

void Character::moveCharacter(Board &game_board)
{
	switch (cur_direction)
	{
	case down:	
		game_board.setTaken(x,y,false);
		game_board.addAt(this->y,this->x,' ');
		this->y++;
		game_board.setTaken(x,y,true);
		game_board.addAt(this->y,this->x,this->icon);
		break;
	case up:
		game_board.setTaken(x,y,false);
		game_board.addAt(this->y,this->x,' ');
		this->y--;
		game_board.setTaken(x,y,true);
		game_board.addAt(this->y,this->x,this->icon);
		break;
	case sx:
		game_board.setTaken(x,y,false);
		game_board.addAt(this->y,this->x,' ');
		this->x--;
		game_board.setTaken(x,y,true);
		game_board.addAt(this->y,this->x,this->icon);
		break;
	case dx:
		game_board.setTaken(x,y,false);
		game_board.addAt(this->y,this->x,' ');
		this->x++;
		game_board.setTaken(x,y,true);
		game_board.addAt(this->y,this->x,this->icon);
		break;
	default:
		break;
	}
}
Direction Character::getRandomDirection(){
	int n = (rand() % 5) - 2;
		switch (n)
		{
		case -2:
			return up;
			break;
		case 2:
			return down;
			break;
		case -1:
			return sx;
			break;
		case 1:
			return dx;
			break;
		default:
		return def;
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
	if(!board_win.getTaken(x+offsetx,y+offsety)){
	switch (board_win.getCharAt(y + offsety, x + offsetx))
	{
	case ' ':
	case 'E':
	case 'H':
	case 'R':
	case 'J':
	case 'O':
	case '-':
	case '|':
	case 'o':
		return true;
		break;
	default:
		return false;
		break;
	}}
	return false;
}
bool Character::checkFlyerCollision(Board &board_win)
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
	case 'X':
	case 'O':
		return true;
		break;
	default:
		return false;
		break;
	}
	return false;
}