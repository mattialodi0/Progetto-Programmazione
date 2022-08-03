#pragma once

#include "Room.hpp"
#include "Board.hpp"
#include "RoomIndex.hpp"


class Game 
{
private:
    bool game_over;
    Board gameboard;
    prm current_room;
    RoomIndex room_index;
public:
    Game();

    bool isNotOver();    //verifica che il gioco non sia terminato

    void processInput();    //gestisce gli input da tastiera

    void updateState();     //aggiorna il punteggio e lo stato del gioco

    void updateScreen();    //aggiorna lo schermo

private:
    void checkCollisions();
    void wallCollosions();
    void doorCollisions();
    void enemyColliosions();

    void moveToNorthRoom();
    void moveToSouthRoom();
    void moveToWestRoom();
    void moveToEstRoom();

    void makeNorthRoom();
    void makeSouthRoom();
    void makeWestRoom();
    void makeEstRoom();
};