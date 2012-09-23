#include "Circle.h"
#include "Squares.h"


class Lists{
public:
    Circle* circ_sentinel;
	Squares* sqr_sentinel;
    //void reverse();
    Circle* insertAfter(Circle* prevNode, int pos_X, int pos_Y);
	Squares* insertAfter(Squares* prevNode, int s);
    
};