#pragma once

#include "Board.hpp"
#include "Chaser.hpp"   //../enemies/
#include "Coward.hpp"
#include "Drunk.hpp"
#include "Shooter.hpp"
#include "room_objects/Door.hpp"
#include "room_objects/Wall.hpp"
#include <cstdlib>

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

    void drawDoors();

    int drawRandom(int num, int ya, int xa, int yb, int xb, int i);
    int drawHorizontalLine( int num, int start_y, int start_x, int i);
    int drawVerticalLine( int num, int start_y, int start_x, int i);
    int drawFilledSquare(int start_y, int start_x, int height, int width, int i);
    int drawEmptySquare(int start_y, int start_x, int height, int width, int i);
    int drawOrtogonalCross(int start_y, int start_x, int h_height, int h_width, int i);
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

        drawDoors();
    }
};

class Template_0i : public General_template {
public:
    Template_0i() : General_template(10,16,1)
    {
        drawRandom(10, 2, 2,BOARD_ROWS-2, BOARD_COLS-2,0);

        drawDoors();
         enemies[0] = new Chaser();
         enemies[0]->setDirection(def);
    }
};


class Template_1 : public General_template {
public:
    Template_1() : General_template(1,16,1)
    {
        walls[0] = Wall(10,15);
        
        drawDoors();

        enemies[0] = new Drunk();
        enemies[0]->setDirection(def);
    }
};

//orizontal line
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


        drawDoors();

        enemies[0] = new Chaser();      //coward
        enemies[0]->setDirection(def);
    }
};

//orizontal line
class Template_2i : public General_template {
public:
    Template_2i() : General_template(8,16,1)
    {
        drawHorizontalLine(8, BOARD_ROWS/3*2, 1, 0);

        drawDoors();

        enemies[0] = new Chaser();      //coward
        enemies[0]->setDirection(def);
    }
};

//verical line
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


        drawDoors();

        enemies[0] = new Chaser();
        enemies[0]->setDirection(def);
    }
};

//verical line
class Template_3i : public General_template {
public:
    Template_3i() : General_template(7,16,1)
    {
        drawVerticalLine(7, 1, (BOARD_ROWS/3+2)*2, 0);

        drawDoors();

        enemies[0] = new Chaser();
        enemies[0]->setDirection(def);
    }
};

//square
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
        

        drawDoors();
    }
};

//filled square
class Template_4i : public General_template {
public:
    Template_4i() : General_template(15,16,0)
    {
        drawFilledSquare(HALF_ROWS-1, HALF_COLS-2, 3, 5, 0);

        drawDoors();
    }
};

//empty square
class Template_4ii : public General_template {
public:
    Template_4ii() : General_template(12,16,0)
    {
        drawEmptySquare(HALF_ROWS-1, HALF_COLS-2, 3, 5, 0);

        drawDoors();
    }
};

//ortogonal cross
class Template_5 : public General_template {
public:
    Template_5() : General_template(23,16,0)
    {
        walls[0] = Wall(HALF_ROWS, HALF_COLS);
        walls[1] = Wall(HALF_ROWS-1, HALF_COLS);
        walls[2] = Wall(HALF_ROWS-2, HALF_COLS);
        walls[3] = Wall(HALF_ROWS-3, HALF_COLS);
        walls[4] = Wall(HALF_ROWS-4, HALF_COLS);
        walls[5] = Wall(HALF_ROWS+1, HALF_COLS);
        walls[6] = Wall(HALF_ROWS+2, HALF_COLS);
        walls[7] = Wall(HALF_ROWS+3, HALF_COLS);
        walls[8] = Wall(HALF_ROWS+4, HALF_COLS);
        walls[9] = Wall(HALF_ROWS, HALF_COLS-1);
        walls[10] = Wall(HALF_ROWS, HALF_COLS-2);
        walls[11] = Wall(HALF_ROWS, HALF_COLS-3);
        walls[12] = Wall(HALF_ROWS, HALF_COLS-4);
        walls[13] = Wall(HALF_ROWS, HALF_COLS-5);
        walls[14] = Wall(HALF_ROWS, HALF_COLS-6);
        walls[15] = Wall(HALF_ROWS, HALF_COLS-7);
        walls[16] = Wall(HALF_ROWS, HALF_COLS+1);
        walls[17] = Wall(HALF_ROWS, HALF_COLS+2);
        walls[18] = Wall(HALF_ROWS, HALF_COLS+3);
        walls[19] = Wall(HALF_ROWS, HALF_COLS+4);
        walls[20] = Wall(HALF_ROWS, HALF_COLS+5);
        walls[21] = Wall(HALF_ROWS, HALF_COLS+6);
        walls[22] = Wall(HALF_ROWS, HALF_COLS+7);
        

        drawDoors();
    }
};

class Template_5i : public General_template {
public:
    Template_5i() : General_template(19,16,0)
    {
        drawOrtogonalCross(HALF_ROWS,HALF_COLS,3,6,0);     //19 walls      

        drawDoors();
    }
};

//wall & door
class Template_6 : public General_template {
public:
    Template_6() : General_template(10,17,0)
    {
        walls[0] = Wall((BOARD_ROWS/3+2)*2,1);
        walls[1] = Wall((BOARD_ROWS/3+2)*2,2);
        walls[2] = Wall((BOARD_ROWS/3+2)*2,3);
        walls[3] = Wall((BOARD_ROWS/3+2)*2,4);
        walls[4] = Wall((BOARD_ROWS/3+2)*2,5);
        walls[5] = Wall((BOARD_ROWS/3+2)*2,6);
        walls[6] = Wall((BOARD_ROWS/3+2)*2,7);
        
        walls[7] = Wall((BOARD_ROWS/3+2)*2,9);
        walls[8] = Wall((BOARD_ROWS/3+2)*2,10);
        walls[9] = Wall((BOARD_ROWS/3+2)*2+1,10);
        walls[10] = Wall((BOARD_ROWS/3+2)*2+2,10);
        
        doors[16] = Door((BOARD_ROWS/3+2)*2,8);

        drawDoors();
    }
};