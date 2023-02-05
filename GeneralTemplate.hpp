#pragma once

#include "Board.hpp"
#include "Chaser.hpp"   //../enemies/
#include "Coward.hpp"
#include "Drunk.hpp"
#include "Shooter.hpp"
#include "Boom.hpp"
#include "Artifact.hpp"
#include "Flyer.hpp"
#include "Stalker.hpp"
#include "Turret.hpp"
#include "room_objects/Door.hpp"
#include "room_objects/Wall.hpp"

#include <cstdlib>

#define HALF_COLS BOARD_COLS/2
#define HALF_ROWS BOARD_ROWS/2
const int max_n_enemies=6;
const int tols=6;



class General_template {
public:
    Drawable* walls;
    Drawable* doors;
    Drawable* artifact;
    pEn* enemies;
    int walls_num; 
    int doors_num;
    int enemies_num=0;
    int artifact_num=0;
    int my_xp=3;
    bool is_north_door_locked, is_south_door_locked, is_west_door_locked, is_est_door_locked;
    bool need_doors;
    bool has_north_door, has_south_door, has_west_door, has_est_door;
    bool must_complete = true;
    General_template();
    General_template(int w, int d, int e, int a);
    ~General_template();

    void drawDoors();

    void createEnemies(bool is_random_enemies,bool is_random_coords,int x, int y,int chosen,int ite,int room_pos,Board &game_board,pEn enemies[]);
    //in chosen enemies 0=drunk,1=coward,2=shooter,3=chaser,4=boom,5=flyer,6=stalker
    int drawRandom(int num, int ya, int xa, int yb, int xb, int i);
    int drawHorizontalLine( int num, int start_y, int start_x, int i);
    int drawVerticalLine( int num, int start_y, int start_x, int i);
    int drawFilledSquare(int start_y, int start_x, int height, int width, int i);
    int drawEmptySquare(int start_y, int start_x, int height, int width, int i);
    int drawOrtogonalCross(int start_y, int start_x, int h_height, int h_width, int i);

    int drawFilledSquareDoor(int start_y, int start_x, int height, int width, int i);
    int drawFilledSquareLockedDoor(int start_y, int start_x, int height, int width, int i);
    int drawFilledSquareNoDoor(int start_y, int start_x, int height, int width, int i);

};



class Template_0 : public General_template {
public:
    Template_0(int n,Board &game_board) : General_template(0,16,0,0)
    {
        drawDoors();
    }
};

//muri casuali
class Template_1 : public General_template {
public:
    Template_1(int n,Board &game_board) : General_template(10,16,rand() % (max_n_enemies+1),1)
    {
        drawRandom(10, 2, 2,BOARD_ROWS-3, BOARD_COLS-3,0);

        drawDoors();
        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);
    }
};

//orizontal line
class Template_2 : public General_template {
public:
    Template_2(int n,Board &game_board) : General_template(8,16,rand() % (max_n_enemies+1),1)
    {
        drawHorizontalLine(8, BOARD_ROWS/3*2, 1, 0);

        drawDoors();
        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);
    }
};

//verical line
class Template_3 : public General_template {
public:
    Template_3(int n,Board &game_board) : General_template(7,16,rand() % (max_n_enemies+1),1)
    {
        drawVerticalLine(7, 1, (BOARD_ROWS/3+2)*2, 0);

        drawDoors();
                int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);
    }
};

//filled square
class Template_4 : public General_template {
public:
    Template_4(int n,Board &game_board) : General_template(15,16,rand() % (max_n_enemies+1),1)
    {
        drawFilledSquare(HALF_ROWS-1, HALF_COLS-2, 3, 5, 0);

        drawDoors();
        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);
    }
};

//empty square
class Template_4i : public General_template {
public:
    Template_4i(int n,Board &game_board) : General_template(12,16,rand() % (max_n_enemies+1),1)
    {
        drawEmptySquare(HALF_ROWS-1, HALF_COLS-2, 3, 5, 0);

        drawDoors();
                int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);
    }
};

//ortogonal cross
class Template_5 : public General_template {
public:
    Template_5(int n,Board &game_board) : General_template(19,16,rand() % (max_n_enemies+1),1)
    {
        
        drawOrtogonalCross(HALF_ROWS,HALF_COLS,3,6,0);     //19 walls      

        drawDoors();
                int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);
    }
};

//left-bottom center subroom
class Template_6 : public General_template {
public:
    Template_6(int n,Board &game_board) : General_template(30,18,rand() % (max_n_enemies+1),1)
    {
        
        int i = 0;
        i = drawHorizontalLine(BOARD_COLS/3, (BOARD_ROWS/3)*2,1,i);
        i = drawVerticalLine(BOARD_ROWS/3, (BOARD_ROWS/3)*2,BOARD_COLS/3,i);
        
        doors[16] = Door((BOARD_ROWS/3)*2,BOARD_COLS/3-4);
        doors[17] = Door((BOARD_ROWS/3)*2,BOARD_COLS/3-3);

        drawDoors();
                int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);
    }
};

