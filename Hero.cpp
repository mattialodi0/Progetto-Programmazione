#include "Hero.hpp"

Hero::Hero():Character(def, herostarty, herostartx,'P')
{
	
}
Hero::Hero(int y, int x):Character(def, y, x,'P')
{   
}

void Hero::centerHero(Direction dir) {
	switch(dir){
    case(sx):
        this->x=1;
        this->y=BOARD_ROWS/2;
        break;
    case (dx):
        this->x=BOARD_COLS-2;
        this->y=BOARD_ROWS/2;
        break;
    case (up):
        this->x=BOARD_COLS/2;
        this->y=1;
        break;
    case (down):
        this->x=BOARD_COLS/2;
    	this->y=BOARD_ROWS-2;
        break;
    }
}
