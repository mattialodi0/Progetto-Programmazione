#pragma once

#include "Room.hpp"
#include "Artifact.hpp"
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

const int GameSpeed=2;

class Game
{
private:
	bool game_over;

	Board game_board;
    Board score_board;
    Board stat_board;

	Hero hero;

	Room* current_room;
   	vector<Room*> room_index;

    int canMove;
public:
	Game(int height, int width, int speed);
	~Game();
    bool isNotOver();
    void processInput();
    void updateState();
    void updateScreen();
private:
    void redraw();
    void checkCollisions();
// funzioni per le stanze
	void manageDoor();

	void moveToNorthRoom();
    void moveToSouthRoom();
 	void moveToWestRoom();
  	void moveToEstRoom();

    void makeNorthRoom();
    void makeSouthRoom();
    void makeWestRoom();
    void makeEstRoom();

// funzioni per l'indice
	bool searchIndexNorth(prm room);
	bool searchIndexSouth(prm room);
	bool searchIndexWest(prm room);
	bool searchIndexEst(prm room);

    void addRoomToIndex(prm room);
    void updateIndex(prm room);
};

