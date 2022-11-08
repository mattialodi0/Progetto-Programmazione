// nemico che scappa
// probabilmente da implementare loot come artifatti e chiavi
#pragma once

#include "Enemy.hpp"

class Coward : public Enemy
{
public:
    Coward()
    {
        Enemy();
        this->icon = 'W';
        this->x = 10;
        this->y = 10;
    }
        void createProjectile(Direction dir)override {}
     void checkProjectile(Board board_win, Characters hero){
         	for (int i = 0; i < projectile.size(); i++)
		{
			if (projectile[i] != NULL){
        if(!projectile[i]->checkCollision(board_win)){
        if(projectile[i]->x=hero.x && projectile[i]->y==hero.y){
            //diminuisci vita player
        }
        board_win.remove(*projectile[i]);
        projectile.erase(projectile.begin()+i);
        }
        else{
            board_win.remove(*projectile[i]);
          projectile[i]->moveCharacter();
          board_win.add(*projectile[i]);
        }
        
    }
        }
     }
    // va via da te
    void ChooseDirection(Board board_win, Characters &hero) override
    {
        int i = 0;
        int distancex, distancey;
        distancex = this->x - hero.x;
        distancey = this->y - hero.y;
            if(hasLos(board_win, hero, this->y, this->x) && abs(distancex) < 10 && abs(distancey) < 10){
            this->mem=EnemyMemory;
            }
        if (this->mem>0){
            Direction horz = (distancex < 0) ? sx : dx;
            Direction ver = (distancey < 0) ? up : down;
            bool pref = abs(distancex) < abs(distancey);
            setDirection((pref) ? horz : ver);
            if (!checkCollision(board_win))
            {
                setDirection((pref) ? ver : horz);
                if (!checkCollision(board_win))
                {
                    if (distancex == 0)
                    {
                        setDirection(sx);
                    }
                    if (distancey == 0)
                    {
                        setDirection(up);
                    }
                }
            }
        }
        this->mem--;
    }
    //line of sight
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