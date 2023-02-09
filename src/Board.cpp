#include "Board.hpp"

Board::Board():Board(0, 0, 300)
{
	for(int i=0;i<BOARD_COLS;i++){
	for(int j=0;j<BOARD_ROWS;j++){
	taken[i][j]=false;	
	}	
	}
	init_pair(BOSS_PAIR, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(ENEMY_PAIR, COLOR_RED, COLOR_BLACK);
	init_pair(ARTIFACT_PAIR, COLOR_BLUE, COLOR_BLACK);
	init_pair(DOOR_PAIR, COLOR_YELLOW, COLOR_BLACK);
}

Board::Board(int height, int width, int speed)
{
	difficulty=0;
	for(int i=0;i<BOARD_COLS;i++){
	for(int j=0;j<BOARD_ROWS;j++){
	taken[i][j]=false;	
	}	
	}
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	board_win = newwin(height, width, (yMax / 2) - (height / 2),
					   (xMax / 2) - (width / 2));
	timeout = speed;
	setTimeout(speed);
	keypad(board_win, true);
	init_pair(BOSS_PAIR, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(ENEMY_PAIR, COLOR_RED, COLOR_BLACK);
	init_pair(ARTIFACT_PAIR, COLOR_BLUE, COLOR_BLACK);
	init_pair(DOOR_PAIR, COLOR_YELLOW, COLOR_BLACK);
}

Board::Board(int height, int width, int starty, int startx, int speed)
{
	difficulty=0;
	for(int i=0;i<BOARD_COLS;i++){
	for(int j=0;j<BOARD_ROWS;j++){
	taken[i][j]=false;	
	}	
	}
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	board_win = newwin(height, width, starty, startx);
	timeout = speed;
	setTimeout(speed);
	keypad(board_win, true);
	init_pair(BOSS_PAIR, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(ENEMY_PAIR, COLOR_RED, COLOR_BLACK);
	init_pair(ARTIFACT_PAIR, COLOR_BLUE, COLOR_BLACK);
	init_pair(DOOR_PAIR, COLOR_YELLOW, COLOR_BLACK);
}

void Board::initialize() 
{
    clear();
	wrefresh(board_win);
}

void Board::add(Drawable &drawable) 
{
    addAt(drawable.gety(), drawable.getx(), drawable.getIcon());
}

/* usata per aggiungere gli artefatti, disegnati in blu */
void Board::add_A(Drawable &drawable) 
{
	wattron(board_win,COLOR_PAIR(ARTIFACT_PAIR));
    addAt(drawable.gety(), drawable.getx(), drawable.getIcon());		//mvwaddstr(board_win, drawable.gety(), drawable.getx(), "\u265E");
	wattroff(board_win,COLOR_PAIR(ARTIFACT_PAIR));
}

/* usata per aggiungere i nemici, disegnati in rosso */
void Board::add_E(Drawable &drawable) 
{
	wattron(board_win,COLOR_PAIR(ENEMY_PAIR));
    addAt(drawable.gety(), drawable.getx(), drawable.getIcon());
	wattroff(board_win,COLOR_PAIR(ENEMY_PAIR));
}

/* usata per aggiungere i boss, disegnati in viola */
void Board::add_B(Drawable &drawable) 
{
	wattron(board_win,COLOR_PAIR(BOSS_PAIR));
    addAt(drawable.gety(), drawable.getx(), drawable.getIcon());
	wattroff(board_win,COLOR_PAIR(BOSS_PAIR));
}

/* usata per aggiungere le porte, disegnate in giallo */
void Board::add_D(Drawable &drawable) 
{
	wattron(board_win,COLOR_PAIR(DOOR_PAIR));
    addAt(drawable.gety(), drawable.getx(), drawable.getIcon());
	wattroff(board_win,COLOR_PAIR(DOOR_PAIR));
}

void Board::remove(Drawable &drawable) 
{
    addAt(drawable.gety(), drawable.getx(), ' ');
}
   
void Board::addAt(int y, int x, chtype ch) 
{	
	switch(ch){
		case ' ':
		case '-':
		case '|':
		case 'O':
		case 'o':
		case 'R':
		case 'J':
		case 'E':
		case 'H':
		setTaken(x,y,false);
		break;
	 default:
	setTaken(x,y,true);
	break;
	}
	mvwaddch(board_win, y, x, ch);
}


int Board::refreshDifficulty(int score){
	setDifficulty(score/difficultyRate);
	return score/difficultyRate;
}

void Board::print(const char* str) 
{
	wprintw(board_win, str);
}
void Board::print(chtype c) 
{
	mvwaddch(board_win, 1, 1, c);
}


chtype Board::getInput()                   //*******************
{
	time_t time_last_input = Time::milliseconds();
	chtype input = wgetch(board_win);
	chtype new_input = ERR;
	setTimeout(0);
	while (time_last_input + timeout >= Time::milliseconds())
	{
		new_input = wgetch(board_win);
	};
	setTimeout(timeout);
	if (new_input != ERR)
	{
		input = new_input;
	};
	return input;
}
    
void Board::getEmptyCoordinates(int &y, int &x) 
{
    srand(time(NULL));
	do{
		x = rand() % BOARD_COLS;
		y = rand() % BOARD_ROWS;
	}
	while ((mvwinch(board_win,y,x)) != ' '||this->getTaken(x,y)) ;     //************
}

int Board::getDifficulty(){
	return this->difficulty;
}
void Board::setDifficulty(int diff){
	this->difficulty=diff;
}
void Board::setDifficultyRate(int diff){
	this->difficultyRate=diff;
}


void Board::setTimeout(int timeout)
{
	wtimeout(board_win, timeout);
}

void Board::setTaken(int x, int y,bool set){
this->taken[x][y]=set;

}
bool Board::getTaken(int x, int y){

	return this->taken[x][y];
}

void Board::clearTaken(){
	for(int x=0;x<BOARD_COLS;x++){
        for(int y=0;y<BOARD_ROWS;y++){
         setTaken(x,y,false);
		 }
    }
}

int Board::getTimeout()
{
	return this->timeout;
}

void Board::clear () 
{
	wclear(board_win);
	addBorder();
}

void Board::refreshBoard()
{
	wrefresh(board_win);
}

void Board::addBorder()
{
	box(board_win, 0, 0);
}

chtype Board::getCharAt(int y, int x)
{
	return mvwinch(board_win, y, x);
}

void Board::printStats(char* str, int y, int stat)
{
	char* buffer = (char *)malloc(3 * sizeof(char));
	sprintf(buffer, "%d", stat);
	mvwprintw(board_win, y, 2, str);
	mvwprintw(board_win, y, 10, buffer);
}   
