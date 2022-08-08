
//#include "RoomTemplates.hpp"
#include <ncurses.h>
#include <iostream>
#include <stdio.h>


class Room {
private:
    int room_template_number;
    //general_template room_template;
    //Drawable enemies[]; 
    int room_num;
public:
    int y; int x;
    Room* north; Room* south; Room* west; Room* est;

    Room();    //costrutture stanza di partenza

    Room(int y, int x, Room** room_index, int index_dim);   //costruttore stanza qualsiasi

    void drawRoom(WINDOW* win);

private:
    Room* findRoom(Room** room_index, int index_dim, int y, int x);

}; typedef Room* prm;
