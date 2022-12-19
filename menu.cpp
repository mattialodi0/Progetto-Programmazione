#include <iostream>
#include <ncurses.h>
#include <string>
#include "menu.hpp"
using namespace std;

void Menu::settings(){
    initscr();
    cbreak();
    noecho();

    //prende le dimensioni della finestra
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    //crea una finestra per l'input
    WINDOW * menuwin = newwin(yMax-6, xMax-8, 3, 4);
    box(menuwin, 0 ,0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);      //makes arrows keys usable
    
    string choices[3] = {"Audio", "Music", "Back"};
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
    
    // Sezione che attua l'azione da compiere quando viene premuto invio
    if (highlight==0){
        // audio_on 
    }

    if (highlight==1){
        // music_playing
    }

    if (highlight==2){
        endwin();
        menu();
    }
    

    getch();
    endwin();
}

void Menu::menu(){

    initscr();
    cbreak();
    noecho();

    //prende le dimensioni della finestra
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    //crea una finestra per l'input
    WINDOW * menuwin = newwin(yMax-6, xMax-8, 3, 4);
    box(menuwin, 0 ,0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);      //makes arrows keys usable
    
    string choices[3] = {"Play", "Settings", "exit"};
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
        endwin();
        play();
    }
    if (highlight==1){
        endwin();
        settings();
    }
    if (highlight==2){
        endwin();
    }

    getch();
    endwin();
}



void Menu::play(){
    initscr();
    cbreak();
    noecho();

    //prende le dimensioni della finestra
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    //crea una finestra per l'input
    WINDOW * menuwin = newwin(yMax-6, xMax-8, 3, 4);
    box(menuwin, 0 ,0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);      //makes arrows keys usable
    
    string choices[3] = {"Start game", "Choose class", "Back"};
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
        endwin();
        // start_game();
    }
    if (highlight==1){
        endwin();
        // choose_class();
    }
    if (highlight==2){
        endwin();
        menu();
    }

    getch();
    endwin();
}



void Menu::character_class(){

    // select class

}

