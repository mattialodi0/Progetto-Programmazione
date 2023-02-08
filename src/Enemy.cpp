#include "Enemy.hpp"
#include "Board.hpp"
#include <cmath>

Enemy::Enemy(Direction dir,int y,int x ,chtype ch,int difficulty):Character(dir,x,y,ch)
{   
        is_boss=false;
         setMaxReload(9-difficulty);
         setReload(0);
         setRange(10+(2*difficulty));
         sight_range= 20+difficulty;
         boom_range=2  +int(difficulty/2);
         default_coord_x= 10;
         default_coord_y=10;
         mem=0;
         enemy_memory=7;
         timer=7-int(difficulty/2);
         setHp(30+(10*difficulty));
         setDmg(5+difficulty);


}    

Enemy::~Enemy()
{
}


bool Enemy::inSight(int distancex,int distancey){
    return int(abs(sqrt(pow(distancex/2.5,2)+pow(distancey,2))))<this->sight_range;
}

void Enemy::makeBoss(int hp_multiplier,int range_multiplier, int dmg_multiplier){
    this->is_boss=true;
    setMaxHp(getMaxHp()*hp_multiplier);
    setHp(getHp()*hp_multiplier);
    setRange(getRange()*range_multiplier);
    setDmg(getDmg()*dmg_multiplier);
}

bool Enemy::isBoss(){
    return this->is_boss;
}

bool Enemy::hasLos(Board &board_win, Hero &hero)
{
    
    int i=0,k=0, maxiter=0;
    int distancex, distancey;
    distancex = getx() - hero.getx();
    distancey = gety() - hero.gety();

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
    while((board_win.getCharAt(gety()+i,getx()+k)==' '||board_win.getCharAt(gety()+i,getx()+k)=='O')&& maxiter<sight_range+1);

       
if(board_win.getCharAt(gety()+i,getx()+k)==hero.getIcon()){
    return true;
}
        return false;
}



bool Enemy::flyerHasLos(Board &board_win, Hero &hero)
{
    
    int i=0,k=0, maxiter=0;
    int distancex, distancey;
    distancex = getx() - hero.getx();
    distancey = gety() - hero.gety();

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
    while((board_win.getCharAt(gety()+i,getx()+k)==' '||board_win.getCharAt(gety()+i,getx()+k)=='O'||board_win.getCharAt(gety()+i,getx()+k)=='X')&& maxiter<sight_range+1);

       
if(board_win.getCharAt(gety()+i,getx()+k)==hero.getIcon()){
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

