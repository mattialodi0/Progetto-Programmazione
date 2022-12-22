#include "Drunk.hpp"

Drunk::Drunk():Enemy(def,13,13,'D')
{
	
}


void Drunk::createProjectile(Board &board_win, Character &hero, Direction dir) 
{
    
    if(this->reload<=0){
    this->reload=enemy_reload;
    Projectile *new_proj = new Projectile(dir,this->getx(),this->gety(), 'o');
    projectile.push_back(new_proj); 
    switch(dir){
    case up:
    new_proj->sety(new_proj->gety()-1);
    break;
    case down:
    new_proj->sety(new_proj->gety()+1);
    break;
    case dx:
    new_proj->setx(new_proj->getx()+1); 
    break;
    case sx:
     new_proj->setx(new_proj->getx()-1);
    break;
    }
    }
    else{
        this->reload--;
    }
}

void Drunk::checkProjectile(Board &board_win, Character &hero)
{
    for (int i = 0; i < projectile.size(); i++)
	{
		if (projectile[i] != NULL){
            projectile[i]->setUptime((projectile[i]->getUptime())+1);
            
            if(!projectile[i]->checkCollision(board_win)|| projectile[i]->getUptime()>melee_range||(board_win.getCharAt(projectile[i]->gety(),projectile[i]->getx())!=' '&&board_win.getCharAt(projectile[i]->gety(),projectile[i]->getx())!=projectile[i]->getIcon())){
                projectile[i]->moveCharacter();
                if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
                //diminuisci vita player
                }    
                projectile.erase(projectile.begin()+i);
            }
            else{
                projectile[i]->moveCharacter();
               
            }
    
        }
    }
}


void Drunk::chooseDirection(Board &board_win, Character &hero)
{
	{
		int n = (rand() % 5) - 2;
		switch (n)
		{
		case -2:
			setDirection(up);
			break;
		case 2:
			setDirection(down);
			break;
		case -1:
			setDirection(sx);
			break;
		case 1:
			setDirection(dx);
			break;
		default:
			break;
		}
	} while (!checkCollision(board_win));
}