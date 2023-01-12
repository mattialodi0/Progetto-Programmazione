#include <iostream>
#include <ncurses.h>
#include <string>
#include "menu.hpp"
using namespace std;



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
    
    string choices[3] = {"Start game", "Choose class", "-Back-"};
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
        character_class();
    }
    if (highlight==2){
        endwin();
        menu();
    }

    getch();
    endwin();
}

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
    
    string choices[3] = {"Audio", "Music", "-Back-"};
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


void Menu::character_class(){

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
    
    string choices[5] = {"Tank", "Rogue", "Ranger", "Mage", "-Back-"};
    int choice;
    int highlight = 0;

    while(1) {
       for(int i = 0; i < 5; i++) {
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
                if(highlight > 4)
                    highlight = 4;
                break;
            default:
                break;
        }
        if(choice == 10)
            break;        
    }

    if (highlight==0){
        endwin();
        class_tank();
    }
    if (highlight==1){
        endwin();
        class_rogue();
    }
    if (highlight==2){
        endwin();
        class_ranger();
    }
    if (highlight==3){
        endwin();
        class_mage();
    }
    if (highlight==4){
        endwin();
        play();
    }
    getch();
    endwin();

}

void Menu::class_tank(){

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
    
    int iy = (yMax/2)-10;
    int ix = (xMax/2)-20;
    string stats_name = " TANK class stats : ";
    mvwprintw(menuwin, iy, ix, stats_name.c_str());

    string stats_hp = " Healt Points = 30 ";
    mvwprintw(menuwin, iy+2, ix, stats_hp.c_str());

    string stats_ac = " Defense = 3 ";
    mvwprintw(menuwin, iy+3, ix, stats_ac.c_str());

    string stats_dmg = " Damage = 2 ";
    mvwprintw(menuwin, iy+4, ix, stats_dmg.c_str());

    string stats_sp = " Speed = 1 ";
    mvwprintw(menuwin, iy+5, ix, stats_sp.c_str());

    string stats_rl = " Reload Time = 3 ";
    mvwprintw(menuwin, iy+6, ix, stats_rl.c_str());

    string stats_rg = " Range = 2 ";
    mvwprintw(menuwin, iy+7, ix, stats_rg.c_str());

    string choices[2] = {"Start Game", "-Back-"};
    int choice;
    int highlight = 0;

    

    while(1) {
       for(int i = 0; i < 2; i++) {
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
        endwin();
        // start_game with Tank
    }
    if (highlight==1){
        endwin();
        character_class();
    }

    getch();
    endwin();

}

void Menu::class_rogue(){

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
    
    int iy = (yMax/2)-10;
    int ix = (xMax/2)-20;
    string stats_name = " ROGUE class stats : ";
    mvwprintw(menuwin, iy, ix, stats_name.c_str());

    string stats_hp = " Healt Points = 20 ";
    mvwprintw(menuwin, iy+2, ix, stats_hp.c_str());

    string stats_ac = " Defense = 2 ";
    mvwprintw(menuwin, iy+3, ix, stats_ac.c_str());

    string stats_dmg = " Damage = 3 ";
    mvwprintw(menuwin, iy+4, ix, stats_dmg.c_str());

    string stats_sp = " Speed = 4 ";
    mvwprintw(menuwin, iy+5, ix, stats_sp.c_str());

    string stats_rl = " Reload Time = 2 ";
    mvwprintw(menuwin, iy+6, ix, stats_rl.c_str());

    string stats_rg = " Range = 2 ";
    mvwprintw(menuwin, iy+7, ix, stats_rg.c_str());

    string choices[2] = {"Start Game", "-Back-"};
    int choice;
    int highlight = 0;

    

    while(1) {
       for(int i = 0; i < 2; i++) {
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
        endwin();
        // start_game with Rogue
    }
    if (highlight==1){
        endwin();
        character_class();
    }

    getch();
    endwin();

}

void Menu::class_ranger(){

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
    
    int iy = (yMax/2)-10;
    int ix = (xMax/2)-20;
    string stats_name = " RANGER class stats : ";
    mvwprintw(menuwin, iy, ix, stats_name.c_str());

    string stats_hp = " Healt Points = 16 ";
    mvwprintw(menuwin, iy+2, ix, stats_hp.c_str());

    string stats_ac = " Defense = 1 ";
    mvwprintw(menuwin, iy+3, ix, stats_ac.c_str());

    string stats_dmg = " Damage = 1 ";
    mvwprintw(menuwin, iy+4, ix, stats_dmg.c_str());

    string stats_sp = " Speed = 3 ";
    mvwprintw(menuwin, iy+5, ix, stats_sp.c_str());

    string stats_rl = " Reload Time = 1 ";
    mvwprintw(menuwin, iy+6, ix, stats_rl.c_str());

    string stats_rg = " Range = 10 ";
    mvwprintw(menuwin, iy+7, ix, stats_rg.c_str());

    string choices[2] = {"Start Game", "-Back-"};
    int choice;
    int highlight = 0;

    

    while(1) {
       for(int i = 0; i < 2; i++) {
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
        endwin();
        // start_game with Ranger
    }
    if (highlight==1){
        endwin();
        character_class();
    }

    getch();
    endwin();

}

void Menu::class_mage(){

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
    
    int iy = (yMax/2)-10;
    int ix = (xMax/2)-20;
    string stats_name = " MAGE class stats : ";
    mvwprintw(menuwin, iy, ix, stats_name.c_str());

    string stats_hp = " Healt Points = 16 ";
    mvwprintw(menuwin, iy+2, ix, stats_hp.c_str());

    string stats_ac = " Defense = 1 ";
    mvwprintw(menuwin, iy+3, ix, stats_ac.c_str());

    string stats_dmg = " Damage = 3 ";
    mvwprintw(menuwin, iy+4, ix, stats_dmg.c_str());

    string stats_sp = " Speed = 2 ";
    mvwprintw(menuwin, iy+5, ix, stats_sp.c_str());

    string stats_rl = " Reload Time = 4 ";
    mvwprintw(menuwin, iy+6, ix, stats_rl.c_str());

    string stats_rg = " Range = 8 ";
    mvwprintw(menuwin, iy+7, ix, stats_rg.c_str());

    string choices[2] = {"Start Game", "-Back-"};
    int choice;
    int highlight = 0;

    

    while(1) {
       for(int i = 0; i < 2; i++) {
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
        endwin();
        // start_game with Mage
    }
    if (highlight==1){
        endwin();
        character_class();
    }

    getch();
    endwin();

}