#include "Boom.hpp"

Boom::Boom():Enemy(def,17,17,'B',0)
{
    setRange(3);
}

Boom::Boom(int y, int x,int diff):Enemy(def,y,x,'B',diff)
{
    setRange(3);
}

void Boom::createProjectile(Board &board_win, Hero &hero,Direction dir)
{
        setIcon(' ');
        board_win.addAt(gety(),getx(),' ');
 for(int j=0;j<boom_range*2;j++){
        for(int i=0;i<boom_range*5;i++){
            if(board_win.getCharAt(gety()+j-(boom_range), getx()+i-((boom_range*2.5))+1)==' '|| board_win.getCharAt(gety()+j-(boom_range), getx()+i-((boom_range*2.5))+1)==hero.getIcon()){
               
                Projectile *new_proj = new Projectile(dir,getx()+i-((boom_range*2.5))+1,gety()+j-(boom_range), 'o');
                projectile.push_back(new_proj); 
        }
    }
    }
    
}

void Boom::checkProjectile(Board &board_win, Hero &hero)
{
    bool existed=false;
    for (int i = 0; i < projectile.size(); i++)
	{
		if (projectile[i] != NULL){
            existed=true;
            projectile[i]->setUptime((projectile[i]->getUptime())+1); 
            if( projectile[i]->getUptime()>getRange()||(board_win.getCharAt(projectile[i]->gety(),projectile[i]->getx())!=projectile[i]->getIcon()&&board_win.getCharAt(projectile[i]->gety(),projectile[i]->getx())!=' ')){
                if(projectile[i]->getx()==hero.getx() && projectile[i]->gety()==hero.gety()){
                    hero.reduceHealthHero(getDmg());
                }  
                board_win.addAt(projectile[i]->gety(),projectile[i]->getx(),' ');
                projectile.erase(projectile.begin()+i);
            }
        
        }
    }
    if(projectile.size()==0&&existed){
            setHp(0);
        }
}

void Boom::chooseDirection(Board &board_win, Hero &hero)
{
    if(!timeractivated&& !die){
    if(getReload()<=0){
        int distancex, distancey;
        distancex = getx() - hero.getx();
        distancey = gety() - hero.gety();
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
            dimReload();
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