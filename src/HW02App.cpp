#include "Lists.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppNative.h"
#include "cinder/Text.h"
#include "cinder/Utilities.h"
#include "cinder/ImageIo.h"
#include "Resources.h"


/*
Samantha Wolf
Hw02
Citations: 
I looked at the sample apps a lot, including the text apps and the basic app.
I also used as references a few of my peers including: 
Nick Collins, Brandon Sonoda, and Lucy(Uploaded to Prof. Brinkman's github)
Also, I referred to Professor Brinkman's code as examples a few times.
		


A. Met by the circle linked list.
B. Met by the keyDown option
C.Met by the mouseDown option, that when you click inside a circle, it move to the back.
E.Met by reverse function
J. Met by the mouseDrag (Makes it possible to "connect the dots")
*/

using namespace ci;
using namespace ci::app;
using namespace std;

#include <list>
using std::list;

class HW02App : public AppBasic {
  public:
    Lists* circList;
	void setup();
	void keyDown( KeyEvent event );
	void mouseDown( MouseEvent event );	
	void mouseDrag(MouseEvent event);
	void update();
	void draw();
	void prepareSettings(Settings* settings);
	

	
	private:
	static const bool PREMULT = false;
	static const int kAppWidth = 800;
	static const int kAppHeight = 600;
	static const int textureSize = 1024;
	int cnt;
	list<Vec2f>		mPoints;
	bool help;
	gl::Texture	mTexture;
		
};

/*
Sets up the correct settings for the window
*/
void HW02App::prepareSettings(Settings* settings){
	(*settings).setWindowSize(kAppWidth,kAppHeight);
	(*settings).setResizable(false);

	}

/*
Creates the linked list and assigns variables their values.
Also creates the text that appears when toggling help
*/
void HW02App::setup() {
	circList = new Lists;
    circList->circ_sentinel = new Circle;
    circList->circ_sentinel->next = circList->circ_sentinel;
    circList->circ_sentinel->previous = circList->circ_sentinel;
	
	
	circList->circ_sentinel->radius = 30;
	circList->circ_sentinel->pos_X=200;
	circList->circ_sentinel->pos_Y=0;
	
    Circle* next;
	
	next=circList->insertAfter(circList->circ_sentinel, 400, 50,60);
	next=circList->insertAfter(next,100 , 250 ,30);
	for(int i=1; i<7; i++) {
	 next= circList->insertAfter(next, (circList->circ_sentinel->pos_X) ,  (circList->circ_sentinel->pos_X)+50*i, 30);
	}
	for(int i=1; i<7; i++) {
	 next= circList->insertAfter(next, (circList->circ_sentinel->pos_X)+400 ,  (circList->circ_sentinel->pos_X)+50*i, 30 );
	}
	next=circList->insertAfter(next, 700, 250, 30);
	

	help=true;
	#if defined( CINDER_COCOA_TOUCH )
	std::string normalFont( "Arial" );
	std::string differentFont( "AmericanTypewriter" );
	#else
	std::string normalFont( "Arial" );
	std::string differentFont( "Papyrus" );
	#endif
	TextLayout layout;
	layout.clear( ColorA( 0.2f, 0.2f, 0.2f, 0.2f ) );
	layout.setFont( Font( normalFont, 22 ) );
	layout.setColor( Color( 0.0f, 1.0f, 0.5f ) );
	layout.addCenteredLine( "Welcome to Connect the Dots!" );
	layout.addCenteredLine( "Right click or hit shift to reverse list" );
	layout.addCenteredLine( "Drag mouse to connect dots" );
	layout.addCenteredLine( "Click in any circle to move it back" );
	layout.setFont( Font( differentFont, 24 ) );
	layout.addCenteredLine( "Hit ? or h to toggle this screen" );
	Surface8u rendered = layout.render( true, PREMULT );
	mTexture = gl::Texture( rendered );
	
}

/*
Handles an event in case a key is pushed. Only deals with the shift button, h, and ?
*/
void HW02App::keyDown(cinder::app::KeyEvent event )
	{
	if(event.isShiftDown())
	circList->reverse();
	if(event.getChar()=='h' || event.getChar()=='/')
		help=!help;

	//NC: Kind of unneccesary, but I decided that clearing the screen could be fun.
	if(event.getChar()==' ')
		mPoints.clear();
	}

/*
Makes it possible to draw on the screen!
*/
void HW02App::mouseDrag( MouseEvent event )
{
	// add wherever the user drags to the end of our list of points
	// NC: conditional added for less confusing interface. Line is only
	// drawn when the left button is down
	if(event.isLeftDown())
	    mPoints.push_back( event.getPos() );

}

/*
Handles the event of a click on the screen. 
It reverses the list, and if it's on a circle, will move it behind the two surrounding it
*/
void HW02App::mouseDown( MouseEvent event )
{
	if(event.isRightDown())
	    circList->reverse();

	// NC TODO: I wasn't able to figure it out for myself, but it would be nice
	// for one circle to still be pushed back if multiple circles are clicked
	Circle* current = circList->circ_sentinel->next;
	while(current!= circList->circ_sentinel) {
	if(circList->isInside(event.getX(), event.getY(),current)) {
		circList->moveToBack(current);
		current=circList->circ_sentinel;
	}
	else 
		current = current->next;
	
	}
	
	

}

/*
Updates screen by clearing it. Had time allowed, would have used this section for motion
*/
void HW02App::update()
	
{
	gl::clear( Color( 0,0,0 ) ); 
	
}

/*
Draws everything on the screen
*/
void HW02App::draw()
{
	
	
	if(help) {
		glClearColor( 0.1f, 0.1f, 0.1f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
	gl::setMatricesWindow( getWindowSize() );

	gl::enableAlphaBlending( PREMULT );

	gl::color( Color::white() );
	gl::draw( mTexture, Vec2f( 240, 200 ) );
	}
	else{

    Circle* current = circList->circ_sentinel->next;
	
    while(current!= circList->circ_sentinel){
		gl::color(current->color);
		gl::drawSolidCircle(Vec2f(current->pos_X, current->pos_Y), current->radius,0);
		current = current->next;
    }    
	  
 	glColor3f( 1.0f, 1.0f, 1.0f );
	
	
	glBegin( GL_LINE_STRIP );
	for( list<Vec2f>::iterator pointIter = mPoints.begin(); pointIter != mPoints.end(); ++pointIter ) {
		glVertex2f( *pointIter );
	}
	glEnd();
	}
}


CINDER_APP_BASIC( HW02App, RendererGl )