//big  negative cross 
class Template_7 : public General_template {
public:
    Template_7(int n,Board &game_board) : General_template(161*4,16,rand() % (max_n_enemies+1),1)
    {
        need_doors = true;
        has_north_door = true; has_south_door = true; has_west_door = true; has_est_door = true;
        int i = 0;
        i = drawFilledSquare(1, 1, 8, 20, 0);   //126 walls
        i = drawFilledSquare(BOARD_ROWS-9, 1, 8, 20, i+1);   //126 walls
        i = drawFilledSquare(1, BOARD_COLS-21, 8, 20, i+1);   //126 walls
        i = drawFilledSquare(BOARD_ROWS-9, BOARD_COLS-21, 8, 20, i+1);   //126 walls

        drawDoors();
                int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);

    }
};

//central sub-chamber no doors
class Template_8 : public General_template {
public:
    Template_8(int n,Board &game_board) : General_template(72,32,rand() % (max_n_enemies+1),1)
    {
        drawEmptySquare(HALF_ROWS-5, HALF_COLS-13, 11, 27, 0);     //72 walls
        
        drawDoors();
        doors[16] = No_Door(HALF_ROWS-5,HALF_COLS-2);   //north doors
        doors[17] = No_Door(HALF_ROWS-5,HALF_COLS-1);
        doors[18] = No_Door(HALF_ROWS-5,HALF_COLS);
        doors[19] = No_Door(HALF_ROWS-5,HALF_COLS+1);
        doors[20] = No_Door(HALF_ROWS-5,HALF_COLS+2);
        doors[21] = No_Door(HALF_ROWS+5,HALF_COLS-2);   //south doors
        doors[22] = No_Door(HALF_ROWS+5,HALF_COLS-1);
        doors[23] = No_Door(HALF_ROWS+5,HALF_COLS);
        doors[24] = No_Door(HALF_ROWS+5,HALF_COLS+1);
        doors[25] = No_Door(HALF_ROWS+5,HALF_COLS+2);
        doors[26] = No_Door(HALF_ROWS-1,HALF_COLS-13);   //west doors
        doors[27] = No_Door(HALF_ROWS,HALF_COLS-13);
        doors[28] = No_Door(HALF_ROWS+1,HALF_COLS-13);
        doors[29] = No_Door(HALF_ROWS-1,HALF_COLS+13);   //est doors
        doors[30] = No_Door(HALF_ROWS,HALF_COLS+13);
        doors[31] = No_Door(HALF_ROWS+1,HALF_COLS+13);
        
        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);
    }
};

//radom wall blocks
class Template_9 : public General_template {
public:
    Template_9(int n,Board &game_board) : General_template(36,16,rand() % (max_n_enemies+1),1)
    {
        int i = 0;
        int ry = rand()%(BOARD_ROWS-4)+1;
        int rx = rand()%(BOARD_COLS-4)+1;
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
                int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);

    }
};

//random walls
class Template_10 : public General_template {
public:
    Template_10(int n,Board &game_board) : General_template(15,16,rand() % (max_n_enemies+1),1)
    {
        int ry, rx;
        for(int i=0; i < 15; i++)
        {
            ry = rand()%(BOARD_ROWS-4)+2;
            rx = rand()%(BOARD_COLS-4)+2;
            walls[i] = Wall(ry, rx);
        }

        drawDoors();
                int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);

    }
};

//maze concentric
class Template_11 : public General_template {
public:
    Template_11(int n,Board &game_board) : General_template(332,16,rand() % (max_n_enemies+1),1)
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
        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);
       
    }
};

//maze spyral
class Template_12 : public General_template {
public:
    Template_12(int n,Board &game_board) : General_template(233,16,rand() % (max_n_enemies+1),1)
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
                int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);
    }
};

//subroom doors
class Template_13 : public General_template {
public:
    Template_13(int n,Board &game_board) : General_template(60,24,rand() % (max_n_enemies+1),1)
    {
        int i = 0;
        i = drawHorizontalLine(21, HALF_ROWS-5, HALF_COLS-10,i);
        i = drawHorizontalLine(21, HALF_ROWS+5, HALF_COLS-10,i);
        i = drawVerticalLine(9, HALF_ROWS-4, HALF_COLS-10,i);     
        i = drawVerticalLine(9, HALF_ROWS-4, HALF_COLS+10,i);
        
        doors[16] = No_Door(HALF_ROWS-5, HALF_COLS-1);
        doors[17] = No_Door(HALF_ROWS-5, HALF_COLS);
        doors[18] = No_Door(HALF_ROWS-5, HALF_COLS+1);
        doors[19] = No_Door(HALF_ROWS+5, HALF_COLS-1);
        doors[20] = No_Door(HALF_ROWS+5, HALF_COLS);
        doors[21] = No_Door(HALF_ROWS+5, HALF_COLS+1);
        doors[22] = No_Door(HALF_ROWS, HALF_COLS-10);
        doors[23] = No_Door(HALF_ROWS, HALF_COLS+10);        

        drawDoors();
        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
            createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);
    }
};

