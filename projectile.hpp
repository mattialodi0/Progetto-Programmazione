//classe dei proiettili per avere un uptime del range dei proiettili
#pragma once
#include "characters.hpp"
class Projectile: public Characters{
    public:
    int uptime=0;
    Projectile(){
        Characters();
    }

};