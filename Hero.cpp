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


void Hero::Const(int y, int x)
{
    setDirection(def);
    this->y = y;
	this->x = x;
	this->icon = 'P';
}

void Hero::centerHero(Direction dir) {
	switch(dir){
    case(sx):
        this->x=1;
        this->y=herostarty;
        break;
    case (dx):
        this->x=herostartx;
        this->y=herostarty;
        break;
    case (up):
        this->x=herostartx;
        this->y=1;
        break;
    case (down):
        this->x=herostartx;
    	this->y=herostarty;
        break;
    }
}
