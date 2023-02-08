#include "Shooter.hpp"


Shooter::Shooter():Enemy(def,18,18,'S',0)
    {
    }
    Shooter::Shooter(int y, int x,int diff):Enemy(def,y,x,'S',diff)
{
}
    //per creare proiettili
     void Shooter::createProjectile(Board &board_win, Hero &hero, Direction dir)
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
    }
     }
     //per movimento proiettili e check di colpito o out of range
     void Shooter::checkProjectile(Board &board_win, Hero &hero){
        for (int i = 0; i < projectile.size(); i++)
		{
			if (projectile[i] != NULL){
                projectile[i]->setUptime(projectile[i]->getUptime()+1);
        if(!projectile[i]->checkCollision(board_win)||projectile[i]->getUptime()>getRange()){
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
     
     //va a una tua stessa linea o colonna per spararti e spara
    void Shooter::chooseDirection(Board &board_win, Hero &hero)
    {
        setDirection(def);
        
    if(getReload()<=0){
         int distancex, distancey;
        distancex = getx() - hero.getx();
        distancey = gety() - hero.gety();
         if(hasLos(board_win, hero) && inSight(distancex,distancey)){
            this->mem=enemy_memory;
            }
        if (this->mem>0)
        {
        if(distancey==0){
            if(distancex>0){
              if(abs(distancex)<getRange()){
                    setDirection(def);
                    createProjectile(board_win,hero,sx);
                    }
                    else{
                        setDirection(sx);
                    }
            }
            else{
               if(abs(distancex)<getRange()){
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
                    if(abs(distancey)<getRange()){
                        setDirection(def);
                    createProjectile(board_win,hero,up);
                    }
                    else{
                        setDirection(up);
                    }
                }
                else{
                    if(abs(distancey)<getRange()){
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
            dimReload();
            setDirection(def);
            }

         this->mem--;
         
         
    }
