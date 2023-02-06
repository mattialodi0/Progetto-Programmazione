#include "Hero.hpp"

const int enemiesdamage = 10;
const int artifacthp = 5;
const int artifactdmg = 1;
const int artifactrange = 2;

Hero::Hero() : Character(def, herostarty, herostartx,'P')
{	
    artifact = Artifact (y, x,'H');
    this->key = 1;
    this->maxHp=30;
    this->hp = this->maxHp;
    this->hero_reload_time = 8;
    this->range = 15;
    this->speed = 1;
    this->dmg = 15;
    this->reload = 0;
}

Hero::Hero(int y=0, int x=0) : Character(def, y, x,'P')
{   
    artifact = Artifact (y, x,'H');
    this->key = 1;
    this->maxHp=30;
    this->hp = this->maxHp;
    this->hero_reload_time = 8;
    this->range = 15;
    this->speed = 1;
    this->dmg = 15;
    this->reload = 0;
}

/*
Hero::Hero(const Hero& h) 
{
    y=1;x=1;icon='P';cur_direction=def;
}*/

//per l'inizializzazione della classe
void Hero::tankClass() 
{
    this->maxHp=40;
    this->hp = this->maxHp;
    this->ac = 3;
    this->dmg = 2;
    this->speed = 1;
    this->reload_time=3;
    this->range = 2;
}

void Hero::rogueClass() 
{
    this->maxHp=20;
    this->hp = this->maxHp;
    this->ac = 2;
    this->dmg = 3;
    this->speed = 4;
    this->reload_time=2;
    this->range = 2;
}

void Hero::rangerClass() 
{
    this->maxHp=16;
    this->hp = this->maxHp;
    this->ac = 1;
    this->dmg = 1;
    this->speed = 3;
    this->reload_time=1;
    this->range = 10;
}

void Hero::mageClass() 
{
    this->maxHp=16;
    this->hp = this->maxHp;
    this->ac = 1;
    this->dmg = 3;
    this->speed = 2;
    this->reload_time=4;
    this->range = 8;
}

void Hero::useAbility() 
{
}

void Hero::attack(Board &board_win, Direction dir) 
{
    if(this->reload<=0){
        this->reload=hero_reload_time;
        Projectile *new_proj = new Projectile(dir,this->getx(),this->gety(), 'o');
        projectile.push_back(new_proj); 
        switch(dir){
            case up:
                new_proj->setIcon('|');
                break;
            case down:
                new_proj->setIcon('|');
                break;
            case dx:
                new_proj->setIcon('-');
                break;
            case sx:
                new_proj->setIcon('-');
                break;
        }
    }
}

int Hero::getReload(){
    return this->reload;
}
void Hero::minusReload(){
    this->reload--;

}
//per movimento proiettili e check di colpito o out of range


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

void Hero::addKey(){
    this->key++;
}

int Hero::getRange()
{
    return this->range;
}

int Hero::getDmg()
{
    return this->dmg;
}

void Hero::heal(int artifactHp){
    if(this->hp+artifactHp<=this->maxHp){
    this->hp=this->hp+artifactHp;
    }
    else{
        this->hp=this->maxHp;
        }
}

void Hero::increaseHealth(int artifactHp)
{
    this->maxHp = this->maxHp + artifactHp;
}

void Hero::increaseDamage(int artifactDmg)
{
    this->dmg = this->dmg + artifactDmg;
}

void Hero::increaseRange(int artifactRange)
{
    this->range = this->range + artifactRange;
}

void Hero::reduceHealthHero(int enemiesDamage)
{
    this->hp = this->hp -enemiesDamage;
}

bool Hero::death()
{
    if(this->hp <= 0){
        return true;
    }
    return false;
}
