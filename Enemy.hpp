//classe base nemico con stat dei nemici
#pragma once
#include "Characters.hpp"
#include <vector>
#include "Hero.hpp"
#include "Projectile.hpp"
using namespace std;
const int EnemyReload=8;
extern const int EnemyMemory=7;
extern const int Range=11;
extern const int MeleeRange=2;
extern const int MeleeEnemyReload=5;
class Enemy:public Characters{
    protected: 
    int mem=0;
    int Reload=0;
    public:
    vector<Projectile *> projectile;
    Enemy(){Characters();}
    virtual void createProjectile(Direction dir){
    }
    virtual void checkProjectile(Board board_win, Characters hero)
    {
    }
     	// metodo astratto per scelta automatica di direzione dei nemici
	virtual void ChooseDirection(Board board_win, Characters &hero)
	{
	}
    virtual bool hasLos(Board board_win, Characters hero, int y, int x){
        return false;
    }
};