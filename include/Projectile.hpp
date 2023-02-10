#pragma once

#include <vector>
#include "Character.hpp"

class Projectile : public Character
{
protected:
    int uptime = 0;

public:
    Projectile(Direction dir, int x, int y, chtype ch);
    int getUptime();
    void setUptime(int new_uptime);
};