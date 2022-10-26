// nemico che va a caso
// puo' essere che lo cambio in un 2x2

#pragma once
#include "characters.hpp"
#include "Hero.hpp"
#include <ncurses.h>

class Dumb : public Characters
{
public:
	Dumb()
	{
		Characters();
		this->icon =
		 'B';
		this->x = 20;
		this->y = 15;
	}
	// override di characters
	void ChooseDirection(Board board_win, Hero hero) override
	{
		setDirection(dx);
	}
};