#pragma once

//nemico che spara

#include "Enemy.hpp"
#include "Projectile.hpp"


class Shooter : public Enemy
{
public:
    Shooter()
    {
        Enemy();
        this->icon = 'S';
        this->x = 10;
        this->y = 10;
    }
    //per creare proiettili
     void createProjectile(Direction dir)override {
                if(this->Reload<=0){
            this->Reload=EnemyReload;
        Projectile *new_proj = new Projectile();
        new_proj->cur_direction=dir;
        if(dir%2==0){
            new_proj->icon='|';
        }
        else{
            new_proj->icon='-';
        }
            new_proj->x=this->x;
            new_proj->y=this->y;
        projectile.push_back(new_proj); 
    }
    else{
        this->Reload--;
    }
     }
     //per movimento proiettili e check di colpito o out of range
     void checkProjectile(Board board_win, Characters hero){
        for (int i = 0; i < projectile.size(); i++)
		{
			if (projectile[i] != NULL){
                projectile[i]->uptime++;
            board_win.remove(*projectile[i]);
        if(!projectile[i]->checkCollision(board_win)||projectile[i]->uptime>Range){
        projectile[i]->moveCharacter();
        if(projectile[i]->x=hero.x && projectile[i]->y==hero.y){
            //diminuisci vita player
        } 
        projectile.erase(projectile.begin()+i);
        }
        else{
          projectile[i]->moveCharacter();
          if(board_win.getCharAt(projectile[i]->y,projectile[i]->x)){
          board_win.add(*projectile[i]);
          }
        }
    }
        }
     }
     //va a una tua stessa linea o colonna per spararti e spara
    void ChooseDirection(Board board_win, Characters &hero) override
    {
         int distancex, distancey;
        distancex = this->x - hero.x;
        distancey = this->y - hero.y;
         if(hasLos(board_win, hero, this->y, this->x) && abs(distancex) < 10 && abs(distancey) < 10){
            this->mem=EnemyMemory;
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
                    setDirection(sx);
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
                        setDirection(up);
                    }
                }
            }
        }
            }
        }
         this->mem--;
    }
    //controlla se ti vede tramite chaser ricorsivo
     bool hasLos(Board board_win, Characters hero, int y, int x) override
    {
            int i=0,k=0;
              int distancex, distancey;
        distancex = x - hero.x;
        distancey = y - hero.y;
            if (abs(distancex) > abs(distancey))
            {
                if (distancex < 0)
                {
                    k++;
                }
                else
                {
                    k--;
                }
            }
            else
            {
                if (abs(distancex) <= abs(distancey))
                {
                    if (distancey < 0)
                    {
                        i++;
                    }
                    else
                    {
                        i--;
                    }
                }
            }
        chtype f =board_win.getCharAt(y+i,x+k);
            if(f==hero.icon){
                return true;
            }
            else{
                if(f!=' '){
                    return false;
                }
                else{
                    return hasLos(board_win, hero, y+i,x+k);
                }
            }
    }
};