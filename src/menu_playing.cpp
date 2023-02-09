#include <ncurses.h>
#include "menu_playing.hpp"
using namespace std;


bool Menu_playing::menu(){

    initscr();
    cbreak();
    noecho();

    //prende le dimensioni della finestra
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    //crea una finestra per l'input
    WINDOW * menuwin = newwin(25, 67+(67/2), (yMax-24)/2, (xMax-100)/2);
    box(menuwin, 0 ,0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);      //makes arrows keys usable
    
    char* choices[3] = {"Resume", "Commands", "exit"};
    int choice;
    int highlight = 0;

    while(1) {
       for(int i = 0; i < 3; i++) {
            if(i == highlight) 
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, choices[i]);
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch(choice) {
            case KEY_UP:
                highlight--;
                if(highlight < 0)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight > 2)
                    highlight = 2;
                break;
            default:
                break;
        }
        if(choice == 10)
            break;        
    }

    if (highlight==0){
        return false;
    }
    if (highlight==1){
        commands();
        return false;
    }
    if (highlight==2){
        return true;
    
    }

}


void Menu_playing::commands(){

    initscr();
    cbreak();
    noecho();

    //prende le dimensioni della finestra
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    //crea una finestra per l'input
    WINDOW * menuwin = newwin(25, 67+(67/2), (yMax-24)/2, (xMax-100)/2);
    box(menuwin, 0 ,0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);      //makes arrows keys usable
    
    int iy = (yMax/2)-10;
    int ix = (xMax/2)-20;

    //char* comln = " Keybindings :";
    mvwprintw(menuwin, iy, ix, " Keybindings :");

    //char* comln1 = " W-A-S-D = Movement ";
    mvwprintw(menuwin, iy+2, ix, " W-A-S-D = Movement ");

    //char* comln2 = " Arrow keys = Attack in choosen direction ";
    mvwprintw(menuwin, iy+3, ix, " Arrow keys = Attack in choosen direction ");

    //char* comln3 = " F = Use special ability ";
    mvwprintw(menuwin, iy+4, ix, " F = Use special ability ");

    //char* comln4 = " O = Quit the game";
    //mvwprintw(menuwin, iy+5, ix, " O = Quit the game");

    //char* comln5 = " P = Pause the game ";
    mvwprintw(menuwin, iy+5, ix, " P = Pause the game ");

    //char* comln6 = " E = Increase damage";
    //mvwprintw(menuwin, iy+7, ix, " E = Increase damage");

    //char* comln7 = " H = Increase healt";
    //mvwprintw(menuwin, iy+8, ix, " H = Increase healt");

    //char* comln8 = " R = Increase range";
    //mvwprintw(menuwin, iy+9, ix, " R = Increase range");

    //char* comln9 = " 0 = Change room";
    //mvwprintw(menuwin, iy+10, ix, " 0 = Change room");

    //char* comln10 = " Q = Open door";
    //mvwprintw(menuwin, iy+11, ix, " Q = Open door");

    char* choices[1] = {"Back"};
    int choice;
    int highlight = 0;

    

    while(1) {
       for(int i = 0; i < 1; i++) {
            if(i == highlight) 
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, choices[i]);
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch(choice) {
            case KEY_UP:
                highlight--;
                if(highlight < 0)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight > 1)
                    highlight = 1;
                break;
            default:
                break;
        }
        if(choice == 10)
            break;        
    }



    if (highlight==0){
        menu();
    }


}


