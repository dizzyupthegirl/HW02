#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"



class Squares {
public:
    
    int side;
    cinder::Color8u color;
    Squares* next;
    Squares* previous;

};