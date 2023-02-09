#include "Chaser.hpp"

Chaser::Chaser():Enemy(def,10,10,'C',0)
{
    setRange(3);
}

Chaser::Chaser(int y, int x,int diff):Enemy(def,y,x,'C',diff)
{
    setRange(3);
}

void Chaser::createProjectile(Board &board_win, Hero &hero, Direction dir) 
{
    Projectile *new_proj = new Projectile(dir,getx(),gety(), 'o');
    projectile.push_back(new_proj); 
   
}

void Chaser::checkProjectile(Board &board_win, Hero &hero)
{
    for (int i = 0; i < projectile.size(); i++)
	{
		if (projectile[i] != NULL){
            projectile[i]->setUptime((projectile[i]->getUptime())+1);
            
            if(!projectile[i]->checkProjectileCollision(board_win)|| projectile[i]->getUptime()>getRange()){
                projectile[i]->moveCharacter(board_win);
                if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
                    hero.reduceHealthHero(getDmg());
                projectile.erase(projectile.begin()+i);
                }    
                else{
                board_win.addAt(projectile[i]->gety(),projectile[i]->getx(),' ');
                projectile.erase(projectile.begin()+i);
                }
            }
            else{
                if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
                    hero.reduceHealthHero(getDmg());
                board_win.addAt(projectile[i]->gety(),projectile[i]->getx(),' ');
                projectile.erase(projectile.begin()+i);
                }  
                else{  
                projectile[i]->moveCharacter(board_win);
                }
            }
        }
    }
}

void Chaser::chooseDirection(Board &board_win, Hero &hero)
{
    if(getReload()<=0){
        int distancex, distancey;
        distancex = getx() - hero.getx();
        distancey = gety() - hero.gety();
        //se sei vicino
        if(hasLos(board_win, hero) && inSight(distancex,distancey))
        {
            this->mem=enemy_memory;
        }
        if (this->mem>0)
        {
            if (abs(distancex) > abs(distancey))
            {
                if (distancex < 0)
                {
                    setDirection(dx);
                }
                else
                {
                    if(distancex>0){
                    setDirection(sx);
                    }
                }
            }
            else
            {
                if (abs(distancex) <= abs(distancey))
                {
                    if (distancey < 0)
                    {
                        setDirection(down);
                    }
                    else
                    {
                        if(distancey>0){
                        setDirection(up);
                        }
                    }
                }}

             if(abs(distancex) <= getRange() && abs(distancey) <= getRange()){
                if(distancey==0){
                    if(distancex>0){
                        setDirection(def);
                        createProjectile(board_win,hero,sx);
                    }
                    else{
                        setDirection(def);
                    createProjectile(board_win,hero,dx);
                    }
                    setReload(getMaxReload());
                }
                else{
                    if(distancex==0){
                        if(distancey>0){
                            setDirection(def);
                            createProjectile(board_win,hero,up);
                        }
                        else{
                            setDirection(def);
                            createProjectile(board_win,hero,down);
                        }
                        setReload(getMaxReload());
                    }
                }
            }
        }
        else{ 
            int i=0;
            do{  
	Direction dir= getRandomDirection();
    setDirection(dir);
    if(i>10){
        setDirection(def);
    } 
    i++;
	} 
    while (!checkCollision(board_win)&&i<12);
        }
    }
     else{
            dimReload();
            setDirection(def);
            }
    this->mem--; 
}