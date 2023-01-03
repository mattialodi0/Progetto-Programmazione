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

    int drawFilledSquareDoor(int start_y, int start_x, int height, int width, int i);

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

//left-bottom center subroom
class Template_6 : public General_template {
public:
    Template_6() : General_template(30,18,0)
    {
        int i = 0;
        i = drawHorizontalLine(BOARD_COLS/3, (BOARD_ROWS/3)*2,1,i);
        i = drawVerticalLine(BOARD_ROWS/3, (BOARD_ROWS/3)*2,BOARD_COLS/3,i);
        
        doors[16] = Door((BOARD_ROWS/3)*2,BOARD_COLS/3-4);
        doors[17] = Door((BOARD_ROWS/3)*2,BOARD_COLS/3-3);

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
    Template_8() : General_template(72,32,0)
    {
        drawEmptySquare(HALF_ROWS-5, HALF_COLS-13, 11, 27, 0);     //72 walls
        
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

//maze spyral
class Template_12 : public General_template {
public:
    Template_12() : General_template(233,16,0)
    {
        int i = 0;
        i = drawVerticalLine(21, 1, 7,i);
        i = drawHorizontalLine(51, BOARD_ROWS-4, 8,i);     
        i = drawVerticalLine(18, 4, BOARD_COLS-8,i);
        i = drawHorizontalLine(46, 3,14,i);  
        i = drawVerticalLine(15, 4, 14,i);
        i = drawHorizontalLine(38, 18,15,i);
        i = drawVerticalLine(12, 7, BOARD_COLS-15,i);
        i = drawHorizontalLine(32, 6, 21,i);
        
        drawDoors();
    }
};

//subroom closed doors
class Template_13 : public General_template {
public:
    Template_13() : General_template(60,19,0)
    {
        int i = 0;
        i = drawHorizontalLine(21, HALF_ROWS-5, HALF_COLS-10,i);
        i = drawHorizontalLine(21, HALF_ROWS+5, HALF_COLS-10,i);
        i = drawVerticalLine(9, HALF_ROWS-4, HALF_COLS-10,i);     
        i = drawVerticalLine(9, HALF_ROWS-4, HALF_COLS+10,i);
        
        doors[16] = Locked_Door(HALF_ROWS-5, HALF_COLS-1);
        doors[17] = Locked_Door(HALF_ROWS-5, HALF_COLS);
        doors[18] = Locked_Door(HALF_ROWS-5, HALF_COLS+1);

        drawDoors();
    }
};

//tempio
class Template_14 : public General_template {               //**************da fare
public:
    Template_14() : General_template(100,16,0)
    {
        int i = 0;
        i = drawVerticalLine(9, 8, 10,i);     
        i = drawHorizontalLine(10, 8, 11,i);
        i = drawHorizontalLine(6, 12, 11,i);
        i = drawHorizontalLine(10, 16, 11,i);

        drawDoors();
    }
};

//chrome subchambers
class Template_15 : public General_template {
public:
    Template_15() : General_template(306,44,0)
    {
        int i = 0;
        i = drawHorizontalLine(BOARD_COLS-9, 4, 1,i);
        i = drawVerticalLine(BOARD_ROWS-6, 1, BOARD_COLS-10,i);
        i = drawVerticalLine(BOARD_ROWS-6, 1, BOARD_COLS-9,i);
        i = drawHorizontalLine(BOARD_COLS-11, BOARD_ROWS-5, 10,i);
        i = drawVerticalLine(BOARD_ROWS-6, 5, 9,i);
        i = drawVerticalLine(BOARD_ROWS-6, 5, 8,i);
        i = drawHorizontalLine(HALF_COLS+5, 9, 10,i);
        i = drawVerticalLine(HALF_ROWS-2, 5, HALF_COLS+15,i);
        i = drawVerticalLine(HALF_ROWS-2, 5, HALF_COLS+16,i);
        i = drawHorizontalLine(HALF_COLS+5, 15, 19,i);
        i = drawVerticalLine(HALF_ROWS-2, 10, 17,i);
        i = drawVerticalLine(HALF_ROWS-2, 10, 18,i);

        int j = 16;
        j = drawFilledSquareDoor(HALF_ROWS-3,HALF_COLS-1,1,3,j);
        j = drawFilledSquareDoor(HALF_ROWS+3,HALF_COLS-1,1,3,j);
        j = drawFilledSquareDoor(4,HALF_COLS-5,1,3,j);
        j = drawFilledSquareDoor(BOARD_ROWS-5,HALF_COLS+4,1,3,j);
        j = drawFilledSquareDoor(HALF_ROWS-3,BOARD_COLS-10,2,2,j);
        j = drawFilledSquareDoor(HALF_ROWS+2,8,2,2,j);
        j = drawFilledSquareDoor(HALF_ROWS-1,HALF_COLS-16,2,2,j);
        j = drawFilledSquareDoor(HALF_ROWS-1,HALF_COLS+15,2,2,j);

        drawDoors();
    }
};

class Template_15i : public General_template {
public:
    Template_15i() : General_template(4*BOARD_COLS+6*BOARD_ROWS+300,50,0)
    {
        int i = 0;
        i = drawHorizontalLine(BOARD_COLS-9, 3, 1,i);
        i = drawHorizontalLine(BOARD_COLS-9, 4, 1,i);
        i = drawVerticalLine(BOARD_ROWS-6, 1, BOARD_COLS-10,i);
        i = drawVerticalLine(BOARD_ROWS-6, 1, BOARD_COLS-9,i);
        i = drawVerticalLine(BOARD_ROWS-6, 1, BOARD_COLS-8,i);
        i = drawHorizontalLine(BOARD_COLS-11, BOARD_ROWS-5, 10,i);
        i = drawHorizontalLine(BOARD_COLS-11, BOARD_ROWS-4, 10,i);
        i = drawVerticalLine(BOARD_ROWS-6, 5, 9,i);
        i = drawVerticalLine(BOARD_ROWS-6, 5, 8,i);
        i = drawVerticalLine(BOARD_ROWS-6, 5, 7,i);
        i = drawHorizontalLine(HALF_COLS+5, 9, 10,i);
        i = drawHorizontalLine(HALF_COLS+5, 8, 10,i);
        i = drawVerticalLine(HALF_ROWS-2, 5, HALF_COLS+15,i);
        i = drawVerticalLine(HALF_ROWS-2, 5, HALF_COLS+16,i);
        i = drawVerticalLine(HALF_ROWS-2, 5, HALF_COLS+17,i);
        i = drawHorizontalLine(HALF_COLS+5, 15, 19,i);
        i = drawHorizontalLine(HALF_COLS+5, 16, 19,i);
        i = drawVerticalLine(HALF_ROWS-2, 10, 16,i);
        i = drawVerticalLine(HALF_ROWS-2, 10, 17,i);
        i = drawVerticalLine(HALF_ROWS-2, 10, 18,i);

        int j = 16;
        j = drawFilledSquareDoor(3,HALF_COLS-1,2,3,j);

        drawDoors();
    }
};

//hexagonal chamber
class Template_16 : public General_template {
public:
    Template_16() : General_template(60,22,0)
    {
        int i = 0;
        int a = BOARD_ROWS/3-2;
        int b = BOARD_ROWS/3*2+2;
        int c = HALF_COLS-9;
        int d = HALF_COLS+9;
        i = drawHorizontalLine(19, a, c,i);
        i = drawHorizontalLine(19, b, c,i);
        walls[i] = Wall(a+1,c-1); i++;
        walls[i] = Wall(a+2,c-2); i++;
        walls[i] = Wall(a+3,c-3); i++;
        walls[i] = Wall(a+4,c-4); i++;
        walls[i] = Wall(a+5,c-5); i++;
        walls[i] = Wall(a+6,c-6); i++;
        
        walls[i] = Wall(a+1,d+1); i++;
        walls[i] = Wall(a+2,d+2); i++;
        walls[i] = Wall(a+3,d+3); i++;
        walls[i] = Wall(a+4,d+4); i++;
        walls[i] = Wall(a+5,d+5); i++;
        walls[i] = Wall(a+6,d+6); i++;

        walls[i] = Wall(b-1,c-1); i++;
        walls[i] = Wall(b-2,c-2); i++;
        walls[i] = Wall(b-3,c-3); i++;
        walls[i] = Wall(b-4,c-4); i++;
        walls[i] = Wall(b-5,c-5); i++;

        walls[i] = Wall(b-1,d+1); i++;
        walls[i] = Wall(b-2,d+2); i++;
        walls[i] = Wall(b-3,d+3); i++;
        walls[i] = Wall(b-4,d+4); i++;
        walls[i] = Wall(b-5,d+5); i++;

        doors[16] = Door(a,HALF_COLS-1);
        doors[17] = Door(a,HALF_COLS);
        doors[18] = Door(a,HALF_COLS+1);
        doors[19] = Door(b,HALF_COLS-1);
        doors[20] = Door(b,HALF_COLS);
        doors[21] = Door(b,HALF_COLS+1);

        drawDoors();
    }
};

//castle
//bomb room