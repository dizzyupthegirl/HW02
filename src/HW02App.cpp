#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
//#include "Lists.h"


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

void changeColor(int r, int g, int b, int index, uint8_t* pixelData) {
		 if(index>=0 && index <kAppHeight*kAppWidth*3){
			pixelData[index]=r;
			pixelData[index+1]=g;
			pixelData[index+2]=b;
		}
	}
int getIndex(int x, int y) {
		return 3*(y*kAppWidth+x);
	}


void drawCircle(int x, int y, int r, uint8_t* pixelData){
    int tempX, tempY;
    double angle = 0;
    
    int i;
    
    while(angle < 6.28){
        tempX = x+r*sin(angle+3.14/2);
        tempY = y+r*sin(angle);
        i = getIndex(tempX, tempY);    
        changeColor(0,0,255,i, pixelData);
        angle+=.01;
    }
}

void HW02App::update()
{
	//uint8_t* pixelData = (*my_Surface).getData();
	//drawCircle(500, 500, 40,  pixelData);


}

void HW02App::draw()
{
	gl::draw(*my_Surface);

}



CINDER_APP_BASIC( HW02App, RendererGl )


