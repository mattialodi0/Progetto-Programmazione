#include <iostream>
#include <ncurses.h>
#include <string>
#include "menu_playing.hpp"
//#include "Game.hpp"
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
    
    string choices[3] = {"Resume", "Commands", "exit"};
    int choice;
    int highlight = 0;

    while(1) {
       for(int i = 0; i < 3; i++) {
            if(i == highlight) 
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, choices[i].c_str());
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
    }
    if (highlight==2){
        return true;
    
    }

}

void Menu_playing::refreshStat(Hero &hero,int score){
    //dmg=hero->dmg;
    //range=hero->range;
    //hp=hero->hp;
    //score=score;
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

    string comln = " Keybindings :";
    mvwprintw(menuwin, iy, ix, comln.c_str());

    string comln1 = " W-A-S-D = Movement ";
    mvwprintw(menuwin, iy+2, ix, comln1.c_str());

    string comln2 = " Arrow keys = Attack in choosen direction ";
    mvwprintw(menuwin, iy+3, ix, comln2.c_str());

    string comln3 = " F = Use special ability ";
    mvwprintw(menuwin, iy+4, ix, comln3.c_str());

    string comln4 = " O = Quit the game";
    mvwprintw(menuwin, iy+5, ix, comln4.c_str());

    string comln5 = " P = Pause the game ";
    mvwprintw(menuwin, iy+6, ix, comln5.c_str());

    string comln6 = " E = Increase damage";
    mvwprintw(menuwin, iy+7, ix, comln6.c_str());

    string comln7 = " H = Increase healt";
    mvwprintw(menuwin, iy+8, ix, comln7.c_str());

    string comln8 = " R = Increase range";
    mvwprintw(menuwin, iy+9, ix, comln8.c_str());

    string comln9 = " 0 = Change room";
    mvwprintw(menuwin, iy+10, ix, comln9.c_str());

    string comln10 = " Q = Open door";
    mvwprintw(menuwin, iy+11, ix, comln10.c_str());

    string choices[1] = {"Back"};
    int choice;
    int highlight = 0;

    

    while(1) {
       for(int i = 0; i < 1; i++) {
            if(i == highlight) 
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, choices[i].c_str());
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