//tempio
class Template_14 : public General_template {
public:
    Template_14(int n,Board &game_board) : General_template(100,16,rand() % (max_n_enemies+1),1)
    {
        need_doors  = true;
        has_north_door = false; has_south_door = false; has_west_door = true; has_est_door = true;
        int i = 0;
        int x = 12;
        i = drawFilledSquare(6, x, 2, 3, i);     
        i = drawFilledSquare(BOARD_ROWS-8, x, 2, 3, i);
        i = drawFilledSquare(6, x+10, 2, 3, i);     
        i = drawFilledSquare(BOARD_ROWS-8, x+10, 2, 3, i);
        i = drawFilledSquare(6, x+20, 2, 3, i);     
        i = drawFilledSquare(BOARD_ROWS-8, x+20, 2, 3, i);
        i = drawFilledSquare(6, x+30, 2, 3, i);     
        i = drawFilledSquare(BOARD_ROWS-8, x+30, 2, 3, i);
        i = drawFilledSquare(6, x+40, 2, 3, i);     
        i = drawFilledSquare(BOARD_ROWS-8, x+40, 2, 3, i);


        drawDoors();
        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
            createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);
    }
};

//chrome subchambers
class Template_15 : public General_template {
public:
    Template_15(int n,Board &game_board) : General_template(306,52,rand() % (max_n_enemies+1),1)
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
        j = drawFilledSquareLockedDoor(HALF_ROWS-6,HALF_COLS+15,2,2,j);
        j = drawFilledSquareLockedDoor(HALF_ROWS+5,HALF_COLS-16,2,2,j);

        drawDoors();
        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);
    }
};

//hexagonal chamber
class Template_16 : public General_template {
public:
    Template_16(int n,Board &game_board) : General_template(52,30,rand() % (max_n_enemies+1),1)
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
        //walls[i] = Wall(a+3,c-3); i++;
        //walls[i] = Wall(a+4,c-4); i++;
        walls[i] = Wall(a+5,c-5); i++;
        walls[i] = Wall(a+6,c-6); i++;
        
        walls[i] = Wall(a+1,d+1); i++;
        walls[i] = Wall(a+2,d+2); i++;
        //walls[i] = Wall(a+3,d+3); i++;
        //walls[i] = Wall(a+4,d+4); i++;
        walls[i] = Wall(a+5,d+5); i++;
        walls[i] = Wall(a+6,d+6); i++;

        walls[i] = Wall(b-1,c-1); i++;
        walls[i] = Wall(b-2,c-2); i++;
        //walls[i] = Wall(b-3,c-3); i++;
        //walls[i] = Wall(b-4,c-4); i++;
        walls[i] = Wall(b-5,c-5); i++;

        walls[i] = Wall(b-1,d+1); i++;
        walls[i] = Wall(b-2,d+2); i++;
        //walls[i] = Wall(b-3,d+3); i++;
        //walls[i] = Wall(b-4,d+4); i++;
        walls[i] = Wall(b-5,d+5); i++;

        doors[16] = No_Door(a,HALF_COLS-1);
        doors[17] = No_Door(a,HALF_COLS);
        doors[18] = No_Door(a,HALF_COLS+1);
        doors[19] = No_Door(b,HALF_COLS-1);
        doors[20] = No_Door(b,HALF_COLS);
        doors[21] = No_Door(b,HALF_COLS+1);
        doors[22] = No_Door(a+3,c-3);
        doors[23] = No_Door(a+4,c-4);
        doors[24] = No_Door(a+3,d+3);
        doors[25] = No_Door(a+4,d+4);
        doors[26] = No_Door(b-3,c-3);
        doors[27] = No_Door(b-4,c-4);
        doors[28] = No_Door(b-3,d+3);
        doors[29] = No_Door(b-4,d+4);

        drawDoors();
        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        artifact[0] = Artifact(6,6);
    }
};

