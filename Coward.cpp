#include "Coward.hpp"

Coward::Coward(int y, int x): Enemy(y,x,'C')
    {
      
    }
     void Coward::checkProjectile(Board board_win, Characters hero){
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