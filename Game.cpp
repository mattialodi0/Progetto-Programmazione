#include "Game.hpp"

Game::Game() {
    gameboard = Board();    //creazione della finestra di gioco

    room_index = new RoomIndex;//creazione dell'indice delle stanze
    current_room  = new Room;
    room_index.addRoomToIndex(current_room);
}

bool Game::isNotOver() {
    return !game_over;
}

void Game::processInput() {

    char c = wgetch(gameboard.game_win);

    switch (c)
    {
    case 'q':
        game_over = true;
        break;
    case 'w':
        //moveHeroNorth();
        break;
    case 's':
        //moveHeroSouth();
        break;
    case 'a':
        //moveHeroWest();
        break;
    case 'd':
        //moveHeroEst();
        break;
    }
}

void Game::updateState() {
    
    checkCollisions()
    
}

void Game::updateScreen() {}


void Game::checkCollisions() {
    wallCollisions();
    doorCollisions();
    enemyCollisions();
}

void Game::wallCollisions() {
    //cancella il movimento
}

void Game::doorCollisions() {
    if (collisione porta nord) 
        if(current_room->north != NULL) moveToNorthRoom();
        else makeNorthRoom();
    else if (collisione porta sud) 
        if(current_room->south != NULL) moveToSouthRoom();
        else makeSouthRoom();
    else if (collisione porta ovest)
        if(current_room->west != NULL) moveToWestRoom();
        else makeWestRoom();
    else if (collisione porta est) 
        if(current_room->est != NULL) moveToEstRoom();
        else makeEstRoom();
    
}

void Game::enemyCollisions() {
    //cancella il movimento + eventuali danni al giocatore
}

//funzioni per cambiare stanza
void Game::moveToNorthRoom() {
    current_room = current_room->north;
    //posiziona il giocatore in basso 
}
void Game::moveToSouthRoom() {
    current_room = current_room->south;
    //posiziona il giocatore in alto 
}
void Game::moveToWestRoom() {
    current_room = current_room->west;
    //posiziona il giocatore a destra
}
void Game::moveToEstRoom() {
    current_room = current_room->est;
    //posiziona il giocatore a sinistra
}

//funzioni per creare nuove stanze
void Game::makeNorthRoom() {
    current_room->north = new Room(current_room->y+1, current_room->x, room_index);
    room_index.updateIndex(current_room->north);
    moveToNorthRoom();
}
void Game::makeSouthRoom() {
    current_room->south = new Room(current_room->y-1, current_room->x, room_index);
    room_index.updateIndex(current_room->south);
    moveToSouthRoom();  
}
void Game::makeWestRoom() {
    current_room->west = new Room(current_room->y, current_room->x-1, room_index);
    room_index.updateIndex(current_room->west);
    moveToWestRoom();
}
void Game::makeEstRoom() {
    current_room->est = new Room(current_room->y, current_room->x+1, room_index);
    room_index.updateIndex(current_room->est);
    moveToEstRoom();
}