// file principale con il main che crea l'oggetto di gioco

#include "Game.hpp"
#include "Board.hpp"
#include <ncurses.h>
#include "Drawable.hpp"
#include <iostream>

using namespace std;
extern const int refreshspeed = 100;

int main()
{																				 // da aggiungere scoreboard e un modo di fare gameover
	initscr();
	noecho();
	cbreak();																	 // funzioni di inizializzazione di ncurses
	refresh();
	curs_set(0);


	Game game = Game(BOARD_ROWS, BOARD_COLS, refreshspeed); 					 // inizializzazione oggetto di gioco
	
	while (game.isNotOver())
	{ 																			 // ciclo pricipale
		game.processInput();													 // input , direzione e rimozione di hero

		game.updateState(); 													 // collisioni e movimento

		game.updateScreen();													 // refresh e add di hero
	}
	getch();
	endwin();
	
	game.Destructor();
	cout << "game over\n";

	return 0;
}

/*ci potrebbero e ci sono alcune cose ridondanti ma scio'
la funzione per il tempo potrebbe non funzionare su tutte le macchine
io ho spammato include magari alcuni sono ridondanti
un po copiato da casual coder ma neanche tanto 
cambiate il nome delle variabili se volete ma fatelo bene 
*/
