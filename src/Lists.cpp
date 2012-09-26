
#include "Lists.h"



/*
Creates a new circle after the one specified
*/
Circle* Lists::insertAfter(Circle* previousCirc, int pos_X, int pos_Y, int radius){
    Circle* temp = new Circle;
    temp->next = previousCirc->next;
    temp->previous = previousCirc;
    previousCirc->next = temp;
    temp->next->previous = temp;
    temp->pos_X = pos_X;
    temp->pos_Y = pos_Y;

	// NC: Added to allow variable sizes of the circles
    temp->radius = radius; //circ_sentinel->radius;
    temp->color = cinder::Color8u(rand()%256, rand()%256, rand()%256);
    
    return temp;

}

/*
Moves the clicked on circle behind the ones around it
*/
void Lists::moveToBack(Circle* movee){
    movee->previous->next = movee->next;
    movee->next->previous = movee->previous;
    circ_sentinel->next->previous = movee;
    movee->next = circ_sentinel->next;
	// NC: Since circ_sentinel->next->previous is just movee, having circ_sentinel->next
	// get movee works just as well, but you don't have to use as many pointers!

    circ_sentinel->next = movee; //circ_sentinel->next->previous;
    movee->previous = circ_sentinel;
}

/*
Uses the distance formula to see if a specified point clicked is within a circle
*/
bool Lists::isInside(int x, int y, Circle* check) {
	// NC: Try different variable names, so that you can avoid using a capital version
	// of a variable already in use, as to avoid confusion
	int X = x-check->pos_X;
    int Y = y-check->pos_Y;
    int distance = sqrt((double)X*X+Y*Y);
    return(distance <= check->radius);
}

/*
Reverses the order of the list
*/
void Lists::reverse(){
    Circle* cur = circ_sentinel;
    Circle* temp;
    
    do {
        temp = cur->previous;
        cur->previous = cur->next;
        cur->next = temp;
        cur = cur->previous;
    }while(cur != circ_sentinel);
}
