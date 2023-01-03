#include "Room.hpp"

//fa il set up della stanza scegliendo un template, istanziando i nemici e gli artefatti
Room::Room() {
    this->y = 0; this->x = 0;
    this->north = NULL; 
    this->south = NULL; 
    this->west = NULL; 
    this->est = NULL; 
    initializeRoomTemplate(15);
    this->room_template_number = 0;
}

Room::Room(int y, int x, vector<Room*> room_index) {//int room_template) {
    this->y = y; this->x = x;
    this->north = findRoom(room_index, y+1, x);
    this->south = findRoom(room_index, y-1, x);
    this->west = findRoom(room_index, y, x-1);
	this->est = findRoom(room_index, y, x+1);
    int n = rand()%16+1;
    this->room_template_number = n;
    initializeRoomTemplate(n);
}

void Room::initializeRoomTemplate(int template_num) {
    switch (template_num)
    {
    case 0:
        this->room_template = new Template_0i();
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
    case 4:
        this->room_template = new Template_4i();
        break;
    case 5:
        this->room_template = new Template_5();
        break;
    case 6:
        this->room_template = new Template_6();
        break;
    case 7:
        this->room_template = new Template_7();
        break; 
    case 8:
        this->room_template = new Template_8();
        break; 
    case 9:
        this->room_template = new Template_9();
        break; 
    case 10:
        this->room_template = new Template_10();
        break;
    case 11:
        this->room_template = new Template_11();
        break;
    case 12:
        this->room_template = new Template_12();
        break;
    case 13:
        this->room_template = new Template_13();
        break;
    case 14:
        this->room_template = new Template_14();
        break;
    case 15:
        this->room_template = new Template_15();
        break;
    case 16:
        this->room_template = new Template_16();
        break;
    default:
        this->room_template = new Template_0i();
        break;
    }
}

Room* Room::findRoom(vector<Room*> room_index, int y, int x){
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

void Room::drawRoom(Board &board) {
    drawEnemies(board);
    drawWalls(board);
    drawDoors(board);
    drawProjectiles(board);
}

void Room::moveEnemies(Board &board, Hero &hero) {
    for(int i = 0; i < room_template->enemies_num; i++) {    
         this->room_template->enemies[i]->chooseDirection(board, hero);
         this->room_template->enemies[i]->checkProjectile(board, hero);
       if(this->room_template->enemies[i]->checkCollision(board)) {
            this->room_template->enemies[i]->moveCharacter();
            
        }
    }
}

bool Room::isClear() {
    //return room_template->enemies_num == 0;    //per il testing è disattivata 
    return 1;
}

void Room::unlockDoor(int y, int x)
{
    int j = 0;
    bool f = true;
    while(f)
    {
        f = false;
        for(int i=0; i < room_template->doors_num; i++)
        {
            int ty = room_template->doors[i].gety();
            int tx = room_template->doors[i].getx();
            if((ty == y-j || ty == y+j || ty == y) && (tx == x-j || tx == x+j || tx == x))
            {
                if(room_template->doors[i].getIcon() == 'Q')
                {
                    f = true;
                    room_template->doors[i] = Door(ty,tx);
                }
            }    
        }
        j++;
    }
}

// funzioni private

void Room::drawProjectiles(Board &board){
for(int j = 0; j < room_template->enemies_num; j++) { 
    for (int i = 0; i < room_template->enemies[j]->projectile.size(); i++)
		{
            board.add(*room_template->enemies[j]->projectile[i]);
        }
        }
}

void Room::drawEnemies(Board &board) {
    for(int i = 0; i < room_template->enemies_num; i++) {    
        board.add(*room_template->enemies[i]);
       // board.addAt(room_template->enemies[i]->gety(), room_template->enemies[i]->getx(), room_template->enemies[i]->getIcon());
    }
   // wrefresh(board);
}

void Room::drawWalls(Board &board) {
    for(int i = 0; i < room_template->walls_num; i++)
    {    
        board.add(room_template->walls[i]);
    }
}

void Room::drawDoors(Board &board) {
    for(int i = 0; i < room_template->doors_num; i++) 
    {    
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