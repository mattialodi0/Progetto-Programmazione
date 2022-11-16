#include "../Drawable.hpp"

class Door : public Drawable {
public:
	Door(int y, int x) : Drawable(y, x,'O') {}
};