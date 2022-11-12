#include "Projectile.hpp"

Projectile::Projectile(Direction dir, int x, int y, chtype ch): Characters(0,0,'O')
    {
    }
    int Projectile::getUptime(){
        return this->uptime;
    }
    void Projectile::setUptime(int new_uptime){
        this->uptime=new_uptime;
    }