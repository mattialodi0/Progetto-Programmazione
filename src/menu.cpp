#include <ncurses.h>
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
    WINDOW * menuwin = newwin(25, 67+(67/2), (yMax-24)/2, (xMax-100)/2);
    box(menuwin, 0 ,0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);      //makes arrows keys usable
    
    char* choices[4] = {"Choose class", "Difficulty", "Commands", "Exit"};
    int choice;
    int highlight = 0;

    while(1) {
       for(int i = 0; i < 4; i++) {
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
                if(highlight > 3)
                    highlight = 3;
                break;
            default:
                break;
        }
        if(choice == 10)
            break;        
    }

    if (highlight==0){
        return character_class();
    }
    if (highlight==1){
        difficulty();
    }
    if (highlight==2){
        commands();
    }
    if (highlight==3){
        endwin();
    }

}

void Menu::difficulty(){

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
    
    char* choices[4] = {"Set Difficulty Easy", "Set Difficulty Medium", "Set Difficulty Hard", "-Back-"};
    int choice;
    int highlight = 0;

    while(1) {
       for(int i = 0; i < 4; i++) {
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
                if(highlight > 3)
                    highlight = 3;
                break;
            default:
                break;
        }
        if(choice == 10)
            break;        
    }

    if (highlight==0){
        setDiff(1);
        setDiff_rate(60);
        menu();
    }
    if (highlight==1){
        setDiff(3);
        setDiff_rate(40);
        menu();
    }
    if (highlight==2){
        setDiff(5);
        setDiff_rate(20);
        menu();
    }
    if (highlight==3){
        menu();
    }

}

/*
void Menu::play(){
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
        // start_game();
    }
    if (highlight==1){
        character_class();
    }
    if (highlight==2){
        menu();
    }

}
*/

