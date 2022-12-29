#pragma once

#include "Board.hpp"
#include "Chaser.hpp"   //../enemies/
#include "Coward.hpp"
#include "Drunk.hpp"
#include "Shooter.hpp"
#include "Boom.hpp"
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
    Template_0i() : General_template(10,16,0)
    {
        drawRandom(10, 2, 2,BOARD_ROWS-2, BOARD_COLS-2,0);

        drawDoors();
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
    Template_4i() : General_template(15,16,1)
    {
        drawFilledSquare(HALF_ROWS-1, HALF_COLS-2, 3, 5, 0);

        drawDoors();

        enemies[0] = new Boom();
        enemies[0]->setDirection(def);
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
    Template_5() : General_template(19,16,0)
    {
        drawOrtogonalCross(HALF_ROWS,HALF_COLS,3,6,0);     //19 walls      

        drawDoors();
    }
};

//wall & door
class Template_6 : public General_template {
public:
    Template_6() : General_template(50,17,0)
    {
        int i = 0;
        i = drawHorizontalLine(BOARD_COLS/3, (BOARD_ROWS/3)*2,1,i);
        i = drawVerticalLine(BOARD_ROWS/3, (BOARD_ROWS/3)*2,BOARD_COLS/3,i);
        
        doors[16] = Door((BOARD_ROWS/3)*2,BOARD_COLS/3-4);

        drawDoors();
    }
};

//big  negative cross 
class Template_7 : public General_template {
public:
    Template_7() : General_template(161*4,16,1)
    {
        int i = 0;
        i = drawFilledSquare(1, 1, 8, 20, 0);   //126 walls
        i = drawFilledSquare(BOARD_ROWS-9, 1, 8, 20, i+1);   //126 walls
        i = drawFilledSquare(1, BOARD_COLS-21, 8, 20, i+1);   //126 walls
        i = drawFilledSquare(BOARD_ROWS-9, BOARD_COLS-21, 8, 20, i+1);   //126 walls

        drawDoors();

        enemies[0] = new Shooter();
        enemies[0]->setDirection(def);
    }
};

//central sub-chamber
class Template_8 : public General_template {
public:
    Template_8() : General_template(76,32,0)
    {
        drawEmptySquare(HALF_ROWS-5, HALF_COLS-13, 11, 27, 0);     //76 walls
        
        drawDoors();
        doors[16] = Door(HALF_ROWS-5,HALF_COLS-2);   //north doors
        doors[17] = Door(HALF_ROWS-5,HALF_COLS-1);
        doors[18] = Door(HALF_ROWS-5,HALF_COLS);
        doors[19] = Door(HALF_ROWS-5,HALF_COLS+1);
        doors[20] = Door(HALF_ROWS-5,HALF_COLS+2);
        doors[21] = Door(HALF_ROWS+5,HALF_COLS-2);   //south doors
        doors[22] = Door(HALF_ROWS+5,HALF_COLS-1);
        doors[23] = Door(HALF_ROWS+5,HALF_COLS);
        doors[24] = Door(HALF_ROWS+5,HALF_COLS+1);
        doors[25] = Door(HALF_ROWS+5,HALF_COLS+2);
        doors[26] = Door(HALF_ROWS-1,HALF_COLS-13);   //west doors
        doors[27] = Door(HALF_ROWS,HALF_COLS-13);
        doors[28] = Door(HALF_ROWS+1,HALF_COLS-13);
        doors[29] = Door(HALF_ROWS-1,HALF_COLS+13);   //est doors
        doors[30] = Door(HALF_ROWS,HALF_COLS+13);
        doors[31] = Door(HALF_ROWS+1,HALF_COLS+13);
    }
};

//radom wall blocks
class Template_9 : public General_template {
public:
    Template_9() : General_template(36,16,1)
    {
        int i = 0;
        int ry = rand()%(BOARD_ROWS-2)+1;
        int rx = rand()%(BOARD_COLS-3)+1;
        i = drawFilledSquare(ry, rx, 2, 3, i);   //15 walls
        ry = rand()%(BOARD_ROWS-2)+1;
        rx = rand()%(BOARD_COLS-3)+1;
        i = drawFilledSquare(ry, rx, 2, 3, i);   //15 walls
        ry = rand()%(BOARD_ROWS-2)+1;
        rx = rand()%(BOARD_COLS-3)+1;
        i = drawFilledSquare(ry, rx, 2, 3, i);   //15 walls
        ry = rand()%(BOARD_ROWS-2)+1;
        rx = rand()%(BOARD_COLS-3)+1;
        i = drawFilledSquare(ry, rx, 2, 3, i);   //15 walls
        ry = rand()%(BOARD_ROWS-2)+1;
        rx = rand()%(BOARD_COLS-3)+1;
        i = drawFilledSquare(ry, rx, 2, 3, i);   //15 walls
        ry = rand()%(BOARD_ROWS-2)+1;
        rx = rand()%(BOARD_COLS-3)+1;
        i = drawFilledSquare(ry, rx, 2, 3, i);   //15 walls


        drawDoors();

        enemies[0] = new Shooter();
        enemies[0]->setDirection(def);
    }
};

//random walls
class Template_10 : public General_template {
public:
    Template_10() : General_template(15,16,0)
    {
        int ry, rx;
        for(int i=0; i < 15; i++)
        {
            ry = rand()%(BOARD_ROWS-2)+2;
            rx = rand()%(BOARD_COLS-2)+2;
            walls[i] = Wall(ry, rx);
        }

        drawDoors();

        enemies[0] = new Shooter();
        enemies[0]->setDirection(def);
    }
};

//maze concentric
class Template_11 : public General_template {
public:
    Template_11() : General_template(332,16,4)
    {
        int i = 0;
        i = drawHorizontalLine(26, 2, 5,i);     
        i = drawHorizontalLine(26, 2, 36,i);
        i = drawHorizontalLine(26, BOARD_ROWS-3, 5,i);
        i = drawHorizontalLine(26, BOARD_ROWS-3, 36,i);    //104
        i = drawVerticalLine(8, 3, 5,i);
        i = drawVerticalLine(8, 14, 5,i);
        i = drawVerticalLine(8, 3, BOARD_COLS-6,i);
        i = drawVerticalLine(8, 14, BOARD_COLS-6,i);    //136

        i = drawHorizontalLine(47, 5, 10,i);
        i = drawHorizontalLine(47, BOARD_ROWS-6, 10,i);
        i = drawVerticalLine(9, 8, 10,i);
        i = drawVerticalLine(9, 8, BOARD_COLS-11,i);    //248

        i = drawHorizontalLine(21, 8, 11,i);
        i = drawHorizontalLine(21, 8, 35,i);
        i = drawHorizontalLine(21, BOARD_ROWS-9, 11,i);
        i = drawHorizontalLine(21, BOARD_ROWS-9, 35,i);    //332

        drawDoors();

        enemies[0] = new Chaser(5,9);
        enemies[0]->setDirection(def);
        enemies[1] = new Chaser(4,8);
        enemies[1]->setDirection(def);
        enemies[2] = new Chaser(4,BOARD_COLS-8);
        enemies[2]->setDirection(def);
        enemies[3] = new Chaser(BOARD_ROWS-6,BOARD_COLS-8);
        enemies[3]->setDirection(def);
    }
};