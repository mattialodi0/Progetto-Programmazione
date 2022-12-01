#include "Room.hpp"

//fa il set up della stanza scegliendo un template, istanziando i nemici e gli artefatti
Room::Room() {
    this->y = 0; this->x = 0;
    this->north = NULL; 
    this->south = NULL; 
    this->west = NULL; 
    this->est = NULL; 
    initializeRoomTemplate(0);
    this->room_template_number = 0;
}

Room::Room(int y, int x, vector<Room*> room_index) {//int room_template) {
    this->y = y; this->x = x;
    this->north = findRoom(room_index, y+1, x);
    this->south = findRoom(room_index, y-1, x);
    this->west = findRoom(room_index, y, x-1);
	this->est = findRoom(room_index, y, x+1);
    int n = rand()%3+1;
    this->room_template_number = n;
    initializeRoomTemplate(n);
}

void Room::initializeRoomTemplate(int template_num) {
    switch (template_num)
    {
    case 0:
        this->room_template = new Template_0();
        break;
    case 1:
        this->room_template = new Template_1();
        break;
    case 2:
        this->room_template = new Template_2();
        break;
    case 3:
        this->room_template = new Template_3();
        break;
    default:
        this->room_template = new Template_0();
        break;
    }
}

Room* Room::findRoom(vector<Room*> room_index, int x, int y){
    int n = -1;
		for(int i = 0; i < room_index.size(); i++)
		{
			if(room_index[i]->y == y && room_index[i]->x == x)
			{
				n = i; 
				break;	
			}
		}
	if(n < 0) return NULL;
	else return room_index[n]; 
}

void Room::drawRoom(Board board) {
    drawEnemies(board);
    drawWalls(board);
    drawDoors(board);
}

void Room::moveEnemies(Board board, Hero hero) {
    for(int i = 0; i < room_template->enemies_num; i++) {    
        this->room_template->enemies[i]->ChooseDirection(board, hero);
        if(this->room_template->enemies[i]->checkCollision(board)) {
            this->room_template->enemies[i]->moveCharacter();
        }
    }
}

bool Room::isClear() {
    //return room_template->enemies_num == 0;    //per il testing è disattivata 
    return 1;
}


// funzioni private

void Room::drawEnemies(Board board) {
    for(int i = 0; i < room_template->enemies_num; i++) {    
        board.add(*room_template->enemies[i]);
        //board.addAt(room_template->enemies[i]->gety(), room_template->enemies[i]->gety(), room_template->enemies[i]->getIcon());
    }
   // wrefresh(board);
}

void Room::drawWalls(Board board) {
    for(int i = 0; i < room_template->walls_num; i++) {    
        board.add(room_template->walls[i]);
    }
}

void Room::drawDoors(Board board) {
    for(int i = 0; i < room_template->doors_num; i++) {    
        board.add(room_template->doors[i]);
    }
}


void Room::removeEnemy(int pos) {
    pEn temp = room_template->enemies[pos];
    room_template->enemies[pos] = room_template->enemies[room_template->enemies_num-1];
    room_template->enemies[room_template->enemies_num-1] = temp;
    room_template->enemies_num--;
}

void Room::addEnemy(pEn enemy) {
    room_template->enemies_num++;
    room_template->enemies[room_template->enemies_num-1] = enemy;
}