#include "Board.hpp"

Board::Board():Board(0, 0, 300)
{
	
}

Board::Board(int height, int width, int speed)
{
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	board_win = newwin(height, width, (yMax / 2) - (height / 2),
					   (xMax / 2) - (width / 2));
	timeout = speed;
	setTimeout(speed);
	keypad(board_win, true);
}

Board::Board(int height, int width, int starty, int startx, int speed)
{
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	board_win = newwin(height, width, starty, startx);
	timeout = speed;
	setTimeout(speed);
	keypad(board_win, true);
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

void Board::remove(Drawable &drawable) 
{
    addAt(drawable.gety(), drawable.getx(), ' ');
}
   
void Board::addAt(int y, int x, chtype ch) 
{
	mvwaddch(board_win, y, x, ch);
}

void Board::print(const char* str) 
{
	wprintw(board_win, str);
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
	while ((mvwinch(board_win, y = rand() % BOARD_ROWS, x = rand() % BOARD_COLS)) != ' ') ;     //************
}

void Board::setTimeout(int timeout)
{
	wtimeout(board_win, timeout);
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