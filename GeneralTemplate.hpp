#pragma once

#include "Board.hpp"
#include "Chaser.hpp"   //../enemies/
//#include "../enemies/Coward.hpp"
#include "Drunk.hpp"
//#include "../enemies/Shooter.hpp"
#include "room_objects/Door.hpp"
#include "room_objects/Wall.hpp"

#define HALF_COLS BOARD_COLS/2
#define HALF_ROWS BOARD_ROWS/2


class General_template {
public:
    Drawable* walls;
    Drawable* doors;
    pEn* enemies;
    int walls_num; 
    int doors_num;
    int enemies_num;
    General_template();
    General_template(int w, int d, int e);
    ~General_template();
};


class Template_0 : public General_template {
public:
    Template_0() : General_template(5,16,0)
    {
        walls[0] = Wall(6,6);
        walls[1] = Wall(10,19); 
        walls[2] = Wall(10,11); 
        walls[3] = Wall(3,25); 
        walls[4] = Wall(8,30); 

        doors[0] = Door(0,HALF_COLS-2);   //north doors
        doors[1] = Door(0,HALF_COLS-1);
        doors[2] = Door(0,HALF_COLS);
        doors[3] = Door(0,HALF_COLS+1);
        doors[4] = Door(0,HALF_COLS+2);
        doors[5] = Door(BOARD_ROWS-1,HALF_COLS-2);   //south doors
        doors[6] = Door(BOARD_ROWS-1,HALF_COLS-1);
        doors[7] = Door(BOARD_ROWS-1,HALF_COLS);
        doors[8] = Door(BOARD_ROWS-1,HALF_COLS+1);
        doors[9] = Door(BOARD_ROWS-1,HALF_COLS+2);
        doors[10] = Door(HALF_ROWS-1,0);   //west doors
        doors[11] = Door(HALF_ROWS,0);
        doors[12] = Door(HALF_ROWS+1,0);
        doors[13] = Door(HALF_ROWS-1,BOARD_COLS-1);   //est doors
        doors[14] = Door(HALF_ROWS,BOARD_COLS-1);
        doors[15] = Door(HALF_ROWS+1,BOARD_COLS-1);
    }
};


class Template_1 : public General_template {
public:
    Template_1() : General_template(1,16,1)
    {
        walls[0] = Wall(10,15);
        
        doors[0] = Door(0,HALF_COLS-2);   //north doors
        doors[1] = Door(0,HALF_COLS-1);
        doors[2] = Door(0,HALF_COLS);
        doors[3] = Door(0,HALF_COLS+1);
        doors[4] = Door(0,HALF_COLS+2);
        doors[5] = Door(BOARD_ROWS-1,HALF_COLS-2);   //south doors
        doors[6] = Door(BOARD_ROWS-1,HALF_COLS-1);
        doors[7] = Door(BOARD_ROWS-1,HALF_COLS);
        doors[8] = Door(BOARD_ROWS-1,HALF_COLS+1);
        doors[9] = Door(BOARD_ROWS-1,HALF_COLS+2);
        doors[10] = Door(HALF_ROWS-1,0);   //west doors
        doors[11] = Door(HALF_ROWS,0);
        doors[12] = Door(HALF_ROWS+1,0);
        doors[13] = Door(HALF_ROWS-1,BOARD_COLS-1);   //est doors
        doors[14] = Door(HALF_ROWS,BOARD_COLS-1);
        doors[15] = Door(HALF_ROWS+1,BOARD_COLS-1);

        enemies[0] = new Drunk();
        enemies[0]->setDirection(def);
    }
};


class Template_2 : public General_template {
public:
    Template_2() : General_template(8,16,1)
    {
        walls[0] = Wall(BOARD_ROWS/3*2,1);
        walls[1] = Wall(BOARD_ROWS/3*2,2);
        walls[2] = Wall(BOARD_ROWS/3*2,3);
        walls[3] = Wall(BOARD_ROWS/3*2,4);
        walls[4] = Wall(BOARD_ROWS/3*2,5);
        walls[5] = Wall(BOARD_ROWS/3*2,6);
        walls[6] = Wall(BOARD_ROWS/3*2,7);
        walls[7] = Wall(BOARD_ROWS/3*2,8);


        doors[0] = Door(0,HALF_COLS-2);   //north doors
        doors[1] = Door(0,HALF_COLS-1);
        doors[2] = Door(0,HALF_COLS);
        doors[3] = Door(0,HALF_COLS+1);
        doors[4] = Door(0,HALF_COLS+2);
        doors[5] = Door(BOARD_ROWS-1,HALF_COLS-2);   //south doors
        doors[6] = Door(BOARD_ROWS-1,HALF_COLS-1);
        doors[7] = Door(BOARD_ROWS-1,HALF_COLS);
        doors[8] = Door(BOARD_ROWS-1,HALF_COLS+1);
        doors[9] = Door(BOARD_ROWS-1,HALF_COLS+2);
        doors[10] = Door(HALF_ROWS-1,0);   //west doors
        doors[11] = Door(HALF_ROWS,0);
        doors[12] = Door(HALF_ROWS+1,0);
        doors[13] = Door(HALF_ROWS-1,BOARD_COLS-1);   //est doors
        doors[14] = Door(HALF_ROWS,BOARD_COLS-1);
        doors[15] = Door(HALF_ROWS+1,BOARD_COLS-1);

        enemies[0] = new Chaser();      //coward
        enemies[0]->setDirection(def);
    }
};


