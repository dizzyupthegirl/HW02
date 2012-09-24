#include "Circle.h"


class Lists{
public:
    Circle* circ_sentinel;
	void moveToFront(Circle* movee);
    void reverse();
	void resize();
    Circle* insertAfter(Circle* prevNode, int pos_X, int pos_Y);
	bool isInside(int x, int y, Circle* check);
};