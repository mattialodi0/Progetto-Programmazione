#include "Artifact.hpp"

Artifact::Artifact(): Drawable()
{
   
}

Artifact::Artifact(int y, int x,chtype ch): Drawable(y,x,ch)
{
   
}
Artifact::Artifact(int y, int x): Drawable(y,x,RandomArtifact())
{
   
}

chtype Artifact::RandomArtifact()
{
    srand(time(NULL));
    int i = (rand() % (4));
    switch(i){
        case '0':
        return 'R';
        case '1':
        return 'E';
        case '2':
        return 'H';
        case '3':
        return 'J';
            };
}