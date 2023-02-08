#include "Game.hpp"
#include "menu.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <ncurses.h>


const int refreshspeed = 100;   //velocità di refresh dello schermo

int main()
{
    setlocale(LC_ALL, "");	//per stampare caratteri unicode
    // funzioni init di ncurses
	initscr();
	noecho();
	cbreak();
	refresh();
	curs_set(0);
	start_color();
	

	Menu menu;
    
	Game game = Game(BOARD_ROWS, BOARD_COLS, refreshspeed);
    
    //menu.menu();
	
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