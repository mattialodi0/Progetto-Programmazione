// nemico che ti segue

#include "Enemy.hpp"


class Chaser : public Enemy
{
public:
    Chaser()
    {
        Enemy();
        this->icon = 'C';
        this->x = 12;
        this->y = 7;
    }
    //sprite diverso ma uguale
        void createProjectile(Direction dir)override {
           if(this->Reload<=0){
            this->Reload=EnemyReload;
        Projectile *new_proj = new Projectile();
        new_proj->cur_direction=dir;
            new_proj->x=this->x;
            new_proj->y=this->y;
        new_proj->icon='O';
        projectile.push_back(new_proj); 
    }
    else{
        this->Reload--;
    }
        }
        //uguale a shooter ma meno range
     void checkProjectile(Board board_win, Characters hero){
        for (int i = 0; i < projectile.size(); i++)
		{
			if (projectile[i] != NULL){
                projectile[i]->uptime++;
            board_win.remove(*projectile[i]);
        if(!projectile[i]->checkCollision(board_win)|| projectile[i]->uptime>MeleeRange){
        projectile[i]->moveCharacter();
        if(projectile[i]->x=hero.x && projectile[i]->y==hero.y){
            //diminuisci vita player
        } 
        projectile.erase(projectile.begin()+i);
        }
        else{
          projectile[i]->moveCharacter();
          if(board_win.getCharAt(projectile[i]->y,projectile[i]->x)){
          board_win.add(*projectile[i]);
          }
        }
        
    }
        }
     }
    //ti viene vicino e spara un piccolo proiettile e viene stunnato
    void ChooseDirection(Board board_win, Characters &hero) override
    {
        if(this->Reload<=0){
        int distancex, distancey;
        distancex = this->x - hero.x;
        distancey = this->y - hero.y;
        //se sei vicino
         if(hasLos(board_win, hero, this->y, this->x) && abs(distancex) < 10 && abs(distancey) < 10){
            this->mem=EnemyMemory;
            }
        if (this->mem>0)
        {
            if(abs(distancex) < MeleeRange && abs(distancey) < MeleeRange){
                 if(distancey==0){
            if(distancex>0){
                createProjectile(sx);
            }
            else{
                createProjectile(dx);
            }
            this->Reload=MeleeEnemyReload;
        }
        else{
            if(distancex==0){
                if(distancey>0){
                    createProjectile(up);
                }
                else{
                    createProjectile(down);
                }
                this->Reload=MeleeEnemyReload;
            }
            }
            }
            if (abs(distancex) > abs(distancey))
            {
                if (distancex < 0)
                {
                    setDirection(dx);
                }
                else
                {
                    setDirection(sx);
                }
            }
            else
            {
                if (abs(distancex) <= abs(distancey))
                {
                    if (distancey < 0)
                    {
                        setDirection(down);
                    }
                    else
                    {
                        setDirection(up);
                    }
                }
            }
        }
        }
        this->mem--;
        this->Reload--;   
    }
    //solito los
    bool hasLos(Board board_win, Characters hero, int y, int x) override
    {
            int i=0,k=0;
              int distancex, distancey;
        distancex = x - hero.x;
        distancey = y - hero.y;
            if (abs(distancex) > abs(distancey))
            {
                if (distancex < 0)
                {
                    k++;
                }
                else
                {
                    k--;
                }
            }
            else
            {
                if (abs(distancex) <= abs(distancey))
                {
                    if (distancey < 0)
                    {
                        i++;
                    }
                    else
                    {
                        i--;
                    }
                }
            }
        chtype f =board_win.getCharAt(y+i,x+k);
            if(f==hero.icon){
                return true;
            }
            else{
                if(f!=' '){
                    return false;
                }
                else{
                    return hasLos(board_win, hero, y+i,x+k);
                }
            }
    }
};