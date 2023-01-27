#pragma once

#include "Character.hpp"
#include "Projectile.hpp"
#include "Artifact.hpp"

const int herostartx = (BOARD_COLS/2);
const int herostarty= (BOARD_ROWS/2);

class Hero : public Character
{
protected:
	int class_type;
	int key=1;	//numero di chiavi trovate
    int ac = 3;
    int dmg = 2;
    int speed = 1;
    int reload_time=3;
    int range = 2;
public:	
	Artifact artifact;
	int hp = 30;
    Hero();
	Hero(int y, int x);
	//void Const(int y, int x);
    std::vector<Projectile*> projectile;

	//per l'inizializzazione della classe
	void tankClass();	//melee, hp++, ac++, dmg+, speed-, reload
	void rogueClass();	//melee, hp, ac, dmg++, speed++, reload+
	void rangerClass();	//ranged+, hp-, ac-, dmg, speed+, reload++
	void mageClass();	//ranged, hp-, ac-, dmg++, speed, reload-
	//da aggiungere le abilità al bilanciamento
	void useAbility();
	void attack(Direction dir);

	void centerHero(Direction dir);
	bool useKey();

	void increaseHealth();
	void increaseDamage();
	void increaseRange();
	//void reduceHealth();

	void takenArtifact();
};