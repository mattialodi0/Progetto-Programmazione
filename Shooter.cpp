#include "Shooter.hpp"


Shooter::Shooter():Enemy(def,12,12,'S')
    {
    }
    //per creare proiettili
     void Shooter::createProjectile(Direction dir)
     {
                if(this->reload<=0){
            this->reload=enemy_reload;
        if(dir%2==0){ 
            Projectile *new_proj = new Projectile(dir,this->getx(),this->gety(), '|');
            projectile.push_back(new_proj); 
        }
             
        else{
             Projectile *new_proj = new Projectile(dir,this->getx(),this->gety(), '-');
             projectile.push_back(new_proj); 
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
            board_win.remove(*projectile[i]);
        if(!projectile[i]->checkCollision(board_win)||projectile[i]->getUptime()>range){
        projectile[i]->moveCharacter();
        if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
            //diminuisci vita player
        } 
        projectile.erase(projectile.begin()+i);
        }
        else{
          projectile[i]->moveCharacter();
         
          board_win.add(*projectile[i]);
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
         if(hasLos(board_win, hero) && abs(distancex) <sight_range && abs(distancey) <sight_range){
            this->mem=enemy_memory;
            }
        if (this->mem>0)
        {
        if(distancey==0){
            if(distancex>0){
                createProjectile(sx);
            }
            else{
                createProjectile(dx);
            }
        }
        else{
            if(distancex==0){
                if(distancey>0){
                    createProjectile(up);
                }
                else{
                    createProjectile(down);
                    
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
                if (abs(distancex) > abs(distancey))
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
