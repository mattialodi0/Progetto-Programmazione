#include "Room.hpp"

//fa il set up della stanza scegliendo un template, istanziando i nemici e gli artefatti
//poi posiziona il giocatore 
Room::Room() {
    this->y = 0; this->x = 0;
    this->north = NULL; 
    this->south = NULL; 
    this->west = NULL; 
    this->est = NULL; 
    initializeRoomTemplate(0);
}

Room::Room(int y, int x, Room** room_index, int index_dim) {//int room_template) {
    this->north = findRoom(room_index, index_dim, y+1, x);
    this->south = findRoom(room_index, index_dim, y-1, x);
    this->west = findRoom(room_index, index_dim, y, x-1);
	this->est = findRoom(room_index, index_dim, y, x+1);
    initializeRoomTemplate(rand()%2+1);   //room_template
}

Room::~Room() {
    delete [] enemies;
}


void Room::initializeRoomTemplate(int template_num) {
    switch (template_num)
    {
    case 0:
        this->room_template = template_0();
        break;
    case 1:
        this->room_template = template_1();
        break;
    case 2:
        this->room_template = template_2();
        break;
    default:
        this->room_template = template_0();
        break;
    }
}

Room* Room::findRoom(Room** room_index, int index_dim, int x, int y){
    int n = -1;
		for(int i = 0; i < index_dim; i++)
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

Room* findRoom1(Room** room_index, int index_dim, int x, int y){
    int n = -1;
		for(int i = 0; i < index_dim; i++)
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
    //drawEnemies();

    drawWalls(board);
    drawDoors(board);
}

void Room::drawWalls(Board board) {
    for(int i = 0; i < room_template.walls_num; i++) {    
        board.add(room_template.walls[i]);
    }
}

void Room::drawDoors(Board board) {
    for(int i = 0; i < room_template.doors_num; i++) {    
        board.add(room_template.doors[i]);
    }
}
