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