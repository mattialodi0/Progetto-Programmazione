#include "Hero.hpp"


Hero::Hero() : Character(def, herostarty, herostartx,'P')
{	
    
}

Hero::Hero(int y=0, int x=0) : Character(def, y, x,'P')
{   
}
/*
Hero::Hero(const Hero& h) 
{
    y=1;x=1;icon='P';cur_direction=def;
}*/

void Hero::centerHero(Direction dir) {
	switch(dir){
    case(sx):
        this->x=BOARD_COLS-2;
        this->y=BOARD_ROWS/2;
        break;
    case (dx):
        this->x=1;
        this->y=BOARD_ROWS/2;
        break;
    case (up):
        this->x=herostartx;
        this->y=1;
        break;
    case (down):
        this->x=herostartx;
    	this->y=1;
        break;
    default:
        this->x=herostartx;
    	this->y=herostarty;
        break;
    }
}
