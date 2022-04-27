// nemico che scappa
// probabilmente da implementare loot come artifatti e chiavi
#pragma once
#include "characters.hpp"
class Coward : public Characters
{
public:
    Coward()
    {
        Characters();
        this->icon = 'W';
        this->x = 10;
        this->y = 10;
    }
    // override di characters
    void ChooseDirection(Board board_win, Characters &hero) override
    {
        int i = 0;
        int distancex, distancey;
        distancex = this->x - hero.x;
        distancey = this->y - hero.y;
        // se sei vicino
        if (abs(distancex) < 10 || abs(distancey) < 10)
        {
            Direction horz = (distancex < 0) ? sx : dx;
            Direction ver = (distancey < 0) ? up : down;
            bool pref = abs(distancex) < abs(distancey);
            setDirection((pref) ? horz : ver);
            if (!checkCollision(board_win))
            {
                setDirection((pref) ? ver : horz);
                if (!checkCollision(board_win))
                {
                    if (distancex == 0)
                    {
                        setDirection(sx);
                    }
                    if (distancey == 0)
                    {
                        setDirection(up);
                    }
                }
            }
        }
    }
};