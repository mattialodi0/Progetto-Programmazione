// nemico che va a caso
// puo' essere che lo cambio in un 2x2

#pragma once
#include "Characters.hpp"
#include "Hero.hpp"
#include <ncurses.h>

class Drunk : public Characters
{
public:
	Drunk()
	{
		Characters();
		this->icon = 'D';
		this->x = 10;
		this->y = 10;
	}
	// override di characters
	void ChooseDirection(Board board_win, Hero hero) override
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