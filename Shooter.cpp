#include "Shooter.hpp"


Shooter::Shooter():Enemy(def,18,18,'S',0)
    {
    }
    Shooter::Shooter(int y, int x,int diff):Enemy(def,y,x,'S',diff)
{
}
    //per creare proiettili
     void Shooter::createProjectile(Board &board_win, Character &hero, Direction dir)
     {
        if(this->reload<=0){
    this->reload=enemy_reload;
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
     void Shooter::checkProjectile(Board &board_win, Character &hero){
        for (int i = 0; i < projectile.size(); i++)
		{
			if (projectile[i] != NULL){
                projectile[i]->setUptime(projectile[i]->getUptime()+1);
        if(!projectile[i]->checkCollision(board_win)||projectile[i]->getUptime()>enemy_range){
        projectile[i]->moveCharacter(board_win);
        if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
            hero.hp=hero.hp-30;
        } 
        projectile.erase(projectile.begin()+i);
        board_win.setTaken(projectile[i]->getx(),projectile[i]->gety(),false);
        }
        else{
            
                if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
                    hero.hp=hero.hp-30;
                board_win.setTaken(projectile[i]->getx(),projectile[i]->gety(),false);
                projectile.erase(projectile.begin()+i);
                }    
          projectile[i]->moveCharacter(board_win);
          
          }
        }
    }
        }
     
     //va a una tua stessa linea o colonna per spararti e spara
    void Shooter::chooseDirection(Board &board_win, Character &hero)
    {
        setDirection(def);
        
    if(this->reload<=0){
         int distancex, distancey;
        distancex = this->x - hero.getx();
        distancey = this->y - hero.gety();
         if(hasLos(board_win, hero) && inSight(distancex,distancey)){
            this->mem=enemy_memory;
            }
        if (this->mem>0)
        {
        if(distancey==0){
            if(distancex>0){
              if(abs(distancex)<enemy_range){
                    setDirection(def);
                    createProjectile(board_win,hero,sx);
                    }
                    else{
                        setDirection(sx);
                    }
            }
            else{
               if(abs(distancex)<enemy_range){
                setDirection(def);
                    createProjectile(board_win,hero,dx);
                    }
                    else{
                        setDirection(dx);
                    }
            }
        }
        else{
            if(distancex==0){
                if(distancey>0){
                    if(abs(distancey)<enemy_range){
                        setDirection(def);
                    createProjectile(board_win,hero,up);
                    }
                    else{
                        setDirection(up);
                    }
                }
                else{
                    if(abs(distancey)<enemy_range){
                        setDirection(def);
                    createProjectile(board_win,hero,down);
                    }
                    else{
                        setDirection(down);
                    }
                }
            }
            else{

            if (abs(distancex) < abs(distancey))
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
                if (abs(distancex) >= abs(distancey))
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
