#include "Game.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <ncurses.h>

const int refreshspeed = 100; // velocità di refresh dello schermo

int main()
{
	setlocale(LC_ALL, ""); // per stampare caratteri unicode
	// funzioni init di ncurses
	initscr();
	noecho();
	cbreak();
	refresh();
	curs_set(0);
	start_color();

	// controllo sulle dimensioni dello schermo
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	if (yMax < 25 || xMax < 100)
	{
		return 0;
	}

	Game game = Game(BOARD_ROWS, BOARD_COLS, refreshspeed);

	while (game.isNotOver())
	{
		// input
		game.processInput();

		// collisioni e movimento
		game.updateState();

		// refresh
		game.updateScreen();
	}
	game.gameOver();
	getch();

	endwin();
	std::cout << "game over\n";
	return 0;
}