#include "Drawable.hpp"


class general_template {
public:
    Drawable* walls = new Drawable[1];
    Drawable* doors = new Drawable[1];
};

class template_0 : public general_template {
public:
    template_0() 
    {
        Drawable w0 = Drawable(3,3,'X');
        walls[0] = w0;
    }
    ~template_0() 
    {
        delete [] walls;
    }
};


class template_1 : public general_template {
public:
    Drawable* walls = new Drawable[1];
    int walls_num = 4;
    //Drawable* doors = new Drawable[1];
    //int doors_num = 4*DOORS_LENGTH;
    template_1() 
    {
        Drawable w0 = Drawable(7,10,'X');
        walls[0] = w0;
    }
    ~template_1() 
    {
        delete [] walls;
    }
};
