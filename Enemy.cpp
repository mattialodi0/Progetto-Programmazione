#include "Enemy.hpp"


Enemy::Enemy(Direction dir, int x, int y, chtype ch):Character(dir,x,y,ch)
{
}    

bool Enemy::hasLos(Board board_win, Character hero, int y, int x)
{
    int i=0,k=0;
    int distancex, distancey;
    distancex = x - hero.getx();
    distancey = y - hero.gety();
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
        if(f==hero.getIcon()){
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