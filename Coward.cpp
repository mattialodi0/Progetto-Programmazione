#include "Coward.hpp"

Coward::Coward():Enemy(def,11,11,'K',0)
{
}
Coward::Coward(int y, int x,int diff):Enemy(def,y,x,'K',diff)
{
}


void Coward::createProjectile(Board &board_win, Hero &hero, Direction dir) 
{
    if(dir!=def){
    Projectile *new_proj = new Projectile(dir,this->getx(),this->gety(), 'o');
    projectile.push_back(new_proj);
    switch(dir){
    case down:
    new_proj->sety(new_proj->gety()-1);
    break;
    case up:
    new_proj->sety(new_proj->gety()+1);
    break;
    case sx:
    new_proj->setx(new_proj->getx()+1); 
    break;
    case dx:
     new_proj->setx(new_proj->getx()-1);
    break;
    }
    }
    else{
        for(int j=0;j<boom_range;j++){
        for(int i=0;i<boom_range*2.5;i++){
            if(board_win.getCharAt(projectile[0]->gety()+j-(boom_range/2), projectile[0]->getx()+i-((boom_range*2.5/2))+1)==' '|| board_win.getCharAt(projectile[0]->gety()+j-(boom_range/2), projectile[0]->getx()+i-((boom_range*2.5/2))+1)==hero.getIcon()){
               
                Projectile *new_proj = new Projectile(def,projectile[0]->getx()+i-((boom_range*2.5/2))+1,projectile[0]->gety()+j-(boom_range/2), 'o');
                projectile.push_back(new_proj); 
        }
    }
    }
    } 
    
}

void Coward::checkProjectile(Board &board_win, Hero &hero)
{
    for (int i = 0; i < projectile.size(); i++)
	{
		if (projectile[i] != NULL){
            projectile[i]->setUptime((projectile[i]->getUptime())+1);            
            if( projectile[i]->getUptime()>melee_range||(board_win.getCharAt(projectile[i]->gety(),projectile[i]->getx())!=projectile[i]->getIcon()&&board_win.getCharAt(projectile[i]->gety(),projectile[i]->getx())!=' ')){
                
                if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
                    hero.reduceHealthHero();
                }  
                board_win.addAt(projectile[i]->gety(),projectile[i]->getx(),' ');
                if(projectile[i]->getUptime()>melee_range && projectile[i]->getDirection()!=def){
                  createProjectile(board_win,hero,def); 
                }  
                projectile.erase(projectile.begin()+i);
            }
        }
    }
}
void Coward::chooseDirection(Board &board_win, Hero &hero)
{       int i = 0;
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
            if(this->ammo>0&&this->reload<=0){
                this->reload=bomb_reload;
                this->ammo--;
                createProjectile(board_win,hero,this->getDirection());

            }
        }
        this->mem--;
        this->reload--;
}