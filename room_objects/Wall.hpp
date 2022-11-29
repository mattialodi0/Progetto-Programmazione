#include "../Drawable.hpp"

class Wall : public Drawable {
public:
	Wall(int y, int x) //: Drawable(y, x,'X') {}
	{
		this->y=y;this->x=x;this->icon='X';
	}
};