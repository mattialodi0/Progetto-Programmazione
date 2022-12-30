#include "../Drawable.hpp"

class Door : public Drawable {
public:
	Door(int y, int x) : Drawable(y, x,'O') {}
	Door(int y, int x, char c) : Drawable(y, x,'Q') {}
};

class Locked_Door : public Door {
public:
	Locked_Door(int y, int x) : Door(y, x,'Q') {}
};

