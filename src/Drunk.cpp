#include "Drunk.hpp"

Drunk::Drunk() : Enemy(def, 13, 13, 'D', 0)
{
    setRange(3);
}
Drunk::Drunk(int y, int x, int diff) : Enemy(def, y, x, 'D', diff)
{
    setRange(3);
}

void Drunk::createProjectile(Board &board_win, Hero &hero, Direction dir)
{

    if (getReload() <= 0)
    {
        setReload(getMaxReload());
        Projectile *new_proj = new Projectile(dir, getx(), gety(), 'o');
        projectile.push_back(new_proj);
        switch (dir)
        {
        case up:
            new_proj->sety(new_proj->gety() - 1);
            break;
        case down:
            new_proj->sety(new_proj->gety() + 1);
            break;
        case dx:
            new_proj->setx(new_proj->getx() + 1);
            break;
        case sx:
            new_proj->setx(new_proj->getx() - 1);
            break;
        }
    }
    else
    {
        dimReload();
    }
}

void Drunk::checkProjectile(Board &board_win, Hero &hero)
{
    for (int i = 0; i < projectile.size(); i++)
    {
        if (projectile[i] != NULL)
        {
            projectile[i]->setUptime((projectile[i]->getUptime()) + 1);

            if (!projectile[i]->checkProjectileCollision(board_win) || projectile[i]->getUptime() > getRange() || (board_win.getCharAt(projectile[i]->gety(), projectile[i]->getx()) != ' ' && board_win.getCharAt(projectile[i]->gety(), projectile[i]->getx()) != projectile[i]->getIcon()))
            {
                projectile[i]->moveCharacter(board_win);
                if (projectile[i]->getx() == hero.getx() && projectile[i]->gety() == hero.gety())
                {
                    hero.reduceHealthHero(getDmg());
                }
                board_win.addAt(projectile[i]->gety(), projectile[i]->getx(), ' ');
                projectile.erase(projectile.begin() + i);
            }
            else
            {
                projectile[i]->moveCharacter(board_win);
            }
        }
    }
}

void Drunk::chooseDirection(Board &board_win, Hero &hero)
{
    int i = 0;
    do
    {
        Direction dir = getRandomDirection();
        setDirection(dir);
        if (i > 10)
        {
            setDirection(def);
        }
        i++;
    } while (!checkCollision(board_win) && i < 12);
}