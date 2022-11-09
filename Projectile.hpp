//classe dei proiettili per avere un uptime del range dei proiettili
#pragma once

#include <vector>
#include "Characters.hpp"

class Projectile: public Characters{
    protected:
     int uptime=0;
    public:
   
    Projectile(){
        Characters();
    }
    Projectile(Direction dir, int x, int y, chtype ch){
        Characters(dir,x,y,ch);
    }
    int getUptime(){
        return this->uptime;
    }
    void setUptime(int new_uptime){
        this->uptime=new_uptime;
    }
};