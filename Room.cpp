#include "Room.hpp"

//fa il set up della stanza scegliendo un template, istanziando i nemici e gli artefatti
//poi posiziona il giocatore 
Room::Room() {

    this->y = 0; this->x = 0;
    this->north = NULL; 
    this->south = NULL; 
    this->west = NULL; 
    this->est = NULL; 
    //initializeRoomTemplate(0);
}

Room::Room(int y, int x, Room** room_index, int index_dim) {//int room_template) {

    this->north = findRoom(room_index, index_dim, y+1, x);
    this->south = findRoom(room_index, index_dim, y-1, x);
    this->west = findRoom(room_index, index_dim, y, x-1);
	  this->est = findRoom(room_index, index_dim, y, x+1);
    //initializeRoomTemplate(room_template);
}
/*
void Room::initializeRoomTemplate(int template_num) {

    this->room_template_number = template_num;
    switch (this->room_template_number)
    {
    case 0:
        template_0 temp_0;
       //this->room_template = temp_0;
       multiarrcpy(room_template.walls, temp_0.walls);
       this->room_template.walls_num = temp_0.walls_num;
       break;
    }
}
*/
void Room::drawRoom(WINDOW* win) {

    //drawPlayer();
    //drawEnemy();

    //drawWalls(win);
    //drawDors();
}
/*
void Room::drawWalls(WINDOW* win) {

    for(int i = 0; i < this->room_template.walls_num ; i++) {
        mvwprintw(win, room_template.walls[i][0], room_template.walls[i][1], "X");
    }
    wrefresh(win);
}
*/
/*
void Room::multiarrcpy(int cpy[][2], int orgn[][2]) {
    for(int i = 0; i < this->room_template.walls_num ; i++) { 
        cpy[i][0] = orgn[i][0];
        cpy[i][1] = orgn[i][1];
    }
}
*/

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
