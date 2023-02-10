#include <ncurses.h>
#include <iostream>
using namespace std;

class Menu{
    protected:
        int hero_class;
        int diff=3;
        int diff_rate=40;
        bool game=true;

        void character_class();
        void class_tank();
        void class_rogue();
        void class_ranger();
        void class_mage();
        void commands();
        void difficulty();

        void setDiff(int diff);
        void setDiff_rate(int diff_rate);
        void setHero_class(int hero_class);
        void setGameOver();
        bool checkTerminal();

    public:
        void menu();
        void play();
        int getDiff();
        int getDiff_rate();
        int getHero_class();
        bool getGame();

};




