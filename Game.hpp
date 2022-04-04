#pragma once

#include "Room.hpp"
#include "Board.hpp"


class Game 
{
private:
    bool game_over;
    Board gameboard;
public:
    Game();

    bool isNotOver();    //verifica che il gioco non sia terminato

    void processInput();    //gestisce gli input da tastiera

    void updateState();     //aggiorna il punteggio e lo stato del gioco

    void updateScreen();    //aggiorna lo schermo

};