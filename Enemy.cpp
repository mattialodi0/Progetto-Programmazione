#include "Enemy.hpp"


Enemy::Enemy(Direction dir, int x, int y, chtype ch):Character(dir,x,y,ch)
{
}    

bool Enemy::hasLos(Board &board_win, Character &hero)
{
    int i=0,k=0, maxiter=0;
    int distancex, distancey;
    distancex = this->x - hero.getx();
    distancey = this->y - hero.gety();

    do{ 
        maxiter++;
        if (abs(distancex) > abs(distancey))
    {
        if (distancex < 0)
        {
            distancex++;
            k++;
        }
        else
        {
            distancex--;
            k--;
        }
    }
    
      if (abs(distancex) <= abs(distancey))
        {
            if (distancey < 0)
            {
                distancey++;
                i++;
            }
            else
            {
                distancey--;
                i--;
            }
        }
}
    while(board_win.getCharAt(this->y+i,this->x+k)==' '&& maxiter<sight_range+1);

       
if(board_win.getCharAt(this->y+i,this->x+k)==hero.getIcon()){
    return true;
}

        
        return false;
}