
#include "Lists.h"



/*
Creates a new circle after the one specified
*/
Circle* Lists::insertAfter(Circle* previousCirc, int pos_X, int pos_Y){
    Circle* temp = new Circle;
    temp->next = previousCirc->next;
    temp->previous = previousCirc;
    previousCirc->next = temp;
    temp->next->previous = temp;
    temp->pos_X = pos_X;
    temp->pos_Y = pos_Y;
    temp->radius = circ_sentinel->radius;
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
    circ_sentinel->next = circ_sentinel->next->previous;
    movee->previous = circ_sentinel;
}

/*
Uses the distance formula to see if a specified point clicked is within a circle
*/
/*BS: I would put this in the circle class so you don't have to pass the circle pointer*/
bool Lists::isInside(int x, int y, Circle* check) {
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
