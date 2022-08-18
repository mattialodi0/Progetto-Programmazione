#pragma once 

#include "RoomTemplates.hpp"
#include <ncurses.h>


class Room {
private:
    int room_template_number;
    general_template room_template;

public:
    int y; int x;
    Room* north; Room* south; Room* west; Room* est;
    Drawable* enemies = new Drawable[1]; 

    Room();    //costrutture stanza di partenza

    Room(int y, int x, Room** room_index, int index_dim);   //costruttore stanza qualsiasi

    ~Room();

    void drawRoom(WINDOW* win);

private:
    void initializeRoomTemplate(int template_num);
    
    Room* findRoom(Room** room_index, int index_dim, int y, int x);
    
    void drawWalls(WINDOW* win);

    void drawDoors(WINDOW* win);

}; typedef Room* prm;
