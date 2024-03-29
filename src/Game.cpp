#include "Game.hpp"

Game::Game(int height, int width, int speed)
{
	srand(time(0));

	game_over = false;

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	game_board = Board(height, width, (yMax / 2) - (height / 2), (xMax / 2) - (width / 2) - (width / 4) - 1, speed);
	game_board.initialize();

	score_board = Board(height / 3, width / 2, (yMax / 2) - (height / 2), (xMax / 2) + (width / 4) + 1, speed);
	score_board.initialize();
	score_board.print("ScoreBoard");
	score_board.refreshBoard();

	stat_board = Board(height - height / 3, width / 2, (yMax / 2) - (height / 2) + (height / 3), (xMax / 2) + (width / 4) + 1, speed);
	stat_board.initialize();
	stat_board.print("StatBoard");
	stat_board.refreshBoard();

	menu.menu();

	hero = Hero(menu.getHero_class(), herostarty, herostartx);
	hero.centerHero(def);

	game_board.setDifficulty(menu.getDiff());

	game_board.setInitialDifficulty();
	// game_board.setDifficultyRate(menu.getDiff_rate());

	checkGameOver(menu.getGame());

	current_room = new Room(game_board);
	room_index.emplace_back(current_room);

	canMove = 0;

	start_time = time(0);
}

bool Game::isNotOver()
{
	return !game_over;
}

void Game::setGameOver()
{
	this->game_over = true;
}

void Game::gameOver()
{
	game_board.clear();
	game_board.printyxWin("Game Over", HALF_ROWS, HALF_COLS-4, ENEMY_PAIR);
	game_board.refreshBoard();
}

void Game::checkGameOver(bool menu)
{
	if (menu == false)
	{
		setGameOver();
	}
}

void Game::processInput()
{
	hero.dimReload();
	chtype input = game_board.getInput();
	int old_timeout = game_board.getTimeout();
	switch (input)
	{
	case 'w':
		hero.setDirection(up);
		break;
	case 's':
		hero.setDirection(down);
		break;
	case 'd':
		hero.setDirection(dx);
		break;
	case 'a':
		hero.setDirection(sx);
		break;
	case KEY_UP:
		if (hero.getReload() <= 0)
		{
			hero.attack(game_board, up);
		}
		break;
	case KEY_DOWN:
		if (hero.getReload() <= 0)
		{
			hero.attack(game_board, down);
		}
		break;
	case KEY_RIGHT:
		if (hero.getReload() <= 0)
		{
			hero.attack(game_board, dx);
		}
		break;
	case KEY_LEFT:
		if (hero.getReload() <= 0)
		{
			hero.attack(game_board, sx);
		}
		break;
	case 'f':
		hero.useAbility(); // abilità speciale della classe
		break;
	case 'o':
		setGameOver();
		break;
	case 'p':
		game_board.setTimeout(-1);
		if (menu_playing.menu())
		{
			setGameOver();
		}
		game_board.setTimeout(old_timeout);
	default:
		hero.setDirection(def); // per non forzare movimento
		break;
	}
}

void Game::updateState()
{
	error_type = 0;
	// hero
	// game_board.remove(hero);

	if (hero.death())
	{
		setGameOver();
	}

	manageHeroMovement();
	hero.setDirection(def);
	int killed = 0;
	current_room->checkHeroProjectile(game_board, hero); //--> da mettere dentro a hero
	killed = current_room->checkEnemiesHp(game_board);

	for (int i = 0; i < killed; i++)
	{
		addScore();
	}
	// enemies

	if (canMove <= 0)
	{
		current_room->moveEnemies(game_board, hero);
		canMove = GameSpeed;
	}
	else
	{
		canMove--;
	}
}

void Game::updateScreen()
{
	redraw();
	game_board.refreshBoard();

	refreshStat(hero); // funzione che stampa le statistiche nella finestra dedicata
	stat_board.refreshBoard();
	stat_board.addBorder();

	refreshScore(hero); // funzione che stampa lo score nella finestra dedicata
	score_board.refreshBoard();
	score_board.addBorder();
}

void Game::redraw() // riaggiunge
{
	current_room->drawRoom(game_board);
	game_board.add(hero);
}

int Game::getScore()
{
	return this->score;
}

void Game::addScore()
{
	this->score = this->score + addedScore;
}

