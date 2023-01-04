#pragma once

#include "Character.hpp"
#include "Projectile.hpp"

const int herostartx = (BOARD_COLS/2);
const int herostarty= (BOARD_ROWS/2);

class Hero : public Character
{
protected:
	int class_type;
	int key=1;	//numero di chiavi trovate
public:	
	std::vector<Projectile *> projectile;
    Hero();
	Hero(int y, int x);
	//void Const(int y, int x);

	//attacco eroe
	virtual void createProjectile(Direction dir);

	//per l'inizializzazione della classe
	void tankClass();	//melee, hp++, ac++, dmg+, speed-, reload
	void rogueClass();	//melee, hp, ac, dmg++, speed++, reload+
	void rangerClass();	//ranged+, hp-, ac-, dmg, speed+, reload++
	void mageClass();	//ranged, hp-, ac-, dmg++, speed, reload-
	//da aggiungere le abilità al bilanciamento
	void useAbility();
	void attack(Direction dir);

	void centerHero(Direction dir);
	void reduceHealth();
	void increaseHealth();
	void increaseDamage();
	void increaseRange();
	bool useKey();
};