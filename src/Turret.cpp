#include "Turret.hpp"

Turret::Turret() : Enemy(def, 25, 25, 'T', 0)
{
}
Turret::Turret(int y, int x, int diff) : Enemy(def, y, x, 'T', diff)
{
}
// per creare proiettili
void Turret::createProjectile(Board &board_win, Hero &hero, Direction dir)
{
    if (getReload() + 5 <= 0)
    {
        setReload(getMaxReload());
        for (int i = 0; i < 4; i++)
        {
            switch (i)
            {
            case 0:
                dir = up;
                break;
            case 1:
                dir = down;
                break;
            case 2:
                dir = dx;
                break;
            case 3:
                dir = sx;
                break;
            }
            Projectile *new_proj = new Projectile(dir, getx(), gety(), 'o');
            projectile.push_back(new_proj);
            switch (dir)
            {
            case up:
                new_proj->setIcon('|');
                break;
            case down:
                new_proj->setIcon('|');
                break;
            case dx:
                new_proj->setIcon('-');
                break;
            case sx:
                new_proj->setIcon('-');
                break;
            }
        }
    }
    else
    {
        dimReload();
    }
}
// per movimento proiettili e check di colpito o out of range
void Turret::checkProjectile(Board &board_win, Hero &hero)
{
    for (int i = 0; i < projectile.size(); i++)
    {
        if (projectile[i] != NULL)
        {
            projectile[i]->setUptime(projectile[i]->getUptime() + 1);
            if (!projectile[i]->checkProjectileCollision(board_win) || projectile[i]->getUptime() > getRange())
            {
                projectile[i]->moveCharacter(board_win);
                if (projectile[i]->getx() == hero.getx() && projectile[i]->gety() == hero.gety())
                {
                    hero.reduceHealthHero(getDmg());
                    projectile.erase(projectile.begin() + i);
                }
                else
                {
                    board_win.addAt(projectile[i]->gety(), projectile[i]->getx(), ' ');
                    projectile.erase(projectile.begin() + i);
                }
            }
            else
            {

                if (projectile[i]->getx() == hero.getx() && projectile[i]->gety() == hero.gety())
                {
                    hero.reduceHealthHero(getDmg());
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
}

// va a una tua stessa linea o colonna per spararti e spara
void Turret::chooseDirection(Board &board_win, Hero &hero)
{
    createProjectile(board_win, hero, def);
    setDirection(def);
}
