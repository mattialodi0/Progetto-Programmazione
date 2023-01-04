#include "Artifact.hpp"
//raggifrocio
Artifact::Artifact(int y, int x): Drawable(x,y,RandomArtifact())
{
   
}

chtype Artifact::RandomArtifact()
{
    srand(time(NULL));
    int i = (rand() % (3));
    if(i==1)
    {
        return 'R';
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