#include "Shooter.hpp"
    Shooter::Shooter(int y, int x):Enemy(y,x,'C')
    {
    }
    void Shooter::checkProjectile(Board board_win, Characters hero){
        for (int i = 0; i < projectile.size(); i++)
		{
			if (projectile[i] != NULL){
                projectile[i]->setUptime((projectile[i]->getUptime())+1);
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
          if(board_win.getCharAt(projectile[i]->gety(),projectile[i]->getx())){
          board_win.add(*projectile[i]);
          }
        }
    }
        }
     }