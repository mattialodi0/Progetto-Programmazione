#pragma once

#include "Character.hpp"

const int herostartx = (BOARD_COLS/2);
const int herostarty= (BOARD_ROWS/2);

class Hero : public Character
{
public:	
    Hero();
	Hero(int y, int x);
	//void Const(int y, int x);

	//per l'inizializzazione della classe
	void tankClass();	//melee, hp++, ac++, dmg+, speed-    t:2
	void rogueClass();	//melee, hp-, ac, dmg++, speed++	 t:1
	void rangerClass();	//ranged+, hp-, ac-, dmg, speed+	 t:2
	void mageClass();	//ranged, hp-, ac-, dmg++, speed	 t:1
	//da aggiungere le abilità al bilanciamento
	void useAbility();

	void centerHero(Direction dir);
};