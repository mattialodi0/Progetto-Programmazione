#include "Coward.hpp"

Coward::Coward():Enemy(def,10,10,'K')
{
}

void Coward::createProjectile(Direction dir) 
{
  /*  if(this->reload<=0){
    this->reload=enemy_reload;
    Projectile *new_proj = new Projectile(dir,this->getx(),this->gety(), 'O');
    projectile.push_back(new_proj); 
    }
    else{
        this->reload--;
    }
    */
}

void Coward::checkProjectile(Board board_win, Character &hero)
{
    /*
    for (int i = 0; i < projectile.size(); i++)
	{
		if (projectile[i] != NULL){
            projectile[i]->setUptime((projectile[i]->getUptime())+1);
            board_win.remove(*projectile[i]);
            if(!projectile[i]->checkCollision(board_win)|| projectile[i]->getUptime()>melee_range){
                projectile[i]->moveCharacter();
                if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
                //diminuisci vita player
                }    
                projectile.erase(projectile.begin()+i);
            }
            else{
                projectile[i]->moveCharacter();
                if(board_win.getCharAt(projectile[i]->gety(),projectile[i]->getx())){
                    board_win.add(*projectile[i]);
                }
            }
    
        }
    }
    */
}

void Coward::chooseDirection(Board board_win, Character &hero)
{int i = 0;
        int distancex, distancey;
        distancex = this->x - hero.getx();
        distancey = this->y - hero.gety();
            if(hasLos(board_win, hero) && abs(distancex) < sight_range && abs(distancey) < sight_range){
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