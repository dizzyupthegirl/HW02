#include "Circle.h"

/*
A class that defines the list and its methods
*/
class Lists{
public:
    Circle* circ_sentinel;
	void moveToBack(Circle* movee);
    void reverse();
    Circle* insertAfter(Circle* prevNode, int pos_X, int pos_Y);
	bool isInside(int x, int y, Circle* check);
};