void Game::manageHeroMovement()
{

	int offsety = 0, offsetx = 0;
	if (hero.getDirection() == up || hero.getDirection() == down)
	{
		// offset per row e col per collisione
		offsety = hero.getDirection() / 2;
	}
	else
	{
		if (hero.getDirection() == dx || hero.getDirection() == sx)
		{
			offsetx = hero.getDirection();
		}
	}
	// if(!game_board.getTaken(hero.getx()+offsetx,hero.gety()+offsety)){
	switch (game_board.getCharAt(hero.gety() + offsety, hero.getx() + offsetx))
	{
	case ' ':
	case 'o':
		hero.moveCharacter(game_board);
		break;
	case 'E':
		hero.moveCharacter(game_board);
		hero.heal(artifactHeal);
		hero.increaseDamage(artifactDmg);
		current_room->removeArtifact(0);
		break;
	case 'H':
		hero.moveCharacter(game_board);
		hero.increaseHealth(artifactHp);
		hero.heal(artifactHeal);
		current_room->removeArtifact(0);
		break;
	case 'R':
		hero.moveCharacter(game_board);
		hero.increaseRange(artifactRange);
		hero.heal(artifactHeal);
		current_room->removeArtifact(0);
		break;
	case 'J':
		hero.moveCharacter(game_board);
		hero.addKey(1);
		hero.heal(artifactHeal);
		current_room->removeArtifact(0);
		break;
	case 'A':
		hero.moveCharacter(game_board);
		hero.rechargeAbility();
		current_room->removeArtifact(0);
		break;
	case 'O': // cambia stanza
		if (hero.gety() > 1 && hero.gety() < BOARD_ROWS - 2 && hero.getx() > 1 && hero.getx() < BOARD_COLS - 2)
			hero.moveCharacter(game_board);
		else
		{
			while (hero.projectile.size() > 0)
			{
				hero.projectile.erase(hero.projectile.begin());
			}
			manageDoor();
		}
		break;
	case 'Q':
		if (hero.useKey())
		{
			current_room->unlockDoor(hero.gety() + offsety, hero.getx() + offsetx, game_board);
		}
		else
			error_type = 2;
		break;
	default:
		break;
	}
	//}
}

void Game::manageDoor()
{
	this->difficulty = game_board.refreshDifficulty(getScore());
	if (current_room->isClear())
	{
		// updateDifficulty();
		game_board.addAt(hero.gety(), hero.getx(), ' ');
		game_board.clearTaken();
		game_board.clear();
		if (hero.gety() <= 1)
		{
			if (current_room->getNorth() != NULL) // se non la stanza non è ancora stata generata
				moveToNorthRoom();
			else
				makeNorthRoom();
		}
		else if (hero.gety() >= BOARD_ROWS - 2)
		{
			if (current_room->getSouth() != NULL) // se non la stanza non è ancora stata generata
				moveToSouthRoom();
			else
				makeSouthRoom();
		}
		else if (hero.getx() <= 1)
		{
			if (current_room->getWest() != NULL) // se non la stanza non è ancora stata generata
				moveToWestRoom();
			else
				makeWestRoom();
		}
		else if (hero.getx() >= BOARD_COLS - 2)
		{
			if (current_room->getEst() != NULL) // se non la stanza non è ancora stata generata
				moveToEstRoom();
			else
				makeEstRoom();
		}
	}
	else
		error_type = 1;
}

// funzioni per cambiare stanza
void Game::moveToNorthRoom()
{
	current_room = current_room->getNorth();
	// posiziona il giocatore in basso
	hero.centerHero(hero.getDirection());
}
void Game::moveToSouthRoom()
{
	current_room = current_room->getSouth();
	// posiziona il giocatore in alto
	hero.centerHero(hero.getDirection());
}
void Game::moveToWestRoom()
{
	current_room = current_room->getWest();
	// posiziona il giocatore a destra
	hero.centerHero(hero.getDirection());
}
void Game::moveToEstRoom()
{
	current_room = current_room->getEst();
	// posiziona il giocatore a sinistra
	hero.centerHero(hero.getDirection());
}

// funzioni per creare nuove stanze
void Game::makeNorthRoom()
{
	prm p = new Room(current_room->gety() + 1, current_room->getx(), room_index, 1, game_board);
	current_room->setNorth(p);
	updateIndex(current_room->getNorth());
	addRoomToIndex(current_room->getNorth());
	moveToNorthRoom();
}
void Game::makeSouthRoom()
{
	prm p = new Room(current_room->gety() - 1, current_room->getx(), room_index, -1, game_board);
	current_room->setSouth(p);
	updateIndex(current_room->getSouth());
	addRoomToIndex(current_room->getSouth());
	moveToSouthRoom();
}
void Game::makeWestRoom()
{
	prm p = new Room(current_room->gety(), current_room->getx() - 1, room_index, -2, game_board);
	current_room->setWest(p);
	updateIndex(current_room->getWest());
	addRoomToIndex(current_room->getWest());
	moveToWestRoom();
}
void Game::makeEstRoom()
{
	prm p = new Room(current_room->gety(), current_room->getx() + 1, room_index, 2, game_board);
	current_room->setEst(p);
	updateIndex(current_room->getEst());
	addRoomToIndex(current_room->getEst());
	moveToEstRoom();
}

