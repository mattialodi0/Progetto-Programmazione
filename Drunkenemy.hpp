// nemico che va a caso
#pragma once
<<<<<<< HEAD:Drunkenemy.hpp
=======
#include "Characters.hpp"
#include "Hero.hpp"
#include <ncurses.h>
>>>>>>> 13ed699ba366b9c647345c8f67fc12ba56e29b79:DrunkenEnemy.hpp

#include "Enemy.hpp"

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