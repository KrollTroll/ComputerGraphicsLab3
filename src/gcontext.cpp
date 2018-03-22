/* This is an abstract base class representing a generic graphics
 * context.  Most implementation specifics will need to be provided by
 * a concrete implementation.  See header file for specifics. */

#define _USE_MATH_DEFINES	// for M_PI
#include <cmath>	// for trig functions
#include "gcontext.h"	

/*
 * Destructor - does nothing
 */
GraphicsContext::~GraphicsContext()
{
	// nothing to do
	// here to insure subclasses handle destruction properly
}


/* This is a naive implementation that uses floating-point math
 * and "setPixel" which will need to be provided by the concrete
 * implementation.
 * 
 * Parameters:
 * 	x0, y0 - origin of line
 *  x1, y1 - end of line
 * 
 * Returns: void
 */
//TODO: implement
void GraphicsContext::drawLine(int x0, int y0, int x1, int y1)
{
	if(abs(y1-y0) < abs(x1-x0)){
		if(x0 > x1){
			lowGradientLine(x1, y1, x0, y0);
		}
		else{
			lowGradientLine(x0, y0, x1, y1);
		}
	}
	else{
		if(y0 > y1){
			highGradientLine(x1, y1, x0, y0);
		}
		else{
			highGradientLine(x0, y0, x1, y1);
		}
	}

	return;
}

//TODO: implement
void GraphicsContext::lowGradientLine(int x0, int y0, int x1, int y1){
	int dx = x1-x0;
	int dy = y1-y0;
	int interceptY = 1;
	if(dy < 0){
		interceptY = -1;
		dy = -dy;
	}
	int difference = 2*dy-dx;
	int y = y0;

	for(int x = x0; x < x1; x++){
		setPixel(x, y);
		if(difference > 0){
			y = y+interceptY;
			difference = difference -2*dx;
		}
		difference = difference + 2*dy;
	}
}

//TODO: implement
void GraphicsContext::highGradientLine(int x0, int y0, int x1, int y1){
	int dx = x1-x0;
	int dy = y1-y0;
	int interceptX = 1;
	interceptX = 1;
	if(dx < 0){
		interceptX = -1;
		dx = -dx;
	}
	int difference = 2*dx - dy;
	int x = x0;

	for(int y = y0; y < y1; y++){
		setPixel(x, y);
		if(difference > 0){
			x = x + interceptX;
			difference = difference - 2*dy;
		}
		difference = difference + 2*dx;
	}
}



/* This is a naive implementation that uses floating-point math
 * and "setPixel" which will need to be provided by the concrete
 * implementation.
 * 
 * Parameters:
 * 	x0, y0 - origin/center of circle
 *  radius - radius of circle
 * 
 * Returns: void
 */
void GraphicsContext::drawCircle(int x0, int y0, unsigned int radius)
{
	// This is a naive implementation that draws many line
	// segments.  Also uses floating point math for poor performance

	// also, large circles will be "jagged"
	
	// start at 0 degrees
	int oldx = radius;
	int oldy = 0;

	// go from 1 to 360 degrees
	for (int segment =1; segment<=360; segment += 1)
	{
		int newx = std::cos(segment*M_PI/180)*radius;
		int newy = std::sin(segment*M_PI/180)*radius;

		// hit four quadrants
		drawLine(x0+oldx,y0+oldy,x0+newx,y0+newy);
		
		oldx = newx;
		oldy = newy;
		
	}
	
	return;	
}

void GraphicsContext::endLoop()
{
	run = false;
}


