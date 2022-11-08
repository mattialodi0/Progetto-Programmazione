//#pragma once
#ifndef BOARD_HPP
#define BOARD_HPP
// file che si occupa del view e del board

#include "Drawable.hpp"
#include <cstdlib>
//#include "window.h"
#include <time.h>
#include "Time.hpp"

const int BOARD_DIM = 17;					//ho tolto extern
const int BOARD_ROWS = BOARD_DIM;
const int BOARD_COLS = BOARD_DIM * 2.5;

class Board
{
protected:
	WINDOW *board_win;

public:
	int timeout;
	void construct(int height, int width, int speed)
	{
		int yMax, xMax;
		getmaxyx(stdscr, yMax, xMax);
		timeout = speed;
		board_win = newwin(height, width, (yMax / 2) - (height / 2),
						   (xMax / 2) - (width / 2));
		setTimeout(speed);
		keypad(board_win, true);
	}

	Board()
	{
		construct(0, 0, 300);
	}

	Board(int height, int width, int speed)
	{
		srand(time(0));
		construct(height, width, speed);
	}

	void initialize()
	{
		clear();
		refresh();
	}
	void clear()
	{
		wclear(board_win);
		addBorder();
	}
	void refreshBoard()
	{
		wrefresh(board_win);
	}
	void addBorder()
	{
		box(board_win, 0, 0);
	}
	// tutto questo sopra e' per init del board
	void add(Drawable &drawable)
	{
		addAt(drawable.gety(), drawable.getx(), drawable.getIcon());
		// add per general use
	}
	void remove(Drawable &drawable)
	{
		addAt(drawable.gety(), drawable.getx(), ' ');
	}

	void addAt(int y, int x, chtype ch)
	{
		// add
		mvwaddch(board_win, y, x, ch);
	}

	chtype getInput()
	// input e fixed time
	{
		time_t time_last_input = Time::milliseconds();
		chtype input = wgetch(board_win);
		chtype new_input = ERR;
		setTimeout(0);
		while (time_last_input + timeout >= Time::milliseconds())
		{
			new_input = wgetch(board_win);
		};
		setTimeout(timeout);
		if (new_input != ERR)
		{
			input = new_input;
		};
		return input;
	}

	void getEmptyCoordinates(int &y, int &x)
	{																									// for future use
		srand(time(NULL));
		while ((mvwinch(board_win, y = rand() % BOARD_ROWS, x = rand() % BOARD_COLS)) != ' ')
		{
		}
	}

	chtype getCharAt(int y, int x)
	{
		return mvwinch(board_win, y, x);
	}

	void setTimeout(int timeout)
	{
		wtimeout(board_win, timeout);
	}
	int getTimeout()
	{
		return timeout;
	}
};

#endif