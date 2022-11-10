// nemico che va a caso
#pragma once
#include "Characters.hpp"
#include "Hero.hpp"
#include <ncurses.h>

#include "Enemy.hpp"

class Drunk : public Enemy
{
public:
	Drunk(int y, int x);

	 void checkProjectile(Board board_win, Characters hero);
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