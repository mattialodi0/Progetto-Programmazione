#include "Drawable.hpp"
#include "Board.hpp"

/* !!!!!!!!!
non si sa per quale assurdo motivo funziona tutto solo 
se non vengono chiamati i delete nei distruttori
ma non può essere una buona soluzione
*/

class general_template {
public:
    Drawable* walls = new Drawable[1];
    Drawable* doors = new Drawable[1];
    Drawable* enemies = new Drawable[1];
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
        enemies = new Drawable[enemies_num];
    }
    ~general_template() {
        delete [] walls;
        delete [] doors;
        delete [] enemies;
    }
};

class template_0 : public general_template {
public:
    template_0() : general_template(5,14,0)
    {
        walls[0] = Wall(6,6);
        walls[1] = Wall(10,19); 
        walls[2] = Wall(10,11); 
        walls[3] = Wall(3,25); 
        walls[4] = Wall(8,30); 

        doors[0] = Door(0,19);   //north doors
        doors[1] = Door(0,20);
        doors[2] = Door(0,21);
        doors[3] = Door(0,22);
        doors[4] = Door(BOARD_ROWS-1,19);   //south doors
        doors[5] = Door(BOARD_ROWS-1,20);
        doors[6] = Door(BOARD_ROWS-1,21);
        doors[7] = Door(BOARD_ROWS-1,22);
        doors[8] = Door(6,0);   //west doors
        doors[9] = Door(7,0);
        doors[10] = Door(8,0);
        doors[11] = Door(6,BOARD_COLS-1);   //est doors
        doors[12] = Door(7,BOARD_COLS-1);
        doors[13] = Door(8,BOARD_COLS-1);
    }
};


class template_1 : public general_template {
public:
    template_1() : general_template(1,14,0)
    {
        walls[0] = Wall(10,10);
        
        doors[0] = Door(0,19);   //north doors
        doors[1] = Door(0,20);
        doors[2] = Door(0,21);
        doors[3] = Door(0,22);
        doors[4] = Door(BOARD_ROWS-1,19);   //south doors
        doors[5] = Door(BOARD_ROWS-1,20);
        doors[6] = Door(BOARD_ROWS-1,21);
        doors[7] = Door(BOARD_ROWS-1,22);
        doors[8] = Door(6,0);   //west doors
        doors[9] = Door(7,0);
        doors[10] = Door(8,0);
        doors[11] = Door(6,BOARD_COLS-1);   //est doors
        doors[12] = Door(7,BOARD_COLS-1);
        doors[13] = Door(8,BOARD_COLS-1);
    }
};


class template_2 : public general_template {
public:
    template_2() : general_template(1,14,0)
    {
        walls[0] = Wall(10,10);

        doors[0] = Door(0,19);   //north doors
        doors[1] = Door(0,20);
        doors[2] = Door(0,21);
        doors[3] = Door(0,22);
        doors[4] = Door(BOARD_ROWS-1,19);   //south doors
        doors[5] = Door(BOARD_ROWS-1,20);
        doors[6] = Door(BOARD_ROWS-1,21);
        doors[7] = Door(BOARD_ROWS-1,22);
        doors[8] = Door(6,0);   //west doors
        doors[9] = Door(7,0);
        doors[10] = Door(8,0);
        doors[11] = Door(6,BOARD_COLS-1);   //est doors
        doors[12] = Door(7,BOARD_COLS-1);
        doors[13] = Door(8,BOARD_COLS-1);
    }
};