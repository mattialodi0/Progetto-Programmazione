#include "Stalker.hpp"


Stalker::Stalker():Enemy(def,20,20,'Z',0)
    {
    }
    Stalker::Stalker(int y, int x,int diff):Enemy(def,y,x,'Z',diff)
{
}
    //per creare proiettili
     void Stalker::createProjectile(Board &board_win, Character &hero, Direction dir)
     {
                 if(this->reload<=0){
    this->reload=enemy_reload;
    Projectile *new_proj = new Projectile(dir,this->getx(),this->gety(), 'o');
    projectile.push_back(new_proj);
    switch(dir){
    case up:
    new_proj->sety(new_proj->gety()-1);
    new_proj->setIcon('|');
    break;
    case down:
    new_proj->sety(new_proj->gety()+1);
    new_proj->setIcon('|');
    break;
    case dx:
     new_proj->setx(new_proj->getx()+1);
    new_proj->setIcon('-');
    break;
    case sx:
     new_proj->setx(new_proj->getx()-1);
    new_proj->setIcon('-');
    break;
    }
    }
    else{
        this->reload--;
    }
     }
     //per movimento proiettili e check di colpito o out of range
     void Stalker::checkProjectile(Board &board_win, Character &hero){
        for (int i = 0; i < projectile.size(); i++)
		{
			if (projectile[i] != NULL){
                projectile[i]->setUptime(projectile[i]->getUptime()+1);
        if(!projectile[i]->checkCollision(board_win)||projectile[i]->getUptime()>enemy_range){
        projectile[i]->moveCharacter(board_win);
        if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
            //diminuisci vita player
        } 
        projectile.erase(projectile.begin()+i);
        board_win.setTaken(projectile[i]->getx(),projectile[i]->gety(),false);
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
        }
     
     //va a una tua stessa linea o colonna per spararti e spara
    void Stalker::chooseDirection(Board &board_win, Character &hero)
    {
        setDirection(def);
        
    if(this->reload<=0){
         int distancex, distancey;
        distancex = this->x - hero.getx();
        distancey = this->y - hero.gety();
         if(hasLos(board_win, hero) && inSight(distancex,distancey)){
            this->mem=enemy_memory;
            }
            else{
                this->setIcon('Z');
            }
        if (this->mem>0)
        {
        if(distancey==0){
            if(distancex>0){
              if(abs(distancex)<enemy_range){
                    this->setIcon('Z');
                    createProjectile(board_win,hero,sx);
                    }
                    else{
                        setDirection(sx);
                        this->setIcon(' ');
                    }
            }
            else{
               if(abs(distancex)<enemy_range){
                    this->setIcon('Z');
                    createProjectile(board_win,hero,dx);
                    }
                    else{
                        setDirection(dx);
                        this->setIcon(' ');
                    }
            }
        }
        else{
            if(distancex==0){
                if(distancey>0){
                    if(abs(distancey)<enemy_range){
                        this->setIcon('Z');
                    createProjectile(board_win,hero,up);
                    }
                    else{
                        setDirection(up);
                        this->setIcon(' ');
                    }
                }
                else{
                    if(abs(distancey)<enemy_range){
                        this->setIcon('Z');
                    createProjectile(board_win,hero,down);
                    }
                    else{
                        setDirection(down);
                        this->setIcon(' ');
                    }
                }
            }
            else{

            if (abs(distancex) < abs(distancey))
            {
                if (distancex < 0)
                {
                    setDirection(dx);
                    this->setIcon(' ');
                }
                else
                {
                    if(distancex>0){
                    setDirection(sx);
                    this->setIcon(' ');
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
                        this->setIcon(' ');
                    }
                    else
                    {
                        if(distancey>0){
                        setDirection(up);
                        this->setIcon(' ');
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
            this->setIcon('Z');
            setDirection(def);
            }

         this->mem--;
         
         
    }
