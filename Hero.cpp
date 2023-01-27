#include "Hero.hpp"

const int enemiesdamage = 15;
const int artifacthp = 5;
const int artifactdmg = 1;
const int artifactrange = 2;

Hero::Hero() : Character(def, herostarty, herostartx,'P')
{	
    artifact = Artifact (y, x);
    this->key = 1;
    this->hp = 30;
}

Hero::Hero(int y=0, int x=0) : Character(def, y, x,'P')
{   
    artifact = Artifact (y, x);
    this->key = 1;
    this->hp = 30;
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
    
    if(this->reload_time<=0){
    this->reload_time=reload_time;
    Projectile *new_proj = new Projectile(dir,this->getx(),this->gety(), 'o');
    projectile.push_back(new_proj); 
    switch(dir){
    case up:
    new_proj->sety(new_proj->gety()-1);
    break;
    case down:
    new_proj->sety(new_proj->gety()+1);
    break;
    case dx:
    new_proj->setx(new_proj->getx()+1); 
    break;
    case sx:
     new_proj->setx(new_proj->getx()-1);
    break;
    }
    }
    else{
        this->reload_time--;
    }
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

/*void Hero::reduceHealth()
{
	this->hp=this->hp-30;
}
*/
void Hero::increaseHealth()
{
    this->hp = this->hp + artifacthp;
}

void Hero::increaseDamage()
{
    this->dmg = this->dmg + artifactdmg;
}

void Hero::increaseRange()
{
    this->range = this->range + artifactrange;
}

void Hero::takenArtifact()
{
    artifact.setIcon(' ');
}