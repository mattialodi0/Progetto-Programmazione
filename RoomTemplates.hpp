#include "Drawable.hpp"
#include "Board.hpp"
#include <iostream>

//#include "Chaser.hpp"
#include "Coward.hpp"
#include "DrunkenEnemy.hpp"
#include "Dumb.hpp"

#define HALF_COLS BOARD_COLS/2
#define HALF_ROWS BOARD_ROWS/2

/* !!!!!!!!!
non si sa per quale assurdo motivo funziona tutto solo 
se non vengono chiamati i delete nei distruttori
ma non può essere una buona soluzione
*/
typedef Characters * pChar;

class general_template {
public:
    Drawable* walls;
    Drawable* doors;
    pChar* enemies;
    int walls_num; 
    int doors_num;
    int enemies_num;
    general_template() {}
    general_template(int w, int d, int e)
    {
        this->walls_num = w; 
        this->doors_num = d;
        this->enemies_num = e;
        walls = new Drawable[walls_num];
        doors = new Drawable[doors_num];
        enemies = new pChar[enemies_num];
    }
    /*~general_template() {
        delete [] walls;
        delete [] doors;
        delete [] enemies;
    }*/
    void Destructor() {
        delete [] walls;
        delete [] doors;
        delete [] enemies;
        std::cout << "D\n";
    }
};

class template_0 : public general_template {
public:
    template_0() : general_template(5,16,0)
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


class template_1 : public general_template {
public:
    template_1() : general_template(1,16,1)
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


class template_2 : public general_template {
public:
    template_2() : general_template(8,16,1)
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

        enemies[0] = new Coward();
        enemies[0]->setDirection(def);
    }
};