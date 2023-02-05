#include <ncurses.h>
#include <iostream>

const int refreshspeed = 100;   //velocità di refresh dello schermo

int main()
{
    // funzioni init di ncurses
	initscr();
	noecho();
	cbreak();
	refresh();
	curs_set(0);
	start_color();
	
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);

    
    WINDOW * win = newwin(8,15,1,1);
    box(win,0,0);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
    wattron(win,COLOR_PAIR(1));
    mvwprintw(win,1,1,"colored text");
    wrefresh(win);
    getch();
	
	endwin();
	std::cout << "game over\n";
	return 0;
}