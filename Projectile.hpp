//classe dei proiettili per avere un uptime del range dei proiettili
#pragma once

#include <vector>
#include "Characters.hpp"

class Projectile: public Characters{
    public:
    int uptime=0;
    Projectile(){
        Characters();
    }
    Projectile(Direction dir, int x, int y, chtype ch){
        Characters(dir,x,y,ch);
    }
};