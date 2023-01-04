#pragma once 

#include "GeneralTemplate.hpp"  //room_templates/
#include "Hero.hpp"
#include <cstdlib>
#include <vector>

using namespace std;


class Room {
private:
    int room_template_number;
    General_template *room_template;
public:
    int y; int x;
    Room* north; Room* south; Room* west; Room* est;
public: 
    Room();    //costrutture stanza di partenza

    Room(int y, int x, vector<Room*> room_index);   //costruttore stanza generica

    void drawRoom(Board &board);

    void moveEnemies(Board &board, Hero &hero);

    bool isClear();

    void unlockDoor(int y, int x);

    void removeArtifact(int pos);
private:
    void initializeRoomTemplate(int template_num);
    Room* findRoom(vector<Room*> room_index, int y, int x);
    
    void drawProjectiles(Board &board);
    void drawEnemies(Board &board);
    void drawWalls(Board &board);
    void drawDoors(Board &board);
    void drawArtifact(Board &board);

    //funzioni per i nemici
    void removeEnemy(int pos);
    void addEnemy(pEn enemy);
    //void damageEnemy(int damage);
    //void healEnemy(int healing);

}; typedef Room* prm;

