#include "menu_playing.hpp"


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
    keypad(menuwin, true);      //rende usabili gli arrow keys
    

    char* choices[3] = {"Resume", "Commands", "exit"};
    int choice;
    int highlight = 0;

     //ciclo che stampa le diverse opzioni selezionabili nella finestra
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

    // specifica cosa fare per ogni opzione della finestra
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


    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);


    WINDOW * menuwin = newwin(25, 67+(67/2), (yMax-24)/2, (xMax-100)/2);
    box(menuwin, 0 ,0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);      
    
    int iy = (yMax/2)-18;
    int ix = (xMax/2)-70;

    mvwprintw(menuwin, iy, ix, " Keybindings :");

    mvwprintw(menuwin, iy+2, ix, " W-A-S-D = Movement ");

    mvwprintw(menuwin, iy+3, ix, " Arrow keys = Attack in choosen direction ");

    mvwprintw(menuwin, iy+4, ix, " F = Use special ability ");

    mvwprintw(menuwin, iy+5, ix, " P = Pause the game ");


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
                if(highlight > 0)
                    highlight = 0;
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


