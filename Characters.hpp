// classe che si occupa dei drawable con direzione e movimento
#pragma once
#include "Drawable.hpp"
#include "Board.hpp"
#include <ncurses.h>
// direzioni possibili
enum Direction
{
	up = -2,
	down = 2,
	sx = -1,
	dx = 1,
	def = 0
};
class Characters : public Drawable
{	
	protected:
	
public:
Direction cur_direction;
	Characters()
	{
		Drawable();
	}

	void setDirection(Direction newdir)
	{
		cur_direction = newdir;
	}
	// move
	Direction getDirection()
	{
		return cur_direction;
	}
	void moveCharacter()
	{
		switch (cur_direction)
		{
		case down:
			y++;
			break;
		case up:
			y--;
			break;
		case sx:
			x--;
			break;
		case dx:
			x++;
			break;
		default:
			break;
		}
	}
	// collisione
	bool checkCollision(Board board_win)
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
		case 'O':		//cambia stanza
			return true;
			break;
		case 'Q':
			// porta chiuisa:
			// controlla se il giocatore ha una chiave
			// se ne ha, ne toglie una e cambia il carattere di tutta la porta
			// e fa manageDoor();
			break;

		default:
			return false;
			break;
		}
		return false;
	}
		// metodo astratto per scelta automatica di direzione dei nemici
	virtual void ChooseDirection(Board board_win, Characters hero)
	{
	}

};