void Menu::commands(){

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
    
    int iy = (yMax/2)-18;
    int ix = (xMax/2)-70;

    char* comln = " Keybindings :";
    mvwprintw(menuwin, iy, ix, comln);

    //char* comln1 = " W-A-S-D = Movement ";
    mvwprintw(menuwin, iy+2, ix, " W-A-S-D = Movement ");

    //char* comln2 = " Arrow keys = Attack in choosen direction ";
    mvwprintw(menuwin, iy+3, ix, " Arrow keys = Attack in choosen direction ");

    //char* comln3 = " F = Use special ability ";
    mvwprintw(menuwin, iy+4, ix, " F = Use special ability ");

    //char* comln4 = " O = Quit the game";
    //mvwprintw(menuwin, iy+5, ix, " O = Quit the game ");

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

void Menu::character_class(){

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
    
    char* choices[5] = {"Tank", "Rogue", "Ranger", "Mage", "-Back-"};
    int choice;
    int highlight = 0;

    while(1) {
       for(int i = 0; i < 5; i++) {
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
        return class_tank();
    }
    if (highlight==1){
        return class_rogue();
    }
    if (highlight==2){
        return class_ranger();
    }
    if (highlight==3){
        return class_mage();
    }
    if (highlight==4){
        menu();
    }

}

void Menu::class_tank(){

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
    
    int iy = (yMax/2)-18;
    int ix = (xMax/2)-70;
    //char* stats_name = " TANK class stats : ";
    mvwprintw(menuwin, iy, ix, " TANK class stats : ");

    //char* stats_hp = " Healt Points = 30 ";
    mvwprintw(menuwin, iy+2, ix, " Healt Points = 30 ");

    //char* stats_ac = " Defense = 3 ";
    mvwprintw(menuwin, iy+3, ix, " Defense = 3 ");

    //char* stats_dmg = " Damage = 2 ";
    mvwprintw(menuwin, iy+4, ix, " Damage = 2 ");

    //char* stats_sp = " Speed = 1 ";
    mvwprintw(menuwin, iy+5, ix, " Speed = 1 ");

    //char* stats_rl = " Reload Time = 3 ";
    mvwprintw(menuwin, iy+6, ix, " Reload Time = 3 ");

    //char* stats_rg = " Range = 2 ";
    mvwprintw(menuwin, iy+7, ix, " Range = 2 ");

    char* choices[2] = {"Start Game", "-Back-"};
    int choice;
    int highlight = 0;

    

    while(1) {
       for(int i = 0; i < 2; i++) {
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
        // start_game with Tank
        setHero_class(1);
    }
    if (highlight==1){
        character_class();
    }

}

void Menu::class_rogue(){

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
    
    int iy = (yMax/2)-18;
    int ix = (xMax/2)-70;
    //char* stats_name = " ROGUE class stats : ";
    mvwprintw(menuwin, iy, ix, " ROGUE class stats : ");

    //char* stats_hp = " Healt Points = 20 ";
    mvwprintw(menuwin, iy+2, ix, " Healt Points = 20 ");

    //char* stats_ac = " Defense = 2 ";
    mvwprintw(menuwin, iy+3, ix, " Defense = 2 ");

    //char* stats_dmg = " Damage = 3 ";
    mvwprintw(menuwin, iy+4, ix, " Damage = 3 ");

    //char* stats_sp = " Speed = 4 ";
    mvwprintw(menuwin, iy+5, ix, " Speed = 4 ");

    //char* stats_rl = " Reload Time = 2 ";
    mvwprintw(menuwin, iy+6, ix, " Reload Time = 2 ");

    //char* stats_rg = " Range = 2 ";
    mvwprintw(menuwin, iy+7, ix, " Range = 2 ");

    char* choices[2] = {"Start Game", "-Back-"};
    int choice;
    int highlight = 0;

    

    while(1) {
       for(int i = 0; i < 2; i++) {
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
        // start_game with Rogue
        setHero_class(2);
    }
    if (highlight==1){
        character_class();
    }

}

void Menu::class_ranger(){

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
    
    int iy = (yMax/2)-18;
    int ix = (xMax/2)-70;
    //char* stats_name = " RANGER class stats : ";
    mvwprintw(menuwin, iy, ix, " RANGER class stats : ");

    //char* stats_hp = " Healt Points = 16 ";
    mvwprintw(menuwin, iy+2, ix, " Healt Points = 16 ");

    //char* stats_ac = " Defense = 1 ";
    mvwprintw(menuwin, iy+3, ix, " Defense = 1 ");

    //char* stats_dmg = " Damage = 1 ";
    mvwprintw(menuwin, iy+4, ix, " Damage = 1 ");

    //char* stats_sp = " Speed = 3 ";
    mvwprintw(menuwin, iy+5, ix, " Speed = 3 ");

    //char* stats_rl = " Reload Time = 1 ";
    mvwprintw(menuwin, iy+6, ix, " Reload Time = 1 ");

    //char* stats_rg = " Range = 10 ";
    mvwprintw(menuwin, iy+7, ix, " Range = 10 ");

    char* choices[2] = {"Start Game", "-Back-"};
    int choice;
    int highlight = 0;

    

    while(1) {
       for(int i = 0; i < 2; i++) {
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
        // start_game with Ranger
        setHero_class(3);
    }
    if (highlight==1){
        character_class();
    }

}

void Menu::class_mage(){

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
    
    int iy = (yMax/2)-18;
    int ix = (xMax/2)-70;
    //char* stats_name = " MAGE class stats : ";
    mvwprintw(menuwin, iy, ix, " MAGE class stats : ");

    //char* stats_hp = " Healt Points = 16 ";
    mvwprintw(menuwin, iy+2, ix, " Healt Points = 16 ");

    //char* stats_ac = " Defense = 1 ";
    mvwprintw(menuwin, iy+3, ix, " Defense = 1 ");

    //char* stats_dmg = " Damage = 3 ";
    mvwprintw(menuwin, iy+4, ix, " Damage = 3 ");

    //char* stats_sp = " Speed = 2 ";
    mvwprintw(menuwin, iy+5, ix, " Speed = 2 ");

    //char* stats_rl = " Reload Time = 4 ";
    mvwprintw(menuwin, iy+6, ix, " Reload Time = 4 ");

    //char* stats_rg = " Range = 8 ";
    mvwprintw(menuwin, iy+7, ix, " Range = 7 ");

    char* choices[2] = {"Start Game", "-Back-"};
    int choice;
    int highlight = 0;

    

    while(1) {
       for(int i = 0; i < 2; i++) {
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
        // start_game with Mage
        setHero_class(4);
    }
    if (highlight==1){
        character_class();
    }

}

void Menu::setDiff(int diff){
    this->diff=diff;
}

int Menu::getDiff(){
    return this->diff;
}

void Menu::setDiff_rate(int diff_rate){
    this->diff_rate=diff_rate;
}

int Menu::getDiff_rate(){
    return this->diff_rate;
}

void Menu::setHero_class(int hero_class){
    this->hero_class=hero_class;
}

int Menu::getHero_class(){
    return this->hero_class;
}

void Menu::setGameOver(){
    this->game=false;
}

bool Menu::getGame(){
    return this->game;
}