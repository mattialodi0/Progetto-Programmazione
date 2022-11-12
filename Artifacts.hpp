
#pragma once

#include "Board.hpp"

class Artifacts : public Drawable
{
protected:
    
public:
    Artifacts(){
        Drawable(x,y,RandomArtifact());
    }
    chtype RandomArtifact(){
        srand(time(NULL));
        int i = (rand() % (3));
        if(i==1)
        {
            return 'S';
        }
        else if(i==2)
        {
            return 'F';
        }
        else
        {
            return 'H';
        }
    }
};