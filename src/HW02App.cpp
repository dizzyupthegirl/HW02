#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Lists.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class HW02App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

	void prepareSettings(Settings* settings);

	
	private:
		Surface* my_Surface;
};

	static const int kAppWidth = 800;
	static const int kAppHeight = 600;
	static const int textureSize = 1024;

	void HW02App::prepareSettings(Settings* settings){
	(*settings).setWindowSize(kAppWidth,kAppHeight);
	(*settings).setResizable(false);

	}

void HW02App::setup()
{
}





void HW02App::mouseDown( MouseEvent event )
{

}
void insertAfter(Circle* where, Circle new_circ) {
Circle* temp_p=new node();
temp_p->next_=where->next_;
where->next_=temp_p;
temp_p->data_=new_circ;

}

void HW02App::update()
{
}

void HW02App::draw()
{
	gl::draw(*my_Surface);
}

CINDER_APP_BASIC( HW02App, RendererGl )



class node{
public:
		node* next_;
		Circle data_;
}