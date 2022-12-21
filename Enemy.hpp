#pragma once

#include "Character.hpp"
#include "Projectile.hpp"
#include <vector>

const int enemy_reload=5;
const int enemy_memory=7;
const int enemy_range=11;
const int melee_range=3;
const int melee_enemy_reload=5;
const int sight_range= 20;
const int default_coord_x= 10;
const int default_coord_y=10;

class Enemy : public Character {
protected: 
    int mem=0;
    int reload=0;
public:
    std::vector<Projectile*> projectile;
public:
    Enemy(Direction dir, int x, int y, chtype ch);
    virtual void createProjectile(Direction dir) {}
    virtual void checkProjectile(Board &board_win, Character &hero) {}
    
    // metodo astratto per scelta automatica di direzione dei nemici
	virtual void chooseDirection(Board &board_win, Character &hero) {}

    bool hasLos(Board &board_win, Character &hero);
};  

typedef Enemy * pEn;