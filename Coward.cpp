#include "Coward.hpp"

Coward::Coward():Enemy(def,11,11,'K',0)
{
}
Coward::Coward(int y, int x,int diff):Enemy(def,y,x,'K',diff)
{
}


void Coward::createProjectile(Board &board_win, Character &hero, Direction dir) 
{
  /*  if(this->reload<=0){
    this->reload=enemy_reload;
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
        this->reload--;
    }
    */
}

void Coward::checkProjectile(Board &board_win, Character &hero)
{
    /*
    for (int i = 0; i < projectile.size(); i++)
	{
		if (projectile[i] != NULL){
            projectile[i]->setUptime((projectile[i]->getUptime())+1);
            
            if(!projectile[i]->checkCollision(board_win)|| projectile[i]->getUptime()>melee_range){
                projectile[i]->moveCharacter(board_win);
                if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
                    hero.reduceHealth();
                }    
                board_win.setTaken(projectile[i]->getx(),projectile[i]->gety(),false);
                projectile.erase(projectile.begin()+i);
            }
            else{
                if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
                //diminuisci vita player
                board_win.setTaken(projectile[i]->getx(),projectile[i]->gety(),false);
                projectile.erase(projectile.begin()+i);
                }    
                projectile[i]->moveCharacter(board_win);
               
            }
    
        }
    }
    */
}

void Coward::chooseDirection(Board &board_win, Character &hero)
{int i = 0;
        int distancex, distancey;
        distancex = this->x - hero.getx();
        distancey = this->y - hero.gety();
            if(hasLos(board_win, hero) && inSight(distancex,distancey)){
            this->mem=enemy_memory;
            }
        if (this->mem>0){
            Direction horz = (distancex < 0) ? sx : dx;
            Direction ver = (distancey < 0) ? up : down;
            bool pref = abs(distancex) < abs(distancey);
            setDirection((pref) ? horz : ver);
            if (!checkCollision(board_win))
            {
                setDirection((pref) ? ver : horz);
                if (!checkCollision(board_win))
                {
                    if (distancex == 0)
                    {
                        setDirection(sx);
                    }
                    if (distancey == 0)
                    {
                        setDirection(up);
                    }
                }
            }
        }
        this->mem--;
}