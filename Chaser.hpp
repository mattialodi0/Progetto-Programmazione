// nemico che ti segue
#pragma once

#include "Enemy.hpp"


class Chaser : public Enemy
{
public:
    Chaser(int y, int x);
    //sprite diverso ma uguale
        void createProjectile(Direction dir)override {
           if(this->reload<=0){
            this->reload=enemy_reload;
        Projectile *new_proj = new Projectile(dir,this->getx(),this->gety(), 'O');
        projectile.push_back(new_proj); 
    }
    else{
        this->reload--;
    }
        }
        //uguale a shooter ma meno range
     void checkProjectile(Board board_win, Characters hero);
    //ti viene vicino e spara un piccolo proiettile e viene stunnato
    void ChooseDirection(Board board_win, Characters &hero) override
    {
        if(this->reload<=0){
        int distancex, distancey;
        distancex = this->x - hero.getx();
        distancey = this->y - hero.gety();
        //se sei vicino
         if(hasLos(board_win, hero, this->y, this->x) && abs(distancex) < sight_range && abs(distancey) < sight_range){
            this->mem=enemy_memory;
            }
        if (this->mem>0)
        {
            if(abs(distancex) < melee_range && abs(distancey) < melee_range){
                 if(distancey==0){
            if(distancex>0){
                createProjectile(sx);
            }
            else{
                createProjectile(dx);
            }
            this->reload=melee_enemy_reload;
        }
        else{
            if(distancex==0){
                if(distancey>0){
                    createProjectile(up);
                }
                else{
                    createProjectile(down);
                }
                this->reload=melee_enemy_reload;
            }
            }
            }
            if (abs(distancex) > abs(distancey))
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
                if (abs(distancex) <= abs(distancey))
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
        this->mem--;
        this->reload--;   
    }
};