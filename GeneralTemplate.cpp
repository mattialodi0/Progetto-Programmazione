#include "GeneralTemplate.hpp"

General_template::General_template() {}

General_template::General_template(int w, int d, int e)
{
    this->walls_num = w; 
    this->doors_num = d;
    this->enemies_num = e;
    walls = new Drawable[walls_num];
    doors = new Drawable[doors_num];
    enemies = new pEn[enemies_num];
}

General_template::~General_template() {
    delete [] walls;
    delete [] doors;
    delete [] enemies;
}
