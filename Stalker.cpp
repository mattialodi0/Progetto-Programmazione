#include "Stalker.hpp"


Stalker::Stalker():Enemy(def,20,20,'Z',0)
    {
    }
    Stalker::Stalker(int y, int x,int diff):Enemy(def,y,x,'Z',diff)
{
}
    //per creare proiettili
     void Stalker::createProjectile(Board &board_win, Hero &hero, Direction dir)
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
          void Stalker::checkProjectile(Board &board_win, Hero &hero){
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
    void Stalker::chooseDirection(Board &board_win, Hero &hero)
    {
        setDirection(def);
        
    if(getReload()<=0){
         int distancex, distancey;
        distancex = getx() - hero.getx();
        distancey = gety() - hero.gety();
         if(hasLos(board_win, hero) && inSight(distancex,distancey)){
            this->mem=enemy_memory;
            }
            else{
                setIcon('Z');
            }
        if (this->mem>0)
        {
        if(distancey==0){
            if(distancex>0){
              if(abs(distancex)<getRange()){
                    setIcon('Z');
                    createProjectile(board_win,hero,sx);
                    }
                    else{
                        setDirection(sx);
                        setIcon(' ');
                    }
            }
            else{
               if(abs(distancex)<getRange()){
                    setIcon('Z');
                    createProjectile(board_win,hero,dx);
                    }
                    else{
                        setDirection(dx);
                        setIcon(' ');
                    }
            }
        }
        else{
            if(distancex==0){
                if(distancey>0){
                    if(abs(distancey)<getRange()){
                        setIcon('Z');
                    createProjectile(board_win,hero,up);
                    }
                    else{
                        setDirection(up);
                        setIcon(' ');
                    }
                }
                else{
                    if(abs(distancey)<getRange()){
                        setIcon('Z');
                    createProjectile(board_win,hero,down);
                    }
                    else{
                        setDirection(down);
                        setIcon(' ');
                    }
                }
            }
            else{

            if (abs(distancex) < abs(distancey))
            {
                if (distancex < 0)
                {
                    setDirection(dx);
                    setIcon(' ');
                }
                else
                {
                    if(distancex>0){
                    setDirection(sx);
                    setIcon(' ');
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
                        setIcon(' ');
                    }
                    else
                    {
                        if(distancey>0){
                        setDirection(up);
                        setIcon(' ');
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
            setIcon('Z');
            setDirection(def);
            }

         this->mem--;
         
         
    }
