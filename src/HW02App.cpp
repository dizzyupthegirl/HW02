#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW02App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void HW02App::setup()
{
}



void HW02App::mouseDown( MouseEvent event )
{

}
void insertAfter(node* where, Circle new_circ) {
node* temp_p=new node();
temp_p->next_=where->next_;
where->next_=temp_p;
temp_p->data_=new_circ;

}

void HW02App::update()
{
}

void HW02App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HW02App, RendererGl )



class node{
public:
		node* next_;
		Circle data_;
}