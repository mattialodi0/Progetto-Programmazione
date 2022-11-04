#include <iostream>
#include <ncurses.h>
using namespace std;
int main() {
initscr();
int height=10, width=20.,starty=10, startx=10;
WINDOW* win =newwin(height, width,starty,startx);
refresh();
box(win,0,0);
wrefresh(win);
int c= getch();
endwin();
    return 0;
}