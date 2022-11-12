#include "Game.hpp"


//distruttore manuale
void Game::Destructor() {
    for(int i=0; i < index_dim; i++) {
        room_index[i]->Destructor();
    }
}

void Game::manageDoor() {
    if(hero.gety() <= 1) 
	{
		if(searchIndexNorth(current_room)) 		//se non la stanza non è ancora stata generata
			moveToNorthRoom();
		else	
			makeNorthRoom();
	}
	else if(hero.gety() >= BOARD_ROWS-2) 
	{
		if(searchIndexSouth(current_room)) 		//se non la stanza non è ancora stata generata
			moveToSouthRoom();
		else	
			makeSouthRoom();
	}
	else if(hero.getx() <= 1) 
	{
		if(searchIndexWest(current_room)) 		//se non la stanza non è ancora stata generata
			moveToWestRoom();
		else	
			makeWestRoom();
	}
	else if(hero.getx() >= BOARD_COLS-2) 
	{
		if(searchIndexEst(current_room)) 		//se non la stanza non è ancora stata generata
			moveToEstRoom();
		else	
			makeEstRoom();
	}
}

//funzioni per cambiare stanza
void Game::moveToNorthRoom() {
    current_room = current_room->north;
    //posiziona il giocatore in basso 
    hero.centerHero(up);
}
void Game::moveToSouthRoom() {
    current_room = current_room->south;
    //posiziona il giocatore in alto 
    hero.centerHero(down);
}
void Game::moveToWestRoom() {
    current_room = current_room->west;
    //posiziona il giocatore a destra
    hero.centerHero(sx);
}
void Game::moveToEstRoom() {
    current_room = current_room->est;
    //posiziona il giocatore a sinistra
    hero.centerHero(dx);
}

//funzioni per creare nuove stanze
void Game::makeNorthRoom() {
    current_room->north = new Room(current_room->y+1, current_room->x, room_index, index_dim);
    updateIndex(current_room->north);
    addRoomToIndex(current_room->north);       //******************
    moveToNorthRoom();

}
void Game::makeSouthRoom() {
    current_room->south = new Room(current_room->y-1, current_room->x, room_index, index_dim);
    updateIndex(current_room->south);
    addRoomToIndex(current_room->south);       //******************
    moveToSouthRoom();  
}
void Game::makeWestRoom() {
    current_room->west = new Room(current_room->y, current_room->x-1, room_index, index_dim);
    updateIndex(current_room->west);
    addRoomToIndex(current_room->west);       //******************
    moveToWestRoom();
}
void Game::makeEstRoom() {
    current_room->est = new Room(current_room->y, current_room->x+1, room_index, index_dim);
    updateIndex(current_room->est);
    addRoomToIndex(current_room->est);       //******************
    moveToEstRoom();
}


void Game::addRoomToIndex(prm room) {
    this->index_dim += 1;
    this->room_index[current_index] = room;
    this->current_index += 1;
}



void Game::updateIndex(prm room) {
    for(int i = 0; i < index_dim; i++)
	{
		if(room_index[i]->y == room->y+1 && room_index[i]->x == room->x)
			room_index[i]->south = room;
		if(room_index[i]->y == room->y-1 && room_index[i]->x == room->x)
			room_index[i]->north = room;
		if(room_index[i]->y == room->y && room_index[i]->x == room->x-1)
			room_index[i]->est = room;
		if(room_index[i]->y == room->y && room_index[i]->x== room->x+1)
			room_index[i]->west = room;		
	}
}

bool Game::searchIndexNorth(prm room) {
    //bool f = false;
    for(int i = 0; i < index_dim; i++)
	{
		if(room_index[i]->y == room->y+1 && room_index[i]->x == room->x)
            //f  = true;
            return true;
	}
    return false;
}

bool Game::searchIndexSouth(prm room) {
    //bool f = false;
    for(int i = 0; i < index_dim; i++)
	{
		if(room_index[i]->y == room->y-1 && room_index[i]->x == room->x)
            //f  = true;
            return true;
	}
    return false;
}

bool Game::searchIndexWest(prm room) {
    bool f = false;
    for(int i = 0; i < index_dim; i++)
	{
		if(room_index[i]->y == room->y && room_index[i]->x == room->x-1)
            f  = true;
	}
    return f;
}

bool Game::searchIndexEst(prm room) {
    bool f = false;
    for(int i = 0; i < index_dim; i++)
	{
		if(room_index[i]->y == room->y && room_index[i]->x == room->x+1)
            f  = true;
	}
    return f;
}