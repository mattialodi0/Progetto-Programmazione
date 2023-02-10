#pragma once

#include "Projectile.hpp"
#include "Artifact.hpp"

const int herostartx = (BOARD_COLS / 2);
const int herostarty = (BOARD_ROWS / 2);

class Hero : public Character
{
protected:
	int class_type;
	int key = 1; // numero di chiavi trovate
	int ability;
	int shot = 0;

public:
	Artifact artifact;
	Hero();
	Hero(int c, int y, int x);
	// void Const(int y, int x);
	std::vector<Projectile *> projectile;

	// per l'inizializzazione della classe
	void tankClass();	// melee, hp++, ac++, dmg+, speed-, reload
	void rogueClass();	// melee, hp, ac, dmg++, speed++, reload+
	void rangerClass(); // ranged+, hp-, ac-, dmg, speed+, reload++
	void mageClass();	// ranged, hp-, ac-, dmg++, speed, reload-
	void initclass(int n);
	int getClass();
	// da aggiungere le abilità al bilanciamento
	void useAbility();
	void centerHero(Direction dir);
	bool useKey();
	void addKey(int key);
	void setKey(int key);
	int getKey();

	void increaseHealth(int artifactHp);
	void heal(int artifactHp);
	void increaseDamage(int artifactDmg);
	void increaseRange(int artifactRange);

	// void reduceHealth();
	void attack(Board &board_win, Direction dir);
	void reduceHealthHero(int enemiesDamage);
	bool death();
};