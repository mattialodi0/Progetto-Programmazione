//classe base nemico con stat dei nemici
#pragma once
#ifndef ENEMY_HPP
#define ENEMY_HPP   

#include <vector>
//#include "Hero.hpp"
#include "Projectile.hpp"

const int enemy_reload=8;            //ho tolto extern
const int enemy_memory=7;
const int range=11;
const int melee_range=2;
const int melee_enemy_reload=5;
const int sight_range= 100;
class Enemy:public Characters{
    protected: 
    int mem=0;
    int reload=0;
    public:
    std::vector<Projectile *> projectile;
    Enemy(int y, int x, chtype ch);

    virtual void createProjectile(Direction dir)
    {
    }
    virtual void checkProjectile(Board board_win, Characters hero)
    {
    }
     	// metodo astratto per scelta automatica di direzione dei nemici
	virtual void ChooseDirection(Board board_win, Characters &hero)
	{
	}
bool hasLos(Board board_win, Characters hero, int y, int x);

};  

#endif