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
	int canMove = 0;
	// Board score_board;
	// da implementare
	Room* current_room;
   	Room** room_index;
    int index_dim;
    int current_index;
public:
	Game(int height, int width, int speed);
		~Game();
	// inizialize
	void initialize();
	
	/*void startdraw(Drawable &drawable)
	*/
	bool isNotOver();
	// input
	void processInput();
	// movimenti
	void updateState();

	// refresh
	void updateScreen();

	void redraw(); // riaggiunge
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

