#pragma once

#include "Character.hpp"

const int herostartx = (BOARD_COLS/2)+1;
const int herostarty= (BOARD_ROWS/2)+1;

class Hero : public Character
{
public:	
    Hero();
	Hero(int y, int x);
	//void Const(int y, int x);

	//per l'inizializzazione della classe
	tankClass();	//melee, hp++, ac++, dmg+, speed-    t:2
	rogueClass();	//melee, hp-, ac, dmg++, speed++	 t:1
	archerClass();	//ranged+, hp-, ac-, dmg, speed+	 t:2
	mageClass();	//ranged, hp-, ac-, dmg++, speed	 t:1
	//da aggiungere le abilità al bilanciamento

	void centerHero(Direction dir);
};