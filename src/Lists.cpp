#include "Lists.h"

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
void Lists::moveToFront(Circle* movee){
    movee->previous->next = movee->next;
    movee->next->previous = movee->previous;
    circ_sentinel->next->previous = movee;
    movee->next = circ_sentinel->next;
    circ_sentinel->next = circ_sentinel->next->previous;
    movee->previous = circ_sentinel;
}

bool Lists::isInside(int x, int y, Circle* check) {
	int deltaX = x-check->pos_X;
    int deltaY = y-check->pos_Y;
    int distance = sqrt((double)deltaX*deltaX+deltaY*deltaY);
    return(distance <= check->radius);
}

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
