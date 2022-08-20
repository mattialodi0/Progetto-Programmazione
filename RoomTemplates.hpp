#include "Drawable.hpp"

/* !!!!!!!!!
non si sa per quale assurdo motivo funziona tutto solo 
se non vengono chiamati i delete nei distruttori
ma non può essere una buona soluzione
*/

class general_template {
public:
    Drawable* walls = new Drawable[1];
    Drawable* doors = new Drawable[1];
    int walls_num; 
    int doors_num;
    general_template(){}
    general_template(int w, int d)
    {
        walls_num = w; 
        doors_num = d;
    }
};

class template_0 : public general_template {
public:
    template_0() : general_template(2,1)
    {
        Drawable w0 = Drawable(6,6,'X');
        Drawable w1 = Drawable(10,19,'X');
        walls[0] = w0;
        walls[1] = w1;
        Drawable d0 = Drawable(6,1,'O');
        //Drawable d1 = Drawable(7,1,'O');
        //Drawable d2 = Drawable(8,1,'O');
        doors[0] = d0;
        //doors[1] = d1;
        //doors[2] = d2;
    }
    ~template_0() 
    {
        //delete [] walls;
        //delete [] doors;
    }
};


class template_1 : public general_template {
public:
    template_1() : general_template(1,1)
    {
        Drawable w0 = Drawable(10,10,'X');
        walls[0] = w0;
        Drawable d0 = Drawable(6,1,'O');
        //Drawable d1 = Drawable(7,1,'O');
        //Drawable d2 = Drawable(8,1,'O');
        doors[0] = d0;
        //doors[1] = d1;
        //doors[2] = d2;
    }
    ~template_1() 
    {
        //delete [] walls;
        //delete [] doors;
    }
};

