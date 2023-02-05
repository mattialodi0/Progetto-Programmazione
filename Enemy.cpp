#include "Enemy.hpp"
#include "Board.hpp"
#include <cmath>

const int herodamage = 3;

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
         hp=30+(10*difficulty);
         dmg=5+difficulty;


}    
bool Enemy::inSight(int distancex,int distancey){
    return int(abs(sqrt(pow(distancex/2.5,2)+pow(distancey,2))))<this->sight_range;
}

bool Enemy::hasLos(Board &board_win, Hero &hero)
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
    while((board_win.getCharAt(this->y+i,this->x+k)==' '||board_win.getCharAt(this->y+i,this->x+k)=='O')&& maxiter<sight_range+1);

       
if(board_win.getCharAt(this->y+i,this->x+k)==hero.getIcon()){
    return true;
}
        return false;
}

int Enemy::getHp(){
    return this->hp;
}

bool Enemy::flyerHasLos(Board &board_win, Hero &hero)
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
    while((board_win.getCharAt(this->y+i,this->x+k)==' '||board_win.getCharAt(this->y+i,this->x+k)=='O'||board_win.getCharAt(this->y+i,this->x+k)=='X')&& maxiter<sight_range+1);

       
if(board_win.getCharAt(this->y+i,this->x+k)==hero.getIcon()){
    return true;
}

        
        return false;
}
bool Enemy:: getisFlyer(){
    return this->isFlyer;
}
void Enemy:: setisFlyer(bool set){
    this->isFlyer=set;
}

void Enemy::reduceHealthEnemy(int heroDamage)
{
    hp = hp - herodamage;
}

