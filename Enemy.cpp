#include "Enemy.hpp"
#include "Board.hpp"
#include <cmath>


Enemy::Enemy(Direction dir,int y,int x ,chtype ch,int diff):Character(dir,x,y,ch)
{
        difficulty=diff;
         enemy_reload=9-difficulty;
         enemy_memory=7;
         enemy_range=15+(2*difficulty);
         melee_range=3;
         melee_enemy_reload=9-difficulty;
         sight_range= 20+difficulty;
         default_coord_x= 10;
         default_coord_y=10;
         boom_range=2  +int(difficulty/2);
         mem=0;
         reload=0;
         timer=7-int(difficulty/2);


}    
bool Enemy::inSight(int distancex,int distancey){
    return int(sqrt(pow(distancex/2.5,2)+pow(distancey,2)))<this->sight_range;
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