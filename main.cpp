#include "Game.hpp"
#include "menu.hpp"
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
	start_color();
	init_pair(BOSS_PAIR, COLOR_RED, COLOR_BLACK);
	init_pair(ARTIFACT_PAIR, COLOR_BLUE, COLOR_BLACK);

	Menu menu;
    
	Game game = Game(BOARD_ROWS, BOARD_COLS, refreshspeed);
    
    menu.menu();
	
	while (game.isNotOver())
	{
		// input
		game.processInput();

        // collisioni e movimento
		game.updateState();
		
        // refresh
		game.updateScreen();
	}
	
	
	endwin();
	std::cout << "game over\n";
	return 0;
}