#include "menu.hpp"

void Menu::menu()
{

    initscr();
    cbreak();
    noecho();

    // prende le dimensioni della finestra
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // crea una finestra per l'input
    WINDOW *menuwin = newwin(25, 67 + (67 / 2), (yMax - 24) / 2, (xMax - 100) / 2);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true); // rende usabili gli arrow keys

    char *choices[3] = {"Play", "Commands", "Exit"};
    int choice;
    int highlight = 0;

    // ciclo che stampa le diverse opzioni selezionabili nella finestra
    while (1)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, choices[i]);
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlight--;
            if (highlight < 0)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight > 2)
                highlight = 2;
            break;
        default:
            break;
        }
        if (choice == 10)
            break;
    }

    // specifica cosa fare per ogni opzione della finestra
    if (highlight == 0)
    {
        play();
    }
    if (highlight == 1)
    {
        commands();
    }
    if (highlight == 2)
    {
        setGameOver();
        endwin();
    }
}

void Menu::play()
{

    initscr();
    cbreak();
    noecho();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *menuwin = newwin(25, 67 + (67 / 2), (yMax - 24) / 2, (xMax - 100) / 2);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);

    char *choices[3] = {"Choose class", "Difficulty", "-Back-"};
    int choice;
    int highlight = 0;

    while (1)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, choices[i]);
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlight--;
            if (highlight < 0)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight > 2)
                highlight = 2;
            break;
        default:
            break;
        }
        if (choice == 10)
            break;
    }

    if (highlight == 0)
    {
        character_class();
    }
    if (highlight == 1)
    {
        difficulty();
    }
    if (highlight == 2)
    {
        menu();
    }
}

void Menu::difficulty()
{

    initscr();
    cbreak();
    noecho();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *menuwin = newwin(25, 67 + (67 / 2), (yMax - 24) / 2, (xMax - 100) / 2);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);

    char *choices[4] = {"Set difficulty easy", "Set difficulty medium", "Set difficulty hard", "-Back-"};
    int choice;
    int highlight = 0;

    while (1)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, choices[i]);
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlight--;
            if (highlight < 0)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight > 3)
                highlight = 3;
            break;
        default:
            break;
        }
        if (choice == 10)
            break;
    }

    if (highlight == 0)
    {
        setDiff(1);
        setDiff_rate(60);
        menu();
    }
    if (highlight == 1)
    {
        setDiff(3);
        setDiff_rate(40);
        menu();
    }
    if (highlight == 2)
    {
        setDiff(5);
        setDiff_rate(20);
        menu();
    }
    if (highlight == 3)
    {
        play();
    }
}

void Menu::commands()
{

    initscr();
    cbreak();
    noecho();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *menuwin = newwin(25, 67 + (67 / 2), (yMax - 24) / 2, (xMax - 100) / 2);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);

    int iy = 10;
    int ix = 35;

    mvwprintw(menuwin, iy, ix, "Keybindings :");

    mvwprintw(menuwin, iy + 2, ix, " W-A-S-D = Movement ");

    mvwprintw(menuwin, iy + 3, ix, " Arrow keys = Attack in choosen direction ");

    mvwprintw(menuwin, iy + 4, ix, " F = Use special ability ");

    mvwprintw(menuwin, iy + 5, ix, " P = Pause the game ");

    char *choices[1] = {"Back"};
    int choice;
    int highlight = 0;

    while (1)
    {
        for (int i = 0; i < 1; i++)
        {
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, choices[i]);
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlight--;
            if (highlight < 0)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight > 0)
                highlight = 0;
            break;
        default:
            break;
        }
        if (choice == 10)
            break;
    }

    if (highlight == 0)
    {
        menu();
    }
}

void Menu::character_class()
{

    initscr();
    cbreak();
    noecho();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *menuwin = newwin(25, 67 + (67 / 2), (yMax - 24) / 2, (xMax - 100) / 2);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);

    char *choices[5] = {"Tank", "Rogue", "Ranger", "Mage", "-Back-"};
    int choice;
    int highlight = 0;

    while (1)
    {
        for (int i = 0; i < 5; i++)
        {
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, choices[i]);
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlight--;
            if (highlight < 0)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight > 4)
                highlight = 4;
            break;
        default:
            break;
        }
        if (choice == 10)
            break;
    }

    if (highlight == 0)
    {
        class_tank();
    }
    if (highlight == 1)
    {
        class_rogue();
    }
    if (highlight == 2)
    {
        class_ranger();
    }
    if (highlight == 3)
    {
        class_mage();
    }
    if (highlight == 4)
    {
        play();
    }
}

