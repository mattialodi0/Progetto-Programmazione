// file controller di funzioni e del gioco

#pragma once
#include "Board.hpp"
#include <iostream>
//#include <windows.h>
//vedete voi se metterlo da me da errori e non mi serve
#include <time.h>
#include <stdlib.h>
#include "Hero.hpp"
#include "Room.hpp"


class Game
{
private:
	bool game_over;
	Board game_board; 																				// init di board e hero
	Hero hero;
	int herostartx = BOARD_COLS/2, herostarty = BOARD_ROWS/2;
	// Board score_board;
	//da implementare

	Room* current_room;
   	Room** room_index;
    int index_dim;
    int current_index;
public:
	Game(int height, int width, int speed)
	{
		game_board = Board(height, width, speed);
		hero = Hero(herostarty, herostartx);
		initialize();
		
		index_dim = 0;
    	room_index = new prm[index_dim];
    	current_index = 0;
    	current_room  = new Room;
    	addRoomToIndex(current_room);
	}
	
	~Game()
	{
 		delete [] room_index;
	}

	void initialize()
	{
		game_board.initialize();
		game_over = false;
		hero.addHero(herostarty, herostartx, game_board);
		hero.setDirection(def);
	}

	bool isNotOver()
	{
		return !game_over;
	}

	void processInput()
	{ 																								// input e direction
		chtype input = game_board.getInput();
		int old_timeout = game_board.getTimeout();
		switch (input)
		{
		case KEY_UP:
		case 'w':
			hero.setDirection(up);
			break;
		case KEY_DOWN:
		case 's':
			hero.setDirection(down);
			break;
		case KEY_RIGHT:
		case 'd':
			hero.setDirection(dx);
			break;
		case KEY_LEFT:
		case 'a':
			hero.setDirection(sx);
			break;
		case 'p':
			game_board.setTimeout(-1);
			while (game_board.getInput() != 'p')
				;
			game_board.setTimeout(old_timeout);
		case 'o':
			game_over = true;
			//Destructor();
			break;
		default:
			hero.setDirection(def); 																// per non forzare movimento
			break;
		}
		hero.removeHero(game_board); 																// per non duplicare
	}

	void updateState()
	{ 																								// chiama solo collision
		checkCollision();
		current_room->moveEnemies(game_board, hero);
	}

void checkCollision()
	{ 																								// collisione
		int offsety = 0, offsetx = 0;
		if (hero.cur_direction == up || hero.cur_direction == down)
		{ 																							// offset per row e col per collisione
			offsety = hero.cur_direction / 2;
		}
		else if (hero.cur_direction == dx || hero.cur_direction == sx)
		{
				offsetx = hero.cur_direction;
		}

		switch (game_board.getCharAt(hero.gety() + offsety, hero.getx() + offsetx))
		{
		case ' ':
			hero.moveHero(); 																		// se si puo' muovere si muove
			hero.setDirection(def);
		case 'O':							//cambia stanza
			manageDoor();
		case 'Q':
			// porta chiuisa:
			// controlla se il giocatore ha una chiave
			// se ne ha, ne toglie una e cambia il carattere di tutta la porta
			// e fa manageDoor();
			break;
		default:
			break;
		}
	}

	void updateScreen()
	{ 																								// riaggiunge e refresh
		game_board.clear();
		redraw();
		wrefresh(game_board.board_win);
	};
	
	void redraw()																					// riaggiunge
	{ 																							
		game_board.add(hero);
		current_room->drawRoom(game_board);
	}

	void Destructor();

private:
	void manageDoor();

	void moveToNorthRoom();
    void moveToSouthRoom();
 	void moveToWestRoom();
  	void moveToEstRoom();

    void makeNorthRoom();
    void makeSouthRoom();
    void makeWestRoom();
    void makeEstRoom();

	bool searchIndexNorth(prm room);
	bool searchIndexSouth(prm room);
	bool searchIndexWest(prm room);
	bool searchIndexEst(prm room);

    void addRoomToIndex(prm room);
    void updateIndex(prm room);
};

