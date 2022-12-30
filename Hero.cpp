#include "Hero.hpp"


Hero::Hero() : Character(def, herostarty, herostartx,'P')
{	
    key = 1;
}

Hero::Hero(int y=0, int x=0) : Character(def, y, x,'P')
{   
    key = 1;
}

/*
Hero::Hero(const Hero& h) 
{
    y=1;x=1;icon='P';cur_direction=def;
}*/

//per l'inizializzazione della classe
void Hero::tankClass() 
{
    this->hp = 30;
    this->ac = 3;
    this->dmg = 2;
    this->speed = 1;
    this->reload_time=3;
    this->range = 2;
}

void Hero::rogueClass() 
{
    this->hp = 20;
    this->ac = 2;
    this->dmg = 3;
    this->speed = 4;
    this->reload_time=2;
    this->range = 2;
}

void Hero::rangerClass() 
{
    this->hp = 16;
    this->ac = 1;
    this->dmg = 1;
    this->speed = 3;
    this->reload_time=1;
    this->range = 10;
}

void Hero::mageClass() 
{
    this->hp = 16;
    this->ac = 1;
    this->dmg = 3;
    this->speed = 2;
    this->reload_time=4;
    this->range = 8;
}

void Hero::useAbility() 
{
}

void Hero::attack(Direction dir) 
{
    
}

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
        this->y=BOARD_ROWS-2;
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

bool Hero::useKey()
{
    if(this->key >= 1)
    {
        this->key--;
        return true;
    }
    else return false;
}