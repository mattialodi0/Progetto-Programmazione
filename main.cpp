#include "Game.hpp"
#include <iostream>
#include <ncurses.h>

const int refreshspeed = 100;   //velocità di refresh dello schermo

int main()
{
    // funzioni init di ncurses
	initscr();
	noecho();
	cbreak();
	refresh();
	curs_set(0);
	
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
	
	getch();
	endwin();
	std::cout << "game over\n";
	return 0;
}