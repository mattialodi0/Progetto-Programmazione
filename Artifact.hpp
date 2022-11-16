#pragma once

#include "Board.hpp"
// cstdlib e ctime inclusi in board

class Artifact : public Drawable
{
protected:
    
public:
    Artifact();
    chtype RandomArtifact();
};

//mancano gli effetti degli artifatti