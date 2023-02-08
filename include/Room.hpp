#pragma once 

#include "Templates.hpp"  
#include <cstdlib>
#include <vector>

using namespace std;

#define NUMBER_OF_ROOMS 40

class Room {
private:
    bool has_north_door, has_south_door, has_west_door, has_est_door;
    bool north_door_locked, south_door_locked, west_door_locked, est_door_locked;
    int room_template_number;
    void decideIfDoors();
    Room* findRoom(vector<Room*> room_index, int y, int x, Direction dir);

    int randomRoomNumber(); 
    void initializeRoomTemplate(int template_num, int n,Board &game_board);

    void lockDoor(int n);
    void lockNorthDoor();
    void lockSouthDoor();
    void lockWestDoor();
    void lockEstDoor();
    
    void drawProjectiles(Board &board);
    void drawEnemies(Board &board);
    void drawArtifact(Board &board);
    void drawWalls(Board &board);
    void drawDoors(Board &board);

    //funzioni per i nemici
    
    void addEnemy(pEn enemy);
    //void damageEnemy(int damage);
    //void healEnemy(int healing);
public:
void removeEnemy(int pos);
    int y; int x;
    Room* north; Room* south; Room* west; Room* est;

    General_template *room_template;

    Room(Board &game_board);    //costrutture stanza di partenza

    Room(int y, int x, vector<Room*> room_index,int n,Board &game_board);   //costruttore stanza generica

    void drawRoom(Board &board);

    void moveEnemies(Board &board, Hero &hero);

    int checkEnemiesHp(Board &board_win);

    bool isClear();

    void unlockDoor(int y, int x, Board &game_board);

    void removeArtifact(int pos);

    void checkHeroProjectile(Board &board_win,Hero &hero);

}; typedef Room* prm;
