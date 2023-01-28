#include "Game.hpp"

Game::Game(int height, int width, int speed)
{
	srand(time(0));

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	
	game_board = Board(height, width, (yMax/2)-(height/2), (xMax/2)-(width/2)-(width/4)-1, speed);
	game_board.initialize();

	score_board = Board(height/3, width/2, (yMax/2)-(height/2), (xMax/2)+(width/4)+1, speed);
	score_board.initialize();
	score_board.print("ScoreBoard");
	score_board.refreshBoard();

	stat_board = Board(height-height/3, width/2, (yMax/2)-(height/2)+(height/3), (xMax/2)+(width/4)+1, speed);
	stat_board.initialize();
	stat_board.print("StatBoard");
	stat_board.refreshBoard();
	
	hero = Hero(herostarty, herostartx);
	hero.centerHero(def);

	game_over = false;

	current_room  = new Room(game_board);
	room_index.emplace_back(current_room);

	canMove = 0;
}

Game::~Game()
{
	//delete [] room_index;
}

bool Game::isNotOver()
{
	return !game_over;
}

void Game::processInput()
{
	chtype input = game_board.getInput();
	int old_timeout = game_board.getTimeout();
	switch (input)
	{
	case 'w':
		hero.setDirection(up);
		break;
	case 's':
		hero.setDirection(down);
		break;
	case 'd':
		hero.setDirection(dx);
		break;
	case 'a':
		hero.setDirection(sx);
		break;
	case KEY_UP:
		hero.attack(game_board, up);
		/*if(current_room->north != NULL)		//per il testing
				moveToNorthRoom();
			else	
				makeNorthRoom();*/
		break;
	case KEY_DOWN:
		hero.attack(game_board, down);
		/*if(current_room->south != NULL)		//per il testing
				moveToSouthRoom();
			else	
				makeSouthRoom();*/
		break;
	case KEY_RIGHT:
		hero.attack(game_board, dx);
		/*if(current_room->west != NULL)		//per il testing
				moveToWestRoom();
			else	
				makeWestRoom();*/
		break;
	case KEY_LEFT:
		hero.attack(game_board, sx);
		/*if(current_room->est != NULL)		//per il testing
				moveToEstRoom();
			else	
				makeEstRoom();*/
		break;
	case 'f':
		hero.useAbility(); 	//abilità speciale della classe
		break;
	case 'o':
		this->game_over = true;
		break;
	case 'p':
		game_board.setTimeout(-1);
		while (game_board.getInput() != 'p')
			;
		game_board.setTimeout(old_timeout);
	default:
		hero.setDirection(def); // per non forzare movimento
		break;
	}
}

void Game::updateState()
{
	//hero
	//game_board.remove(hero);
	
	if(hero.death()){
		this->game_over = true;
	}

	manageHeroMovement();
	hero.setDirection(def);	
	hero.checkProjectile(game_board);							//--> da mettere dentro a hero

	//enemies
	if(canMove <= 0){
		current_room->moveEnemies(game_board, hero);
		canMove=GameSpeed;
	}
	else{
		canMove--;
	}
}

void Game::updateScreen()
{
	game_board.clear();
	redraw();
	game_board.refreshBoard();
}

void Game::redraw() // riaggiunge
{
	current_room->drawRoom(game_board);
	game_board.add(hero);
}

void Game::manageHeroMovement()
{

	int offsety = 0, offsetx = 0;
	if (hero.getDirection() == up || hero.getDirection() == down)
	{
		// offset per row e col per collisione
		offsety = hero.getDirection() / 2;
	}
	else
	{
		if (hero.getDirection() == dx || hero.getDirection() == sx)
		{
			offsetx = hero.getDirection();
		}
	}
	if(!game_board.getTaken(hero.getx()+offsetx,hero.gety()+offsety)){
	switch (game_board.getCharAt(hero.gety() + offsety, hero.getx() + offsetx))
	{
	case ' ':
	case 'o':
	case '-':
	case '|':
		hero.moveCharacter(game_board);
		break;
	case 'E':
		hero.moveCharacter(game_board);
		hero.increaseDamage();
		current_room->removeArtifact(0);
		break;
	case 'H':
		hero.moveCharacter(game_board);
		hero.increaseHealth();
		current_room->removeArtifact(0);
		break;
	case 'R':
		hero.moveCharacter(game_board);
		hero.increaseRange();
		current_room->removeArtifact(0);
		break;	
	case 'O':		//cambia stanza
		if(hero.gety() > 1 && hero.gety() < BOARD_ROWS-2 && hero.getx() > 1 && hero.getx() < BOARD_COLS-2) 
			hero.moveCharacter(game_board);
		else
			manageDoor();
		break;
	case 'Q':
		if(hero.useKey()) {
			current_room->unlockDoor(hero.gety() + offsety, hero.getx() + offsetx);			
		}
		break;
	default:
		break;
	}
	}
}

