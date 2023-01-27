#pragma once

#include "Board.hpp"
// cstdlib e ctime inclusi in board

class Artifact : public Drawable
{
protected:
public:
    Artifact();
    Artifact(int y, int x);
    chtype RandomArtifact();
};