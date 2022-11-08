#pragma once

// file controller di funzioni e del gioco
#include <iostream>
//#include <windows.h>
// vedete voi se metterlo da me da errori e non mi serve
#include <time.h>
#include <stdlib.h>
#include "Room.hpp"
#include "Artifacts.hpp"
#include <cassert>

const int GameSpeed=2;
using namespace std;
class Game
{
protected:
	bool game_over;
	Board game_board;
	Hero hero;
	Artifacts artifacts;
	// init di board e hero
	int herostartx = BOARD_COLS/2;
	int herostarty= BOARD_ROWS/2;
	int canMove = 0;
	// Board score_board;
	// da implementare
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
	// inizialize
	void initialize()
	{
		game_board.initialize();
		game_over = false;
		game_board.add(hero);
		hero.setDirection(def);
	}
	
	/*void startdraw(Drawable &drawable)
	{
		game_board.getEmptyCoordinates(drawable);
		game_board.addAt(drawable.y, drawable.x, drawable.icon);
	}
	*/
	bool isNotOver()
	{
		return !game_over;
	}
	// input
	void processInput()
	{ // input e direction
	chtype input = game_board.getInput();
		int old_timeout = game_board.getTimeout();
		hero.takeDirection(game_board);
		// per non duplicare
	}

	// movimenti
	void updateState()
	{
		// hero
		game_board.remove(hero);
		if (hero.checkCollision(game_board))
		{
			hero.moveCharacter();
				manageDoor();
		}
		hero.setDirection(def);
		game_board.add(hero);
		if(canMove<=0){
		current_room->moveEnemies(game_board, hero);
		canMove--;
		}
		else{
		canMove=GameSpeed;
		}
	}

	// refresh
	void updateScreen()
	{ // riaggiunge e refresh
		game_board.clear();
		redraw();
		game_board.refreshBoard();
	}

	void redraw() // riaggiunge
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

