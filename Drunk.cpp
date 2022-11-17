#include "Drunk.hpp"

Drunk::Drunk():Enemy(def,default_coord_x,default_coord_y,'D')
{
	
}


void Drunk::createProjectile(Direction dir) 
{
    if(this->reload<=0){
    this->reload=enemy_reload;
    Projectile *new_proj = new Projectile(dir,this->getx(),this->gety(), 'O');
    projectile.push_back(new_proj); 
    }
    else{
        this->reload--;
    }
}

void Drunk::checkProjectile(Board board_win, Character hero)
{
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
}


void Drunk::ChooseDirection(Board board_win, Character &hero)
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