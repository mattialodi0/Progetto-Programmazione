#include "Chaser.hpp"

Chaser::Chaser():Enemy(def,10,10,'C',0)
{

}

Chaser::Chaser(int y, int x,int diff):Enemy(def,y,x,'C',diff)
{
}

void Chaser::createProjectile(Board &board_win, Character &hero, Direction dir) 
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

void Chaser::checkProjectile(Board &board_win, Character &hero)
{
    for (int i = 0; i < projectile.size(); i++)
	{
		if (projectile[i] != NULL){
            projectile[i]->setUptime((projectile[i]->getUptime())+1);
            
            if(!projectile[i]->checkCollision(board_win)|| projectile[i]->getUptime()>melee_range){
                projectile[i]->moveCharacter(board_win);
                if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
                    hero.hp=hero.hp-30;
                }    
                board_win.setTaken(projectile[i]->getx(),projectile[i]->gety(),false);
                board_win.remove(*projectile[i]);
                projectile.erase(projectile.begin()+i);
            }
            else{
                if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
                    hero.hp=hero.hp-30;
                board_win.setTaken(projectile[i]->getx(),projectile[i]->gety(),false);
                board_win.remove(*projectile[i]);
                projectile.erase(projectile.begin()+i);
                
                
                }    
                projectile[i]->moveCharacter(board_win);
               
            }
        }
    }
}

void Chaser::chooseDirection(Board &board_win, Character &hero)
{
    if(this->reload<=0){
        int distancex, distancey;
        distancex = this->x - hero.getx();
        distancey = this->y - hero.gety();
        //se sei vicino
        if(hasLos(board_win, hero) && inSight(distancex,distancey))
        {
            this->mem=enemy_memory;
        }
        if (this->mem>0)
        {
            if(abs(distancex) <= melee_range && abs(distancey) <= melee_range){
                if(distancey==0){
                    if(distancex>0){
                        setDirection(def);
                        createProjectile(board_win,hero,sx);
                    }
                    else{
                        setDirection(def);
                    createProjectile(board_win,hero,dx);
                    }
                    this->reload=melee_enemy_reload;
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
                        this->reload=melee_enemy_reload;
                    }
                }
            }
            else{
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

            }
        }
    }
     else{
            this->reload--;
            setDirection(def);
            }
    this->mem--; 
}