void Menu::class_tank()
{

    initscr();
    cbreak();
    noecho();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *menuwin = newwin(25, 67 + (67 / 2), (yMax - 24) / 2, (xMax - 100) / 2);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);

    int iy = 10;
    int ix = 40;

    mvwprintw(menuwin, iy, ix, " TANK class stats : ");

    mvwprintw(menuwin, iy + 2, ix + 1, " Healt Points = 40 ");

    mvwprintw(menuwin, iy + 3, ix + 1, " Damage = 5 ");

    mvwprintw(menuwin, iy + 4, ix + 1, " Reload Time = 3 ");

    mvwprintw(menuwin, iy + 5, ix + 1, " Range = 4 ");

    char *choices[2] = {"Start Game", "-Back-"};
    int choice;
    int highlight = 0;

    while (1)
    {
        for (int i = 0; i < 2; i++)
        {
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, choices[i]);
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlight--;
            if (highlight < 0)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight > 1)
                highlight = 1;
            break;
        default:
            break;
        }
        if (choice == 10)
            break;
    }

    if (highlight == 0)
    {
        setHero_class(1);
    }
    if (highlight == 1)
    {
        character_class();
    }
}

void Menu::class_rogue()
{

    initscr();
    cbreak();
    noecho();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *menuwin = newwin(25, 67 + (67 / 2), (yMax - 24) / 2, (xMax - 100) / 2);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);

    int iy = 10;
    int ix = 40;

    mvwprintw(menuwin, iy, ix, " ROGUE class stats : ");

    mvwprintw(menuwin, iy + 2, ix + 1, " Healt Points = 20 ");

    mvwprintw(menuwin, iy + 3, ix + 1, " Damage = 7 ");

    mvwprintw(menuwin, iy + 4, ix + 1, " Reload Time = 2 ");

    mvwprintw(menuwin, iy + 5, ix + 1, " Range = 5 ");

    char *choices[2] = {"Start Game", "-Back-"};
    int choice;
    int highlight = 0;

    while (1)
    {
        for (int i = 0; i < 2; i++)
        {
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, choices[i]);
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlight--;
            if (highlight < 0)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight > 1)
                highlight = 1;
            break;
        default:
            break;
        }
        if (choice == 10)
            break;
    }

    if (highlight == 0)
    {
        setHero_class(2);
    }
    if (highlight == 1)
    {
        character_class();
    }
}

void Menu::class_ranger()
{

    initscr();
    cbreak();
    noecho();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *menuwin = newwin(25, 67 + (67 / 2), (yMax - 24) / 2, (xMax - 100) / 2);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);

    int iy = 10;
    int ix = 40;

    mvwprintw(menuwin, iy, ix, " RANGER class stats : ");

    mvwprintw(menuwin, iy + 2, ix + 1, " Healt Points = 16 ");

    mvwprintw(menuwin, iy + 3, ix + 1, " Damage = 3 ");

    mvwprintw(menuwin, iy + 4, ix + 1, " Reload Time = 2 ");

    mvwprintw(menuwin, iy + 5, ix + 1, " Range = 14 ");

    char *choices[2] = {"Start Game", "-Back-"};
    int choice;
    int highlight = 0;

    while (1)
    {
        for (int i = 0; i < 2; i++)
        {
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, choices[i]);
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlight--;
            if (highlight < 0)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight > 1)
                highlight = 1;
            break;
        default:
            break;
        }
        if (choice == 10)
            break;
    }

    if (highlight == 0)
    {
        setHero_class(3);
    }
    if (highlight == 1)
    {
        character_class();
    }
}

void Menu::class_mage()
{

    initscr();
    cbreak();
    noecho();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *menuwin = newwin(25, 67 + (67 / 2), (yMax - 24) / 2, (xMax - 100) / 2);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);

    int iy = 10;
    int ix = 40;

    mvwprintw(menuwin, iy, ix, " MAGE class stats : ");

    mvwprintw(menuwin, iy + 2, ix + 1, " Healt Points = 16 ");

    mvwprintw(menuwin, iy + 3, ix + 1, " Damage = 6 ");

    mvwprintw(menuwin, iy + 4, ix + 1, " Reload Time = 4 ");

    mvwprintw(menuwin, iy + 5, ix + 1, " Range = 7 ");

    char *choices[2] = {"Start Game", "-Back-"};
    int choice;
    int highlight = 0;

    while (1)
    {
        for (int i = 0; i < 2; i++)
        {
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, choices[i]);
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlight--;
            if (highlight < 0)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight > 1)
                highlight = 1;
            break;
        default:
            break;
        }
        if (choice == 10)
            break;
    }

    if (highlight == 0)
    {
        setHero_class(4);
    }
    if (highlight == 1)
    {
        character_class();
    }
}

void Menu::setDiff(int diff)
{
    this->diff = diff;
}

int Menu::getDiff()
{
    return this->diff;
}

void Menu::setDiff_rate(int diff_rate)
{
    this->diff_rate = diff_rate;
}

int Menu::getDiff_rate()
{
    return this->diff_rate;
}

void Menu::setHero_class(int hero_class)
{
    this->hero_class = hero_class;
}

int Menu::getHero_class()
{
    return this->hero_class;
}

void Menu::setGameOver()
{
    this->game = false;
}

bool Menu::getGame()
{
    return this->game;
}