#pragma once 

#include "RoomTemplates.hpp"
#include "Hero.hpp"
#include <cstdlib>

class Room {
private:
    int room_template_number;
    general_template room_template;
public:
    int y; int x;
    Room* north; Room* south; Room* west; Room* est;
    //Drawable* enemies = new Drawable[1]; 
    //int enemies_num;

    Room();    //costrutture stanza di partenza

    Room(int y, int x, Room** room_index, int index_dim);   //costruttore stanza qualsiasi

    //~Room();

    void drawRoom(Board board);

    void moveEnemies(Board board, Hero hero);

    void Destructor();

private:
    void initializeRoomTemplate(int template_num);
    
    Room* findRoom(Room** room_index, int index_dim, int y, int x);
    
    void drawEnemies(Board board);
    void drawWalls(Board board);
    void drawDoors(Board board);

}; typedef Room* prm;

