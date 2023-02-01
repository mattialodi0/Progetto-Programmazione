#include "Flyer.hpp"

Flyer::Flyer():Enemy(def,10,10,'F',0)
{
    setisFlyer(true);
}

Flyer::Flyer(int y, int x,int diff):Enemy(def,y,x,'F',diff)
{
    setisFlyer(true);
}

void Flyer::createProjectile(Board &board_win, Hero &hero, Direction dir) 
{
    if(this->reload<=0){
    this->reload=enemy_reload;
    Projectile *new_proj = new Projectile(dir,this->getx(),this->gety(), 'o');
    projectile.push_back(new_proj); 
   
    }
    else{
        this->reload--;
    }
}

void Flyer::checkProjectile(Board &board_win, Hero &hero)
{
    for (int i = 0; i < projectile.size(); i++)
	{
		if (projectile[i] != NULL){
            projectile[i]->setUptime((projectile[i]->getUptime())+1);
            
            if(!projectile[i]->checkFlyerCollision(board_win)|| projectile[i]->getUptime()>melee_range){
                projectile[i]->moveCharacter(board_win);
                if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
                    hero.reduceHealth();
                }    
                projectile.erase(projectile.begin()+i);
                board_win.addAt(this->y,this->x,' ');
                board_win.setTaken(projectile[i]->getx(),projectile[i]->gety(),false);
            }
            else{
                if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
                    hero.reduceHealth();
                board_win.setTaken(projectile[i]->getx(),projectile[i]->gety(),false);
                board_win.addAt(this->y,this->x,' ');
                projectile.erase(projectile.begin()+i);
                }    
                else{
                projectile[i]->moveCharacter(board_win);
                }
            }
    
        }
    }
}

void Flyer::chooseDirection(Board &board_win, Hero &hero)
{
    
    if(this->reload<=0){
        int distancex, distancey;
        distancex = this->x - hero.getx();
        distancey = this->y - hero.gety();
        //se sei vicino
        if(flyerHasLos(board_win, hero) && inSight(distancex,distancey))
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
                }
            }
            if(abs(distancex) <= melee_range && abs(distancey) <= melee_range){
                if(distancey==0){
                    if(distancex>0){
                        createProjectile(board_win,hero,sx);
                        setDirection(def);
                    }
                    else{
                    createProjectile(board_win,hero,dx);
                    setDirection(def);
                    }
                    this->reload=melee_enemy_reload;
                }
                else{
                    if(distancex==0){
                        if(distancey>0){
                            createProjectile(board_win,hero,up);
                            setDirection(def);
                        }
                        else{
                            createProjectile(board_win,hero,down);
                            setDirection(def);
                        }
                        this->reload=melee_enemy_reload;
                    }
                }
            }
        }
    }
     else{
            this->reload--;
            setDirection(def);
            }
    this->mem--; 
}
