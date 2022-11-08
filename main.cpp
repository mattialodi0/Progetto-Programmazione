// file principale con il main che crea l'oggetto di gioco
#include "Game.hpp"

using namespace std;
extern const int refreshspeed = 100;

int main()
{
	// da aggiungere scoreboard e un modo di fare gameover
	initscr();
	noecho();
	cbreak();
	refresh();
	curs_set(0);
	// funzioni init di ncurses
	Game game = Game(BOARD_ROWS, BOARD_COLS, refreshspeed);
	// inizializzazione
	while (game.isNotOver())
	{
		// ciclo pricipale

		game.processInput();
		// input

		game.updateState();
		// collisioni e movimento

		game.updateScreen();
		// refresh
	}
	
	getch();
	endwin();
	game.Destructor();
	cout << "game over";
	return 0;
}
/*ci potrebbero e ci sono alcune cose ridondanti ma scio'
la funzione per il tempo potrebbe non funzionare su tutte le macchine
cambiate il nome delle variabili se volete ma fatelo bene
non aggiungo direzione diagonale perche' e' una cattiva idea
non aggiungo un nemico 2x2 perche' e' un bordello enome
la linea in mezzo e' per testing potete toglierla
e' un po difficile come gioco perche' le ai sono troppo brave volendo potete implementare delay per farle piu' ez ma...
known issues:

potete implementare che spara anche il nostro personaggio senza problemi 
io ho finito la mia parte arrangiatevi
buona fortuna
bacetti<3<3
*/
