#include "Hero.hpp"

const int enemiesdamage = 10;
const int artifacthp = 5;
const int artifactdmg = 2;
const int artifactrange = 2;

Hero::Hero() : Character(def, herostarty, herostartx,'P')
{	
    this->key = 1;
    this->maxHp=30;
    this->hp = this->maxHp;
    this->maxReload = 8;
    this->standardRange = 8;
    this->range = standardRange;
    this->standardDmg = 8;
    this->dmg = standardDmg;
    this->reload = 0;
    this->ability = 3;
}

Hero::Hero(int c, int y=0, int x=0) : Character(def, y, x,'P')
{   
    this->key = 1;
    this->maxHp=30;
    this->hp = this->maxHp;
    this->maxReload=8;
    this->reload=maxReload;
    this->standardRange = 8;
    this->range = standardRange;
    this->standardDmg = 8;
    this->dmg = standardDmg;
    this->reload = 0;
    this->ability = 3;
    initclass(c);
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
    this->standardDmg = 5;
    this->dmg = standardDmg;
    this->maxReload=3;
    this->reload=maxReload;
    this->standardRange = 4;
    this->range = standardRange;
    this->ability = 1;
}

void Hero::rogueClass() 
{
    this->maxHp=20;
    this->hp = this->maxHp;
    this->ac = 2;
    this->standardDmg = 7;
    this->dmg = standardDmg;
    this->maxReload=2;
    this->reload=maxReload;
    this->standardRange = 5;
    this->range = standardRange;
    this->ability = 2;
}

void Hero::rangerClass() 
{
    this->maxHp=16;
    this->hp = this->maxHp;
    this->ac = 1;
    this->standardDmg = 3;
    this->dmg = standardDmg;
    this->maxReload=2;
    this->reload=maxReload;
    this->standardRange = 14;
    this->range = standardRange;
    this->ability = 3;
}

void Hero::mageClass() 
{
    this->maxHp=16;
    this->hp = this->maxHp;
    this->ac = 1;
    this->standardDmg = 6;
    this->dmg = standardDmg;
    this->maxReload=4;
    this->reload=maxReload;
    this->standardRange = 7;
    this->range = standardRange;
    this->ability = 4;
}

void Hero::useAbility() 
{
    if(this->ability == 1){         //tank
        this->hp = this->maxHp;
        this->ability = 0;
    }
    else if(this->ability == 2){    //rougue
        this->dmg = 16;
        this->ability = 0;
    }
    else if(this->ability == 3){    //ranger
        this->range = 16;
        this->ability = 0;
    }
    else if(this->ability == 4){    //mage
        this->range = 16;
        this->ability = 0;
    }
}

void Hero::attack(Board &board_win, Direction dir) 
{
    if(getReload()<=0){
        setReload(getMaxReload());
        Projectile *new_proj = new Projectile(dir,getx(),gety(), 'o');
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
        if(this->range == 16){
            if(shot>=5){
                this->range = this->standardRange;
                shot=0;
            }
            shot++;
        }
        if(this->dmg == 16){
            if(shot>=5){
                this->dmg = this->standardDmg;
                shot=0;
            }
            shot++;
        }
    }
}

//per movimento proiettili e check di colpito o out of range


void Hero::centerHero(Direction dir) {
	switch(dir){
    case(sx):
        setx(BOARD_COLS-2);
        sety(BOARD_ROWS/2);
        break;
    case (dx):
        setx(1);
        sety(BOARD_ROWS/2);
        break;
    case (up):
        setx(herostartx);
        sety(BOARD_ROWS-2);
        break;
    case (down):
        setx(herostartx);
    	sety(1);
        break;
    default:
        setx(herostartx);
    	sety(herostarty);
        break;
    }
}

bool Hero::useKey()
{
    if(getKey() >= 1)
    {
        addKey(-1);
        return true;
    }
    else return false;
}

void Hero::setKey(int key){
    this->key=key;
}

int Hero::getKey(){
    return this->key;
}

void Hero::addKey(int key){
    setKey(getKey()+key);
}


void Hero::heal(int artifactHp){
    if(getHp()+artifactHp<=getMaxHp()){
    setHp(getHp()+artifactHp);
    }
    else{
        setHp(getMaxHp());
        }
}

void Hero::increaseHealth(int artifactHp)
{
    setMaxHp(getMaxHp()+artifactHp);
}

void Hero::increaseDamage(int artifactDmg)
{
    setDmg(getDmg()+artifactDmg);
}

void Hero::increaseRange(int artifactRange)
{
    setRange(getRange()+artifactRange);
}

void Hero::reduceHealthHero(int enemiesDamage)
{
    setHp(getHp()-enemiesDamage);
}

bool Hero::death()
{
    if(getHp() <= 0){
        return true;
    }
    return false;
}

void Hero::initclass(int c){
    if (c==1){
        tankClass();
        class_type = 1;
    }else if (c==2){
        rogueClass();
        class_type = 2;
    }else if (c==3){
        rangerClass();
        class_type = 3;
    }else if (c==4){
        mageClass();
        class_type = 4;
    }
    
}

int Hero::getClass() {
    return class_type;
}