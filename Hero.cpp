#include "Hero.hpp"

const int enemiesdamage = 10;
const int artifacthp = 5;
const int artifactdmg = 1;
const int artifactrange = 2;

Hero::Hero() : Character(def, herostarty, herostartx,'P')
{	
    artifact = Artifact (y, x);
    this->key = 1;
    this->hp = 30;
    this->reload_time = 2;
    this->range = 5;
    this->speed = 1;
    this->dmg = 3;
    this->reload = 0;
}

Hero::Hero(int y=0, int x=0) : Character(def, y, x,'P')
{   
    artifact = Artifact (y, x);
    this->key = 1;
    this->hp = 30;
    this->reload_time = 2;
    this->range = 5;
    this->speed = 1;
    this->dmg = 3;
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

void Hero::attack(Board &board_win, Direction dir) 
{
    if(this->reload<=0){
        this->reload=reload_time;
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
    else{
        this->reload--;
    }
}


//per movimento proiettili e check di colpito o out of range
/*
void Hero::checkHeroProjectile(Board &board_win, Room *current_room){
    for (int i = 0; i < projectile.size(); i++)
	{   
		if (projectile[i] != NULL){
            projectile[i]->setUptime(projectile[i]->getUptime()+1);
            if(!projectile[i]->checkCollision(board_win)||projectile[i]->getUptime()>range){
                projectile[i]->moveCharacter(board_win);
                for(int j=0;j < current_room->room_template->enemies_num; j++){
                    if(projectile[i]->getx()==current_room->room_template->enemies[j]->getx() && projectile[i]->gety()==current_room->room_template->enemies[j]->gety()){
                        current_room->room_template->enemies[j]->reduceHealthEnemy(this->dmg);
                        projectile.erase(projectile.begin()+i);
                    }
                    else{
                    board_win.addAt(projectile[i]->gety(),projectile[i]->getx(),' ');
                    projectile.erase(projectile.begin()+i);
                    }
                }
            }
            else{  
                        projectile[i]->moveCharacter(board_win);
                    
                }
            }
        }
    }

*/
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

void Hero::increaseHealth(int artifactHp)
{
    this->hp = this->hp + artifactHp;
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
    hp = hp -enemiesDamage;
}

bool Hero::death()
{
    if(this->hp <= 0){
        return true;
    }
    return false;
}
