#pragma once
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
	int timeout;
public:
	
	void construct(int height, int width, int speed);

	Board();

	Board(int height, int width, int speed);

	void initialize();
	void clear();
	void refreshBoard();
	void addBorder();
	void add(Drawable &drawable);
	void remove(Drawable &drawable);

	void addAt(int y, int x, chtype ch);

	chtype getInput();

	void getEmptyCoordinates(int &y, int &x);

	chtype getCharAt(int y, int x);

	void setTimeout(int timeout);

	int getTimeout();
};

#endif