class Template_3 : public General_template {
public:
    Template_3() : General_template(7,16,1)
    {
        walls[0] = Wall(1,(BOARD_ROWS/3+2)*2);
        walls[1] = Wall(2,(BOARD_ROWS/3+2)*2);
        walls[2] = Wall(3,(BOARD_ROWS/3+2)*2);
        walls[3] = Wall(4,(BOARD_ROWS/3+2)*2);
        walls[4] = Wall(5,(BOARD_ROWS/3+2)*2);
        walls[5] = Wall(6,(BOARD_ROWS/3+2)*2);
        walls[6] = Wall(7,(BOARD_ROWS/3+2)*2);


        doors[0] = Door(0,HALF_COLS-2);   //north doors
        doors[1] = Door(0,HALF_COLS-1);
        doors[2] = Door(0,HALF_COLS);
        doors[3] = Door(0,HALF_COLS+1);
        doors[4] = Door(0,HALF_COLS+2);
        doors[5] = Door(BOARD_ROWS-1,HALF_COLS-2);   //south doors
        doors[6] = Door(BOARD_ROWS-1,HALF_COLS-1);
        doors[7] = Door(BOARD_ROWS-1,HALF_COLS);
        doors[8] = Door(BOARD_ROWS-1,HALF_COLS+1);
        doors[9] = Door(BOARD_ROWS-1,HALF_COLS+2);
        doors[10] = Door(HALF_ROWS-1,0);   //west doors
        doors[11] = Door(HALF_ROWS,0);
        doors[12] = Door(HALF_ROWS+1,0);
        doors[13] = Door(HALF_ROWS-1,BOARD_COLS-1);   //est doors
        doors[14] = Door(HALF_ROWS,BOARD_COLS-1);
        doors[15] = Door(HALF_ROWS+1,BOARD_COLS-1);

        enemies[0] = new Chaser();
        enemies[0]->setDirection(def);
    }
};


class Template_4 : public General_template {
public:
    Template_4() : General_template(18,16,0)
    {
        walls[0] = Wall(HALF_ROWS-1, HALF_COLS-1);
        walls[1] = Wall(HALF_ROWS-1, HALF_COLS);
        walls[2] = Wall(HALF_ROWS-1, HALF_COLS+1);
        walls[3] = Wall(HALF_ROWS, HALF_COLS+1);
        walls[4] = Wall(HALF_ROWS+1, HALF_COLS+1);
        walls[5] = Wall(HALF_ROWS+1, HALF_COLS);
        walls[6] = Wall(HALF_ROWS+1, HALF_COLS-1);
        walls[7] = Wall(HALF_ROWS, HALF_COLS-1);
        walls[8] = Wall(HALF_ROWS, HALF_COLS);
        walls[9] = Wall(HALF_ROWS-1, HALF_COLS-1);
        walls[10] = Wall(HALF_ROWS, HALF_COLS-1);
        walls[11] = Wall(HALF_ROWS+1, HALF_COLS-1);
        walls[12] = Wall(HALF_ROWS-1, HALF_COLS+2);
        walls[13] = Wall(HALF_ROWS, HALF_COLS+2);
        walls[14] = Wall(HALF_ROWS+1, HALF_COLS+2);
        walls[15] = Wall(HALF_ROWS-1, HALF_COLS-2);
        walls[16] = Wall(HALF_ROWS, HALF_COLS-2);
        walls[17] = Wall(HALF_ROWS+1, HALF_COLS-2);
        

        doors[0] = Door(0,HALF_COLS-2);   //north doors
        doors[1] = Door(0,HALF_COLS-1);
        doors[2] = Door(0,HALF_COLS);
        doors[3] = Door(0,HALF_COLS+1);
        doors[4] = Door(0,HALF_COLS+2);
        doors[5] = Door(BOARD_ROWS-1,HALF_COLS-2);   //south doors
        doors[6] = Door(BOARD_ROWS-1,HALF_COLS-1);
        doors[7] = Door(BOARD_ROWS-1,HALF_COLS);
        doors[8] = Door(BOARD_ROWS-1,HALF_COLS+1);
        doors[9] = Door(BOARD_ROWS-1,HALF_COLS+2);
        doors[10] = Door(HALF_ROWS-1,0);   //west doors
        doors[11] = Door(HALF_ROWS,0);
        doors[12] = Door(HALF_ROWS+1,0);
        doors[13] = Door(HALF_ROWS-1,BOARD_COLS-1);   //est doors
        doors[14] = Door(HALF_ROWS,BOARD_COLS-1);
        doors[15] = Door(HALF_ROWS+1,BOARD_COLS-1);
    }
};