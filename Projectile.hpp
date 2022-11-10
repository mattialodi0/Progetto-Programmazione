//classe dei proiettili per avere un uptime del range dei proiettili
#pragma once

#include <vector>
#include "Characters.hpp"

class Projectile: public Characters{
    protected:
     int uptime=0;
    public:
    Projectile(Direction dir, int x, int y, chtype ch);
    int getUptime();
    void setUptime(int new_uptime);
};