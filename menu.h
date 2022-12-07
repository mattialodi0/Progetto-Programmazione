#include <ncurses.h>
#include <string>
using namespace std;

void m_character_class() 
{
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
    
    string choices[3] = {"Tank", "Warrior", "Assassin"};
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
        //selezione classe tank
    }

    if (highlight==1){
        //selezione classe warrior
    }

    if (highlight==2){
        //selezione classe assassin
    }
    

    getch();
    endwin();
}


void m_settings() 
{
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
        // menu();
    }
    

    getch();
    endwin();
}


void m_play() 
{
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
    
    string choices[3] = {"start game", "choose class", "back"};
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

    getch();
    endwin();
}


void menu() 
{
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
    
    string choices[3] = {"play", "settings", "exit"};
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
        m_play();
    }
    if (highlight==1){
        m_settings();
    }
    if (highlight==2){
        endwin();
    }

    getch();
    endwin();
}