void Game::manageDoor() {
	if(current_room->isClear()) 
	{
		if(hero.gety() <= 1) 
		{
			if(current_room->north != NULL)		//searchIndexNorth(current_room)) 		//se non la stanza non è ancora stata generata
				moveToNorthRoom();
			else	
				makeNorthRoom();
		}
		else if(hero.gety() >= BOARD_ROWS-2) 
		{
			if(current_room->south != NULL)		//searchIndexSouth(current_room)) 		//se non la stanza non è ancora stata generata
				moveToSouthRoom();
			else	
				makeSouthRoom();
		}
		else if(hero.getx() <= 1) 
		{
			if(current_room->west != NULL)		//searchIndexWest(current_room)) 		//se non la stanza non è ancora stata generata
				moveToWestRoom();
			else	
				makeWestRoom();
		}
		else if(hero.getx() >= BOARD_COLS-2) 
		{
			if(current_room->est != NULL)		//searchIndexEst(current_room)) 		//se non la stanza non è ancora stata generata
				moveToEstRoom();
			else	
				makeEstRoom();
		}
	}
}

//funzioni per cambiare stanza
void Game::moveToNorthRoom() {
	game_board.clearTaken();
    current_room = current_room->north;
    //posiziona il giocatore in basso 
    hero.centerHero(hero.getDirection());
}
void Game::moveToSouthRoom() {
	game_board.clearTaken();
    current_room = current_room->south;
    //posiziona il giocatore in alto 
    hero.centerHero(hero.getDirection());
}
void Game::moveToWestRoom() {
	game_board.clearTaken();
    current_room = current_room->west;
    //posiziona il giocatore a destra
    hero.centerHero(hero.getDirection());
}
void Game::moveToEstRoom() {
	game_board.clearTaken();
    current_room = current_room->est;
    //posiziona il giocatore a sinistra
    hero.centerHero(hero.getDirection());
}

//funzioni per creare nuove stanze
void Game::makeNorthRoom() {
	game_board.clearTaken();
    current_room->north = new Room(current_room->y+1, current_room->x, room_index,1,game_board);
    updateIndex(current_room->north);
    addRoomToIndex(current_room->north);       //******************
    moveToNorthRoom();

}
void Game::makeSouthRoom() {
	game_board.clearTaken();
    current_room->south = new Room(current_room->y-1, current_room->x, room_index,-1,game_board);
    updateIndex(current_room->south);
    addRoomToIndex(current_room->south);       //******************
    moveToSouthRoom();  
}
void Game::makeWestRoom() {
	game_board.clearTaken();
    current_room->west = new Room(current_room->y, current_room->x-1, room_index, -2,game_board);
    updateIndex(current_room->west);
    addRoomToIndex(current_room->west);       //******************
    moveToWestRoom();
}
void Game::makeEstRoom() {
	game_board.clearTaken();
    current_room->est = new Room(current_room->y, current_room->x+1, room_index,2,game_board);
    updateIndex(current_room->est);
    addRoomToIndex(current_room->est);       //******************
    moveToEstRoom();
}


void Game::addRoomToIndex(prm room) {
    //this->index_dim += 1;
    //this->room_index[current_index] = room;
    //this->current_index += 1;
	this->room_index.emplace_back(room);
}



void Game::updateIndex(prm room) {
    for(int i = 0; i < room_index.size(); i++)
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
    for(int i = 0; i < room_index.size(); i++)
	{
		if(room_index[i]->y == room->y+1 && room_index[i]->x == room->x)
            //f  = true;
            return true;
	}
    return false;
}

bool Game::searchIndexSouth(prm room) {
    //bool f = false;
    for(int i = 0; i < room_index.size(); i++)
	{
		if(room_index[i]->y == room->y-1 && room_index[i]->x == room->x)
            //f  = true;
            return true;
	}
    return false;
}

bool Game::searchIndexWest(prm room) {
    bool f = false;
    for(int i = 0; i < room_index.size(); i++)
	{
		if(room_index[i]->y == room->y && room_index[i]->x == room->x-1)
            f  = true;
	}
    return f;
}

bool Game::searchIndexEst(prm room) {
    bool f = false;
    for(int i = 0; i < room_index.size(); i++)
	{
		if(room_index[i]->y == room->y && room_index[i]->x == room->x+1)
            f  = true;
	}
    return f;
}