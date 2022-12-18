#include "Enemy.hpp"


Enemy::Enemy(Direction dir, int x, int y, chtype ch):Character(dir,x,y,ch)
{
}    

bool Enemy::hasLos(Board board_win, Character &hero)
{
    int i=0,k=0;
    int distancex, distancey;
    distancex = this->x - hero.getx();
    distancey = this->y - hero.gety();
    bool trovato=false;
    bool empty=true;
    while(!trovato && empty){

    empty=false;

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



    if(board_win.getCharAt(this->y+i,this->x+k)==' '){
    empty==true;
}

if(board_win.getCharAt(this->y+i,this->x+k)==hero.getIcon()){
    trovato==true;
}

        }
        return trovato;
}