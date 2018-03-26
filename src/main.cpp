#include "x11context.h"
#include <unistd.h>
#include <iostream>
 
int main(void)
{
	GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);
 
 
	// draw some lines
	gc->setColor(GraphicsContext::GREEN);
	gc->drawLine(-100,-75,800,600);
	gc->setColor(GraphicsContext::RED);
	gc->drawLine(800,0,0, 600);
	gc->setColor(GraphicsContext::BLUE);
	gc->drawCircle(400,300,150);
	gc->setColor(GraphicsContext::GREEN);
	gc->drawLine(400,0,400,600);
	gc->setColor(GraphicsContext::RED);
	gc->drawLine(0,300,800,300);
	gc->setColor(GraphicsContext::MAGENTA);
	gc->drawCircle(0,0,200);
	gc->drawCircle(800, 0, 200);
	gc->drawCircle(0, 600, 200);
	gc->drawCircle(800, 600, 200);
	gc->setColor(GraphicsContext::YELLOW);
	gc->drawCircle(400, 300, 300);
	gc->drawCircle(400, -200, 300);
	gc->drawCircle(400, 800, 300);
	gc->setColor(GraphicsContext::BLUE);
	gc->drawCircle(-200, 300, 400);
	gc->drawCircle(1000, 300, 400);
	sleep(5);
 
	delete gc;
 
	return 0;
}
