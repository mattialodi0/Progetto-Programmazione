#include "Board.hpp"

void Board::construct(int height, int width, int speed)
	{
		int yMax, xMax;
		getmaxyx(stdscr, yMax, xMax);
		timeout = speed;
		board_win = newwin(height, width, (yMax / 2) - (height / 2),
						   (xMax / 2) - (width / 2));
		setTimeout(speed);
		keypad(board_win, true);
	}

	Board::Board()
	{
		construct(0, 0, 300);
	}

	Board::Board(int height, int width, int speed)
	{
		srand(time(0));
		construct(height, width, speed);
	}

	void Board::initialize()
	{
		clear();
		refresh();
	}
	void Board::clear()
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
	// tutto questo sopra e' per init del board
	void Board::add(Drawable &drawable)
	{
		addAt(drawable.gety(), drawable.getx(), drawable.getIcon());
		// add per general use
	}
	void Board::remove(Drawable &drawable)
	{
		addAt(drawable.gety(), drawable.getx(), ' ');
	}

	void Board::addAt(int y, int x, chtype ch)
	{
		// add
		mvwaddch(board_win, y, x, ch);
	}

	chtype Board::getInput()
	// input e fixed time
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
	{																									// for future use
		srand(time(NULL));
		while ((mvwinch(board_win, y = rand() % BOARD_ROWS, x = rand() % BOARD_COLS)) != ' ')
		{
		}
	}

	chtype Board::getCharAt(int y, int x)
	{
		return mvwinch(board_win, y, x);
	}

	void Board::setTimeout(int timeout)
	{
		wtimeout(board_win, timeout);
	}

	int Board::getTimeout()
	{
		return this->timeout;
	}