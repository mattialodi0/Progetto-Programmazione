#pragma once

#include "Room.hpp"
#include "Artifact.hpp"
#include "Hero.hpp"
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "menu_playing.hpp"
using namespace std;

const int GameSpeed=2;
const int addedScore=10;

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

    Menu_playing menu_playing;
protected:
    int score=0;
    int canMove=0;
    int artifactHeal=10;
    int artifactDmg=5;
    int artifactRange=5;
    int artifactHp=10;
    int difficulty;
public:
	Game(int height, int width, int speed);
    bool isNotOver();
    void setGameOver();
    void processInput();
    void updateState();
    void updateScreen();
    void addScore();
    int getScore();

private:
    void redraw();
    void manageHeroMovement();
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
    void addRoomToIndex(prm room);
    void updateIndex(prm room);
};

