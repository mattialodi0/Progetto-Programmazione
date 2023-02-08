#include <ncurses.h>
#include <string>
#include "Hero.hpp"
using namespace std;

class Menu_playing{

    public:
        bool menu();
        void commands();
        void refreshStat(Hero &hero,int score);
};