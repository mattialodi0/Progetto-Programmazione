// nemico che scappa
// probabilmente da implementare loot come artifatti e chiavi
#pragma once

#include "Enemy.hpp"

class Coward : public Enemy
{
public:
    Coward(int y, int x): Enemy(y,x,'C')
    {
      
    }
        void createProjectile(Direction dir)override {}
     void checkProjectile(Board board_win, Characters hero){
         	for (int i = 0; i < projectile.size(); i++)
		{
			if (projectile[i] != NULL){
        if(!projectile[i]->checkCollision(board_win)){
        if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
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
        distancex = this->x - hero.getx();
        distancey = this->y - hero.gety();
            if(hasLos(board_win, hero, this->y, this->x) && abs(distancex) < sight_range && abs(distancey) < sight_range){
            this->mem=enemy_memory;
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
};