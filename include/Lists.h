#include "Circle.h"

/*
A class that defines the list and its methods
*/
class Lists{
public:
    Circle* circ_sentinel;
	void moveToBack(Circle* movee);
    void reverse();
	
	// NC: I added "radius" as a parameter, so as to allow different circles to be different sizes, 
	// not just restricted to the size of the sentinel size, as it was before.
	// We all know how much fun different sized circles can be!
    Circle* insertAfter(Circle* prevNode, int pos_X, int pos_Y, int radius);
	bool isInside(int x, int y, Circle* check);
};