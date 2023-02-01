#include "Boom.hpp"

Boom::Boom():Enemy(def,17,17,'B',0)
{
}

Boom::Boom(int y, int x,int diff):Enemy(def,y,x,'B',diff)
{
}

void Boom::createProjectile(Board &board_win, Hero &hero,Direction dir)
{
        this->setIcon(' ');
        board_win.addAt(this->y,this->x,' ');
 for(int j=0;j<boom_range*2;j++){
        for(int i=0;i<boom_range*5;i++){
            if(board_win.getCharAt(this->gety()+j-(boom_range), this->getx()+i-((boom_range*2.5))+1)==' '|| board_win.getCharAt(this->gety()+j-(boom_range)+1, this->getx()+i-((boom_range*2.5))+1)==hero.getIcon()){
               
                Projectile *new_proj = new Projectile(dir,this->getx()+i-((boom_range*2.5))+1,this->gety()+j-(boom_range), 'o');
                projectile.push_back(new_proj); 
        }
    }
    }
    
}

void Boom::checkProjectile(Board &board_win, Hero &hero)
{
    for (int i = 0; i < projectile.size(); i++)
	{
		if (projectile[i] != NULL){
            projectile[i]->setUptime((projectile[i]->getUptime())+1);            
            if( projectile[i]->getUptime()>melee_range||(board_win.getCharAt(projectile[i]->gety(),projectile[i]->getx())!=projectile[i]->getIcon()&&board_win.getCharAt(projectile[i]->gety(),projectile[i]->getx())!=' ')){
                
                if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
                    hero.reduceHealth();
                }    
                board_win.setTaken(projectile[i]->getx(),projectile[i]->gety(),false);
                board_win.addAt(this->y,this->x,' ');
                projectile.erase(projectile.begin()+i);
            }
        }
    }
}

void Boom::chooseDirection(Board &board_win, Hero &hero)
{
    if(!timeractivated&& !die){
    if(this->reload<=0){
        int distancex, distancey;
        distancex = this->x - hero.getx();
        distancey = this->y - hero.gety();
        //se sei vicino
        if(hasLos(board_win, hero) &&  inSight(distancex,distancey))
        {
            this->mem=enemy_memory;
        }
        if (this->mem>0)
        {
           
            if (abs(distancex) > abs(distancey))
            {
                if (distancex < 0)
                {
                    setDirection(dx);
                }
                else
                {
                    if(distancex>0){
                    setDirection(sx);
                    }
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
                        if(distancey>0){
                        setDirection(up);
                        }
                    }
                }
            }
             if(abs(distancex) <= boom_range/2 && abs(distancey) <= boom_range/2){
                
                timeractivated=true;
                setDirection(def);
            }
        }
    }
     else{
            this->reload--;
            setDirection(def);
            }
    this->mem--; 
    }
    else{
        if(!die){
        if(timer<=0){
         createProjectile(board_win,hero, def);
         die=true;
        }else{
        timer--;
    }
        }
        else{
            if(dying_timer<=0){
                //rimuovilo
            }
            else{
                dying_timer--;
            }
            
        }
    
    }
}