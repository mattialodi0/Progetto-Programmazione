#include "Drawable.hpp"

class Door : public Drawable
{
public:
	Door(int y, int x) : Drawable(y, x, 'O') {}
	Door(int y, int x, char c) : Drawable(y, x, c) {}
};

class Locked_Door : public Door
{
public:
	Locked_Door(int y, int x) : Door(y, x, 'Q') {}
};

class No_Door : public Door
{
public:
	No_Door(int y, int x) : Door(y, x, ' ') {}
};
