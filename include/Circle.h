#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"


/*
A class that defines the basic qualities of the circle
*/
class Circle {
public:
    
    int pos_X;
    int pos_Y;
    int radius;
    cinder::Color8u color;
    Circle* next;
    Circle* previous;
};