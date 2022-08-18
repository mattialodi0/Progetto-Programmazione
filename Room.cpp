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
    //initializeRoomTemplate(room_template);
}

Room::~Room()
{
    delete [] enemies;
}

void Room::drawRoom(WINDOW* win) {

    //drawPlayer();
    //drawEnemy();

    drawWalls(win);
    drawDoors(win);
}



void Room::initializeRoomTemplate(int template_num) {
    switch (template_num)
    {
    case 0:
        this->room_template = template_0;
        break;
    default:
        break;
    }
}

/*
void Room::multiarrcpy(int cpy[][2], int orgn[][2]) {
    for(int i = 0; i < this->room_template.walls_num ; i++) { 
        cpy[i][0] = orgn[i][0];
        cpy[i][1] = orgn[i][1];
    }
}
*/

Room* Room::findRoom(Room** room_index, int index_dim, int y, int x){
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

void Room::drawWalls(WINDOW* win) {
    for(int i = 0; i < room_template.doors.length; i++) {    
        mvwprintw(win, room_template.walls[i].gety(), room_template.walls[i].getx(), "X");
    }
    wrefresh(win);
}

void Room::drawDoors(WINDOW* win) {
    for(int i = 0; i < room_template.doors.length; i++) {    
        mvwprintw(win, room_template.doors[i].gety(), room_template.doors[i].getx(), "X");
    }
    wrefresh(win);
}