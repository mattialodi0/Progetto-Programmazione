#include "Drawable.hpp"


class general_template {
public:
    Drawable* walls = new Drawable[1];
    Drawable* doors = new Drawable[1];
    int walls_num; int doors_num;
};

class template_0 : public general_template {
public:
    int wall_num = 1;
    template_0() 
    {
        Drawable w0 = Drawable(6,6,'X');
        Drawable w0 = Drawable(6,6,'X');
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
    int walls_num = 1;
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