//4 square x
class Template_17 : public General_template {
public:
    Template_17(int n,Board &game_board) : General_template(160,16,rand() % (max_n_enemies+1),1)
    {
        int i = 0;
        i = drawFilledSquare(HALF_ROWS/2-1, HALF_COLS/2-4, 4, 10, i);
        i = drawFilledSquare((HALF_ROWS/2)*3-2, HALF_COLS/2-4, 4, 10, i);
        i = drawFilledSquare(HALF_ROWS/2-1, (HALF_COLS/2)*3-3, 4, 10, i);
        i = drawFilledSquare((HALF_ROWS/2)*3-2, (HALF_COLS/2)*3-3, 4, 10, i);

        drawDoors();

        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//4 square +
class Template_18 : public General_template {
public:
    Template_18(int n,Board &game_board) : General_template(108,16,rand() % (max_n_enemies+1),1)
    {
        int i = 0;
        i = drawFilledSquare(HALF_ROWS/2-2, HALF_COLS-4, 3, 9, i);
        i = drawFilledSquare(BOARD_ROWS-HALF_ROWS/2-1, HALF_COLS-4, 3, 9, i);
        i = drawFilledSquare(HALF_ROWS-1, HALF_COLS/2-6, 3, 9, i);
        i = drawFilledSquare(HALF_ROWS-1, (HALF_COLS/2)*3, 3, 9, i);

        drawDoors();

        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//random cross
class Template_19 : public General_template {
public:
    Template_19(int n,Board &game_board) : General_template(35,16,rand() % (max_n_enemies+1),1)
    {
        int i = 0;
        int ry = rand()%(BOARD_ROWS-8)+3;
        int rx = rand()%(BOARD_COLS-14)+6;
        i = drawOrtogonalCross(ry, rx, 1, 2, i);   //7 walls
        ry = rand()%(BOARD_ROWS-8)+3;
        rx = rand()%(BOARD_COLS-14)+6;
        i = drawOrtogonalCross(ry, rx, 1, 2, i);   //7 walls
        ry = rand()%(BOARD_ROWS-8)+3;
        rx = rand()%(BOARD_COLS-14)+6;
        i = drawOrtogonalCross(ry, rx, 1, 2, i);   //7 walls
        ry = rand()%(BOARD_ROWS-8)+3;
        rx = rand()%(BOARD_COLS-14)+6;
        i = drawOrtogonalCross(ry, rx, 1, 2, i);   //7 walls
        ry = rand()%(BOARD_ROWS-8)+3;
        rx = rand()%(BOARD_COLS-14)+6;
        i = drawOrtogonalCross(ry, rx, 1, 2, i);   //7 walls        

        drawDoors();

        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//horizontal S
class Template_20 : public General_template {
public:
    Template_20(int n,Board &game_board) : General_template(85,19,rand() % (max_n_enemies+1),1)
    {
        int i = 0;
        i = drawHorizontalLine(20, HALF_ROWS-4, HALF_COLS-20, i);
        i = drawHorizontalLine(20, HALF_ROWS+4, HALF_COLS+1, i);
        i = drawVerticalLine(9, HALF_ROWS-4, HALF_COLS, i);
        i = drawVerticalLine(9, HALF_ROWS-4, HALF_COLS-21, i);
        i = drawVerticalLine(9, HALF_ROWS-4, HALF_COLS+21, i);
        i = drawHorizontalLine(9, HALF_ROWS-4, HALF_COLS+12, i);
        i = drawHorizontalLine(9, HALF_ROWS+4, HALF_COLS-20, i);

        doors[16] = Locked_Door(HALF_ROWS-1, HALF_COLS);
        doors[17] = Locked_Door(HALF_ROWS, HALF_COLS);
        doors[18] = Locked_Door(HALF_ROWS+1, HALF_COLS);

        drawDoors();

        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//4 angoli 
class Template_21 : public General_template {
public:
    Template_21(int n,Board &game_board) : General_template(80,16,rand() % (max_n_enemies+1),1)
    {
        int i = 0;
        i = drawHorizontalLine(16, 4, 11, i);
        i = drawVerticalLine(6, 4, 10, i);
        i = drawHorizontalLine(16, 4, BOARD_COLS-27, i);
        i = drawVerticalLine(6, 4, BOARD_COLS-11, i);
        i = drawHorizontalLine(16, BOARD_ROWS-5, 11, i);
        i = drawVerticalLine(6, BOARD_ROWS-10, 10, i);
        i = drawHorizontalLine(16, BOARD_ROWS-5, BOARD_COLS-27, i);
        i = drawVerticalLine(6, BOARD_ROWS-10, BOARD_COLS-11, i);   

        drawDoors();

        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//pacman, i nemici dovrebbero  essere tutti chaser
class Template_22 : public General_template {
public:
    Template_22(int n,Board &game_board) : General_template(281,16,3,1)
    {
        int i = 0;
        i = drawHorizontalLine(7, HALF_ROWS+1, HALF_COLS-3, i);     //strutture centrali
        i = drawVerticalLine(3, HALF_ROWS-1, HALF_COLS-4, i);
        i = drawVerticalLine(3, HALF_ROWS-1, HALF_COLS+4, i);
        walls[i] = Wall(HALF_ROWS-1,HALF_COLS-2); i++;
        walls[i] = Wall(HALF_ROWS-1,HALF_COLS+2); i++;
        walls[i] = Wall(HALF_ROWS-1,HALF_COLS-3); i++;
        walls[i] = Wall(HALF_ROWS-1,HALF_COLS+3); i++;
        i = drawHorizontalLine(7, 8, 30, i);
        walls[i] = Wall(9,HALF_COLS); i++;
        i = drawEmptySquare(3, HALF_COLS-1, 3, 3, i);
        i = drawOrtogonalCross(16, HALF_COLS, 1, 2, i);
        i = drawHorizontalLine(4, 20, 28, i);
        i = drawHorizontalLine(4, 21, 28, i);
        i = drawHorizontalLine(4, 20, 35, i);
        i = drawHorizontalLine(4, 21, 35, i);

        i = drawEmptySquare(2, 5, 2, 5, i);             //strutture a sinistra
        i = drawEmptySquare(2, 15, 2, 5, i);
        i = drawVerticalLine(8, 1, 24, i);
        i = drawEmptySquare(6, 5, 3, 5, i);
        i = drawVerticalLine(5, 6, 17, i);
        i = drawHorizontalLine(9, 11, 13, i);
        i = drawVerticalLine(4, 11, 7, i);
        i = drawHorizontalLine(4, 14, 8, i);
        i = drawEmptySquare(16, 16, 3, 9, i);
        walls[i] = Wall(14,20); i++;
        walls[i] = Wall(15,20); i++;
        walls[i] = Wall(19,20); i++;
        i = drawEmptySquare(BOARD_ROWS-4, 11, 3, 5, i);
        i = drawVerticalLine(2, BOARD_ROWS-3, 22, i);
        i = drawHorizontalLine(8, 17, 1, i);
        walls[i] = Wall(BOARD_ROWS-5,5); i++;
        walls[i] = Wall(BOARD_ROWS-4,5); i++;
        i = drawOrtogonalCross(16, HALF_COLS, 1, 2, i);

        i = drawEmptySquare(2, BOARD_COLS-10, 2, 5, i);     //strutture simmetriche a desta
        i = drawEmptySquare(2, BOARD_COLS-20, 2, 5, i);
        i = drawVerticalLine(8, 1, BOARD_COLS-25, i);
        i = drawEmptySquare(6, BOARD_COLS-10, 3, 5, i);
        i = drawVerticalLine(5, 6, BOARD_COLS-18, i);
        i = drawHorizontalLine(9, 11, BOARD_COLS-22, i);
        i = drawVerticalLine(4, 11, BOARD_COLS-8, i);
        i = drawHorizontalLine(4, 14, BOARD_COLS-12, i);
        i = drawEmptySquare(16, BOARD_COLS-25, 3, 9, i);
        walls[i] = Wall(14,BOARD_COLS-21); i++;
        walls[i] = Wall(15,BOARD_COLS-21); i++;
        walls[i] = Wall(19,BOARD_COLS-21); i++;
        i = drawEmptySquare(BOARD_ROWS-4, BOARD_COLS-16, 3, 5, i);
        i = drawVerticalLine(2, BOARD_ROWS-3, BOARD_COLS-23, i);
        i = drawHorizontalLine(8, 17, BOARD_COLS-9, i);
        walls[i] = Wall(BOARD_ROWS-5,BOARD_COLS-5); i++;
        walls[i] = Wall(BOARD_ROWS-4,BOARD_COLS-5); i++;
        

        drawDoors();
        
        int chosen_enemies[enemies_num] = {3,3,3};
        int x_chosen[enemies_num] = {HALF_COLS-2, HALF_COLS, HALF_COLS+2};
        int y_chosen[enemies_num] = {HALF_ROWS, HALF_ROWS, HALF_ROWS};
        for(int i=0;i<this->enemies_num;i++){   
            createEnemies(false,false,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }        

        artifact[0] = Artifact(6,6);
    }
};

//verical blocking wall right 
class Template_23 : public General_template {
public:
    Template_23(int n,Board &game_board) : General_template((BOARD_ROWS-2)*5,16,rand() % (max_n_enemies+1),1)
    {
        int i = 0;
        i = drawVerticalLine(BOARD_ROWS-2, 1, BOARD_COLS-15, i);
        i = drawVerticalLine(BOARD_ROWS-2, 1, BOARD_COLS-14, i);
        i = drawVerticalLine(BOARD_ROWS-2, 1, BOARD_COLS-13, i);
        i = drawVerticalLine(BOARD_ROWS-2, 1, BOARD_COLS-12, i);
        i = drawVerticalLine(BOARD_ROWS-2, 1, BOARD_COLS-11, i);       

        drawDoors();

        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//verical blocking wall left 
class Template_24 : public General_template {
public:
    Template_24(int n,Board &game_board) : General_template((BOARD_ROWS-2)*5,16,rand() % (max_n_enemies+1),1)
    {
        int i = 0;
        i = drawVerticalLine(BOARD_ROWS-2, 1, 14, i);
        i = drawVerticalLine(BOARD_ROWS-2, 1, 13, i);
        i = drawVerticalLine(BOARD_ROWS-2, 1, 12, i);
        i = drawVerticalLine(BOARD_ROWS-2, 1, 11, i);   
        i = drawVerticalLine(BOARD_ROWS-2, 1, 10, i);       

        drawDoors();

        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//horizontal blocking wall up 
class Template_25 : public General_template {
public:
    Template_25(int n,Board &game_board) : General_template((BOARD_COLS-2)*2,16,rand() % (max_n_enemies+1),1)
    {
        int i = 0;
        i = drawHorizontalLine(BOARD_COLS-2, 3, 1, i);
        i = drawHorizontalLine(BOARD_COLS-2, 4, 1, i);   
     

        drawDoors();

        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//horizontal blocking wall down 
class Template_26 : public General_template {
public:
    Template_26(int n,Board &game_board) : General_template((BOARD_COLS-2)*2,16,rand() % (max_n_enemies+1),1)
    {
        int i = 0;
        i = drawHorizontalLine(BOARD_COLS-2, BOARD_ROWS-5, 1, i);
        i = drawHorizontalLine(BOARD_COLS-2, BOARD_ROWS-4, 1, i);   

        drawDoors();

        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        //chosen_enemies={}
        //x_chosen={}
        //y_chosen={}
        for(int i=0;i<this->enemies_num;i++){   
            createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//turret boss
class Template_27 : public General_template {
public:
    Template_27(int n,Board &game_board) : General_template(24,16,1,1)
    {
        int i = 0;   
        i = drawFilledSquare(HALF_ROWS/2,(HALF_COLS/2)*3-1,2,3,i);
        i = drawFilledSquare(HALF_ROWS/2,HALF_COLS/2-1,2,3,i);
        i = drawFilledSquare((HALF_ROWS/2)*3,(HALF_COLS/2)*3-1,2,3,i);
        i = drawFilledSquare((HALF_ROWS/2)*3,HALF_COLS/2-1,2,3,i);

        drawDoors();

        int chosen_enemies[enemies_num] = {7};
        int x_chosen[enemies_num] = {HALF_COLS};
        int y_chosen[enemies_num] = {HALF_ROWS};
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(false,false,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//4 turret
class Template_28 : public General_template {
public:
    Template_28(int n,Board &game_board) : General_template(0,16,rand() % (max_n_enemies-3) +4,1)
    {
        drawDoors();

        int chosen_enemies[enemies_num] = {7,7,7,7};
        int x_chosen[enemies_num] = {HALF_COLS/2, (HALF_COLS/2)*3, HALF_COLS/2, (HALF_COLS/2)*3};
        int y_chosen[enemies_num] = {HALF_ROWS/2, HALF_ROWS/2, (HALF_ROWS/2)*3, (HALF_ROWS/2)*3};
        for(int i=0;i<4;i++){   
            createEnemies(false,false,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
        for(int i=4;i<this->enemies_num;i++){   
            createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//16 turret
class Template_29 : public General_template {
public:
    Template_29(int n,Board &game_board) : General_template(0,16,30,0)
    {
        need_doors = true; has_west_door = true; has_est_door = true;
        must_complete = false;

        drawDoors();

        int chosen_enemies[enemies_num] = {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7};
        int x_chosen[enemies_num] = {12,13,14,22,23,24,32,33,34,42,43,44,52,53,54,12,13,14,22,23,24,32,33,34,42,43,44,52,53,54};
        int y_chosen[enemies_num] = {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18};
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(false,false,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }
    }
};

//wall horizontal north rand
class Template_30 : public General_template {
public:
    Template_30(int n,Board &game_board) : General_template((BOARD_COLS-2)*2,20,rand() % (max_n_enemies+1),1)
    {
        int r = rand() % 5 + 3;
        drawHorizontalLine(BOARD_COLS-2, r, 1, 0);
        int f = rand() % 4;
        int t = rand() % (BOARD_COLS-10) + 5;
        if(f == 0) {
            doors[16] = Locked_Door(r,t);
            doors[17] = Locked_Door(r,t+1);
            doors[18] = Locked_Door(r,t+2);
            doors[19] = Locked_Door(r,t+3);
        }
        else {
            doors[16] = No_Door(r,t);
            doors[17] = No_Door(r,t+1);
            doors[18] = No_Door(r,t+2);
            doors[19] = No_Door(r,t+3);
        }   

        drawDoors();

        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        for(int i=0;i<this->enemies_num;i++){   
            createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//wall horizontal south rand
class Template_31 : public General_template {
public:
    Template_31(int n,Board &game_board) : General_template((BOARD_COLS-2)*2,20,rand() % (max_n_enemies+1),1)
    {
        int r = rand() % 5 + HALF_ROWS+5;
        drawHorizontalLine(BOARD_COLS-2, r, 1, 0);
        int f = rand() % 4;
        int t = rand() % (BOARD_COLS-9) + 5;
        if(f == 0) {
            doors[16] = Locked_Door(r,t);
            doors[17] = Locked_Door(r,t+1);
            doors[18] = Locked_Door(r,t+2);
            doors[19] = Locked_Door(r,t+3);
        }
        else {
            doors[16] = No_Door(r,t);
            doors[17] = No_Door(r,t+1);
            doors[18] = No_Door(r,t+2);
            doors[19] = No_Door(r,t+3);
        }   

        drawDoors();

        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        for(int i=0;i<this->enemies_num;i++){   
            createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//wall vertical west rand
class Template_32 : public General_template {
public:
    Template_32(int n,Board &game_board) : General_template((BOARD_COLS-2)*2,18,rand() % (max_n_enemies+1),1)
    {
        int r = rand() % 10 + 10;
        drawVerticalLine(BOARD_ROWS-2, 1, r, 0);
        int f = rand() % 4;
        int t = rand() % (BOARD_ROWS-7) + 3;
        if(f == 0) {
            doors[16] = Locked_Door(t,r);
            doors[17] = Locked_Door(t+1,r);
        }
        else {
            doors[16] = No_Door(t,r);
            doors[17] = No_Door(t+1,r);
        }   

        drawDoors();

        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        for(int i=0;i<this->enemies_num;i++){   
            createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//wall vertical est rand
class Template_33 : public General_template {
public:
    Template_33(int n,Board &game_board) : General_template((BOARD_COLS-2)*2,18,rand() % (max_n_enemies+1),1)
    {
        int r = rand() % 10 + BOARD_COLS-20;
        drawVerticalLine(BOARD_ROWS-2, 1, r, 0);
        int f = rand() % 4;
        int t = rand() % (BOARD_ROWS-7) + 3;
        if(f == 0) {
            doors[16] = Locked_Door(t,r);
            doors[17] = Locked_Door(t+1,r);
        }
        else {
            doors[16] = No_Door(t,r);
            doors[17] = No_Door(t+1,r);
        }   

        drawDoors();

        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        for(int i=0;i<this->enemies_num;i++){   
            createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//4 rand subchamber
class Template_34 : public General_template {
public:
    Template_34(int n,Board &game_board) : General_template(BOARD_COLS+BOARD_ROWS-4,28,rand() % (max_n_enemies+1),1)
    {
        int i = 0;
        int rx1 = (rand() % (HALF_COLS-12)) +5;   //primo muro
        int rx2 = (rand() % 2) * (HALF_COLS);
        int rx = rx1+rx2;
        i = drawVerticalLine(BOARD_ROWS-2, 1, rx, i);

        int ry1 = (rand() % (HALF_ROWS-5)) +3;   //secondo muro
        int ry2 = (rand() % 2) * (HALF_ROWS);
        int ry = ry1+ry2;
        i = drawHorizontalLine(BOARD_COLS-2, ry, 1, i);

        int r = (rand() % (ry-3)) +1;
        doors[16] = No_Door(r,rx);
        doors[17] = No_Door(r+1,rx);
        r = (rand() % (BOARD_ROWS-ry-3)) +ry +1;
        doors[18] = No_Door(r,rx);
        doors[19] = No_Door(r+1,rx);
        r = rand() % (rx-4) +0;
        doors[20] = No_Door(ry,r);
        doors[21] = No_Door(ry,r+1);
        doors[22] = No_Door(ry,r+2);
        doors[23] = No_Door(ry,r+3);
        r = rand() % (BOARD_COLS-rx-5) +rx +1;
        doors[24] = No_Door(ry,r);
        doors[25] = No_Door(ry,r+1);
        doors[26] = No_Door(ry,r+2);
        doors[27] = No_Door(ry,r+3);
      
        drawDoors();

        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        for(int i=0;i<this->enemies_num;i++){   
            createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//3 rand subchamber vertical
class Template_35 : public General_template {
public:
    Template_35(int n,Board &game_board) : General_template(BOARD_COLS+BOARD_ROWS-4,24,rand() % (max_n_enemies+1),1)
    { 
        int i = 0;
        int rx1 = (rand() % (HALF_COLS-20)) +10;   //primo muro
        int rx2 = (rand() % 2) * (HALF_COLS);
        int rx = rx1+rx2;
        i = drawVerticalLine(BOARD_ROWS-2, 1, rx, i);
        int ry1 = (rand() % (HALF_ROWS-6)) +4;   //secondo muro
        int ry2 = (rand() % 2) * (HALF_ROWS);
        int ry = ry1+ry2;
        int f;
        if(rx2 > 1) {
            f = 1;
            i = drawHorizontalLine(rx-1, ry, f, i);
        }
        else {
            f = rx+1;
            i = drawHorizontalLine(BOARD_COLS-rx-2, ry, f, i);
        }

        int r = (rand() % (ry-3)) +1;
        doors[16] = No_Door(r,rx);
        doors[17] = No_Door(r+1,rx);
        r = (rand() % (BOARD_ROWS-ry-3)) +ry +1;
        doors[18] = No_Door(r,rx);
        doors[19] = No_Door(r+1,rx);
        r = (rand() % (BOARD_COLS-rx-5)) +f;
        doors[20] = No_Door(ry,r);
        doors[21] = No_Door(ry,r+1);
        doors[22] = No_Door(ry,r+2);
        doors[23] = No_Door(ry,r+3);
      
        drawDoors();

        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        for(int i=0;i<this->enemies_num;i++){   
            createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//3 rand subchamber horizontal
class Template_36 : public General_template {
public:
    Template_36(int n,Board &game_board) : General_template(BOARD_COLS+BOARD_ROWS-4,26,rand() % (max_n_enemies+1),1)
    {
        int i = 0;
        int ry1 = (rand() % (HALF_ROWS-5)) +3;   //primo muro
        int ry2 = (rand() % 2) * (HALF_ROWS);
        int ry = ry1+ry2;
        i = drawHorizontalLine(BOARD_COLS-2, ry, 1, i);
        int rx1 = (rand() % (HALF_COLS-20)) +10;   //secondo muro
        int rx2 = (rand() % 2) * (HALF_COLS);
        int rx = rx1+rx2;
        int f;
        if(ry2 > 1) {
            f = 1;
            i = drawVerticalLine(ry-1, f, rx, i);
        }
        else {
            f = ry+1;
            i = drawVerticalLine(BOARD_ROWS-ry-2, f, rx, i);
        }

        int r = rand() % (rx-4) +0;
        doors[16] = No_Door(ry,r);
        doors[17] = No_Door(ry,r+1);
        doors[18] = No_Door(ry,r+2);
        doors[19] = No_Door(ry,r+3);
        r = rand() % (BOARD_COLS-rx-6) +rx +1;
        doors[20] = No_Door(ry,r);
        doors[21] = No_Door(ry,r+1);
        doors[22] = No_Door(ry,r+2);
        doors[23] = No_Door(ry,r+3);      
        r = (rand() % (BOARD_ROWS-ry-3)) +f;
        doors[24] = No_Door(r,rx);
        doors[25] = No_Door(r+1,rx);
      
        drawDoors();

        int chosen_enemies[enemies_num];
        int x_chosen[enemies_num];
        int y_chosen[enemies_num];
        for(int i=0;i<enemies_num;i++){
            chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
        }
        for(int i=0;i<this->enemies_num;i++){   
            createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//stalker boss, (4 deboli + il boss)
class Template_37 : public General_template {
public:
    Template_37(int n,Board &game_board) : General_template(0,16,5,1)
    {
        int i = 0;   
        //i = drawFilledSquare(HALF_ROWS/2,(HALF_COLS/2)*3-1,2,3,i);

        drawDoors();

        int chosen_enemies[enemies_num] = {3,3,3,3,3};
        int x_chosen[enemies_num] = {HALF_COLS,HALF_COLS/2,HALF_COLS/2,(HALF_COLS/2)*3,(HALF_COLS/2)*3};
        int y_chosen[enemies_num] = {HALF_ROWS,HALF_ROWS/2,(HALF_ROWS/2)*3,HALF_ROWS/2,(HALF_ROWS/2)*3};
        for(int i=0;i<this->enemies_num;i++){   
            createEnemies(false,false,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};

//drunk boss (4 deboli + il boss)
class Template_38 : public General_template {
public:
    Template_38(int n,Board &game_board) : General_template(0,16,5,1)
    {
        int i = 0;   
        //i = drawFilledSquare(HALF_ROWS/2,(HALF_COLS/2)*3-1,2,3,i);

        drawDoors();

        int chosen_enemies[enemies_num] = {0,0,0,0,0};
        int x_chosen[enemies_num] = {HALF_COLS,HALF_COLS-2,HALF_COLS-2,HALF_COLS+2,HALF_COLS+2};
        int y_chosen[enemies_num] = {HALF_ROWS,HALF_ROWS-2,HALF_ROWS+2,HALF_ROWS-2,HALF_ROWS+2};
        for(int i=0;i<this->enemies_num;i++){   
        createEnemies(false,false,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
        }

        artifact[0] = Artifact(6,6);
    }
};
