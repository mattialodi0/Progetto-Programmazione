#pragma once

#include "Board.hpp"
// cstdlib e ctime inclusi in board

class Artifact : public Drawable
{
public:
    Artifact();
    Artifact(int y, int x,chtype ch);
    Artifact(int y, int x);
    chtype RandomArtifact(); 
};