#include "Coward.hpp"

Coward::Coward() : Enemy(def, 11, 11, 'K', 0)
{
    setMaxReload(5);
    setRange(3);
}
Coward::Coward(int y, int x, int diff) : Enemy(def, y, x, 'K', diff)
{
    setMaxReload(5);
    setRange(3);
}

void Coward::createProjectile(Board &board_win, Hero &hero, Direction dir)
{
    if (dir != def)
    {
        Projectile *new_proj = new Projectile(dir, getx(), gety(), 'o');
        projectile.push_back(new_proj);
        switch (dir)
        {
        case down:
            new_proj->sety(new_proj->gety() - 1);
            break;
        case up:
            new_proj->sety(new_proj->gety() + 1);
            break;
        case sx:
            new_proj->setx(new_proj->getx() + 1);
            break;
        case dx:
            new_proj->setx(new_proj->getx() - 1);
            break;
        }
    }
    else
    {
        int k = 0;
        for (int i = 0; i < projectile.size(); i++)
        {
            if (projectile[i]->getDirection() != def)
            {
                k = i;
            }
        }
        for (int j = 0; j < boom_range * 2; j++)
        {
            for (int i = 0; i < boom_range * 5; i++)
            {
                if (board_win.getCharAt(projectile[k]->gety() + j - (boom_range), projectile[k]->getx() + i - ((boom_range * 2.5)) + 1) == ' ' || board_win.getCharAt(projectile[k]->gety() + j - (boom_range), projectile[k]->getx() + i - ((boom_range * 2.5)) + 1) == hero.getIcon())
                {

                    Projectile *new_proj = new Projectile(def, projectile[k]->getx() + i - ((boom_range * 2.5)) + 1, projectile[k]->gety() + j - (boom_range), 'o');
                    projectile.push_back(new_proj);
                }
            }
        }
    }
}

void Coward::checkProjectile(Board &board_win, Hero &hero)
{
    for (int i = 0; i < projectile.size(); i++)
    {
        if (projectile[i] != NULL)
        {
            projectile[i]->setUptime((projectile[i]->getUptime()) + 1);
            if (projectile[i]->getUptime() > getRange() || (board_win.getCharAt(projectile[i]->gety(), projectile[i]->getx()) != projectile[i]->getIcon() && board_win.getCharAt(projectile[i]->gety(), projectile[i]->getx()) != ' '))
            {

                if (projectile[i]->getx() == hero.getx() && projectile[i]->gety() == hero.gety())
                {
                    hero.reduceHealthHero(getDmg());
                }
                board_win.addAt(projectile[i]->gety(), projectile[i]->getx(), ' ');
                if (projectile[i]->getUptime() > getRange() && projectile[i]->getDirection() != def)
                {
                    createProjectile(board_win, hero, def);
                }
                projectile.erase(projectile.begin() + i);
            }
        }
    }
}
void Coward::chooseDirection(Board &board_win, Hero &hero)
{
    int i = 0;
    int distancex, distancey;
    distancex = getx() - hero.getx();
    distancey = gety() - hero.gety();
    if (hasLos(board_win, hero) && inSight(distancex, distancey))
    {
        this->mem = enemy_memory;
    }
    if (this->mem > 0)
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
        if (this->ammo > 0 && getReload() <= 0)
        {
            setReload(getMaxReload());
            this->ammo--;
            createProjectile(board_win, hero, getDirection());
        }
    }
    this->mem--;
    dimReload();
}