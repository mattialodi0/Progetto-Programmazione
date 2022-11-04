// nemico che va a caso
#pragma once
#include "enemy.hpp"
#include <ncurses.h>
class Drunk : public Enemy
{
public:
	Drunk()
	{
		Enemy();
		this->icon = 'D';
		this->x = 10;
		this->y = 10;
	}
	 void checkProjectile(Board board_win, Characters hero){
     }
	// override di characters
	void ChooseDirection(Board board_win, Characters &hero) override
	{
		do
		{
			int n = (rand() % 5) - 2;
			switch (n)
			{
			case -2:
				setDirection(up);
				break;
			case 2:
				setDirection(down);
				break;
			case -1:
				setDirection(sx);
				break;
			case 1:
				setDirection(dx);
				break;
			default:
				break;
			}
		} while (!checkCollision(board_win));
	}
};