void Game::addRoomToIndex(prm room)
{
	this->room_index.emplace_back(room);
}

void Game::updateIndex(prm room)
{
	for (int i = 0; i < room_index.size(); i++)
	{
		if (room_index[i]->gety() == room->gety() + 1 && room_index[i]->getx() == room->getx())
			room_index[i]->setSouth(room);
		if (room_index[i]->gety() == room->gety() - 1 && room_index[i]->getx() == room->getx())
			room_index[i]->setNorth(room);
		if (room_index[i]->gety() == room->gety() && room_index[i]->getx() == room->getx() - 1)
			room_index[i]->setEst(room);
		if (room_index[i]->gety() == room->gety() && room_index[i]->getx() == room->getx() + 1)
			room_index[i]->setWest(room);
	}
}

void Game::refreshStat(Hero &hero)
{
	int c = hero.getClass();
	switch (c)
	{
	case 1:
		stat_board.printyxWin("Class:       Tank", 2, 2);
		break;
	case 2:
		stat_board.printyxWin("Class:       Rogue", 2, 2);
		break;
	case 3:
		stat_board.printyxWin("Class:       Ranger", 2, 2);
		break;
	default:
		stat_board.printyxWin("Class:       Mage", 2, 2);
		break;
	}
	int hp = hero.getHp();
	int i, j = 0;
	stat_board.printyxWin("                      ", 3, 2);
	stat_board.printyxWin("Health: ", 3, 2);
	for (i = 1; i * 10 <= hp; i++)
	{ // cuori pieni
		stat_board.printyxWin("♥", 3, j + 15, ENEMY_PAIR);
		j++;
	}
	for (i; i * 10 <= hero.getMaxHp(); i++)
	{ // cuori vuoti
		stat_board.printyxWin("♡", 3, j + 15);
		j++;
	}
	stat_board.printyxWin("                      ", 4, 2);
	stat_board.printWin("Hp: ", 4, hp);

	int dmg = hero.getDmg();
	stat_board.printyxWin("                      ", 5, 2);
	stat_board.printWin("Damage: ", 5, dmg);

	int reload = hero.getMaxReload();
	stat_board.printyxWin("                      ", 6, 2);
	stat_board.printWin("Reload time: ", 6, reload);

	int range = hero.getRange();
	stat_board.printyxWin("                      ", 7, 2);
	stat_board.printWin("Range: ", 7, range);

	stat_board.printyxWin("                      ", 8, 2);
	stat_board.printWin("Keys: ", 8, hero.getKey());

	stat_board.printyxWin("                      ", 10, 2);
	stat_board.printWin("Room (y,x): ", 10, current_room->gety(), current_room->getx());
	displayError();
}

void Game::refreshScore(Hero &hero)
{
	score_board.printWin("Score: ", 2, getScore());
	score_board.printyxWin("                      ", 4, 2);
	score_board.printWin("Time: ", 4, getTime());
	if(game_board.getDifficulty()<3)
	{
		score_board.printyxWin("Difficulty:", 6, 2);
		score_board.printyxWin("Easy", 6, 15, LIFE_PAIR);
	}
	else{
		if(game_board.getDifficulty()>7){
		score_board.printyxWin("Difficulty:", 6, 2);
		score_board.printyxWin("Hard", 6, 15, ENEMY_PAIR);
		}
		else{
		score_board.printyxWin("Difficulty:", 6, 2);
		score_board.printyxWin("Medium", 6, 15, ERROR_PAIR);
		}
	}
	//score_board.printWin("Difficulty: ", 6, game_board.getDifficulty());
}

void Game::displayError()
{
	switch (error_type)
	{
	case 1:
		stat_board.printyxWin("There are enemies left", 15, 2, ERROR_PAIR);
		break;
	case 2:
		stat_board.printyxWin("You have no more keys", 15, 2, ERROR_PAIR);
		break;
	default:
		stat_board.printyxWin("                      ", 15, 2, ERROR_PAIR);
		break;
	}
}

int Game::getTime() 
{
	return time(0) - start_time;
}