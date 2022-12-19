#include <iostream>
#include <ncurses.h>
#include "menu.cpp"
#include "menu_playing.cpp"
using namespace std;


int main(){
    
    Menu menu;
    Menu_playing menu_p;
    
    menu.menu();
    // menu_p.menu();
    return 0;
}