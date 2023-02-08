#include "Projectile.hpp"


Projectile::Projectile(Direction dir, int x, int y, chtype ch) :Character(dir,x,y,ch)
{
   
}

int Projectile::getUptime()
{
 return this->uptime;
}

void Projectile::setUptime(int new_uptime)
{
    this->uptime=new_uptime;
}