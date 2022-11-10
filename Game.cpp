#include "Game.hpp"

Game::Game(int height, int width, int speed)
	{
		hero= Hero();
		game_board = Board(height, width, speed);
		initialize();
		index_dim = 0;
    	room_index = new prm[index_dim];
    	current_index = 0;
    	current_room  = new Room;
    	addRoomToIndex(current_room);
	}

		Game::~Game()
	{
 		delete [] room_index;
	}
    	void Game::initialize()
	{
		game_board.initialize();
		game_over = false;
		game_board.add(hero);
		hero.setDirection(def);
	}
    	/*void Game::startdraw(Drawable &drawable)
	{
		game_board.getEmptyCoordinates(drawable);
		game_board.addAt(drawable.y, drawable.x, drawable.icon);
	}
	*/
	bool Game::isNotOver()
	{
		return !game_over;
	}
    void Game::processInput()
	{ // input e direction
	chtype input = game_board.getInput();
		int old_timeout = game_board.getTimeout();
		hero.takeDirection(game_board);
		// per non duplicare
	}
	// movimenti
	void Game::updateState()
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
	void Game::updateScreen()
	{ // riaggiunge e refresh
		game_board.clear();
		redraw();
		game_board.refreshBoard();
	}
    void Game::redraw() // riaggiunge
	{
		game_board.add(hero);
		current_room->drawRoom(game_board);
	}



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
    hero.centerHero(down);
}
void Game::moveToSouthRoom() {
    current_room = current_room->south;
    //posiziona il giocatore in alto 
    hero.centerHero(up);
}
void Game::moveToWestRoom() {
    current_room = current_room->west;
    //posiziona il giocatore a destra
    hero.centerHero(dx);
}
void Game::moveToEstRoom() {
    current_room = current_room->est;
    //posiziona il giocatore a sinistra
    hero.centerHero(sx);
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