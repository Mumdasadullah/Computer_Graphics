#include "Canvas.h"
#include<GL/glut.h>
#include<iostream>

using namespace std;

#define M_PI 3.141
const double HEX_RADIUS = 0.05; // Radius of the hexagons

Canvas cvs(640,480,"Hexagonal Tiling");

void myInit()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(-0.1, 1, -0.1, 1);
	gluOrtho2D(-1, 0, -1, 0);
}

void motif()
{
	glColor3f(0.5, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < 6; i++)
	{
		double angle = 2.0 * M_PI * i / 6; // Angle for each vertex
		double x = HEX_RADIUS * cos(angle);
		double y = HEX_RADIUS * sin(angle);
		//glVertex2f(x, y);
		cvs.moveTo(x , y);
		cvs.lineTo(x , y);
	}

	glEnd();
}

/*void motif()
{
	cvs.moveTo(-0.85,-0.95);
	cvs.lineTo(-0.8,-0.95);

	cvs.moveTo(-0.8, -0.95);
	cvs.lineTo(-0.78, -0.9);

	cvs.moveTo(-0.78, -0.9);
	cvs.lineTo(-0.8, -0.85);

	cvs.moveTo(-0.8, -0.85);
	cvs.lineTo(-0.85, -0.85);

	cvs.moveTo(-0.85, -0.85);
	cvs.lineTo(-0.87, -0.9);

	cvs.moveTo(-0.87, -0.9);
	cvs.lineTo(-0.85, -0.95);
}*/


void tilingHexagonal()
{
	cvs.pushCT();
	cvs.translate2D(0.0, 0.0);

	for (int i = 0; i < 7; i++)
	{
		cvs.pushCT(); 
		for (int j = 0; j < 11; j++)
		{
			motif();
			//cvs.translate2D(0.2,0);
			if (j % 2 != 0)
			{
				cvs.translate2D(0.07, -0.05);
			}
			else
			{
				cvs.translate2D(0.07, 0.05);
			}
		}
		cvs.popCT();
		cvs.translate2D(0.0 ,0.1);
	}
	cvs.popCT();
}

/*void tiling()
{
	pushCT();
	translate2D(0.0,0.0);
	for (int row = 0; row < 7; row++)
	{
		pushCT();
		for (int col = 0; col < 11; col++)
		{
			motif();
			//translate2D(0.07,0.05);
			if (col % 2 != 0)
			{
				translate2D(0.07, -0.05);
			}
			else
			{
				translate2D(0.07, 0.05);
			}
			
		}
		popCT();
		translate2D(0.0, 0.1);
	}
	popCT();
}

glVertex2f(-0.85, -0.95);
	glVertex2f(-0.8, -0.95);
	glVertex2f(-0.78, -0.9);
	glVertex2f(-0.8, -0.85);
	glVertex2f(-0.85, -0.85);
	glVertex2f(-0.87, -0.9);
	glVertex2f(-0.85, -0.95);

*/

void myDisplay()
{
	cvs.clearScreen();
	cvs.setWindow(-1, 0, -1, 0);

	//motif();
	tilingHexagonal();

	glFlush();
}

int main(int argc, char** argv)
{
	cvs.setBackgroundColor(1.0,1.0,1.0);
	cvs.setColor(0.5,0.0,0.0);

	glutDisplayFunc(myDisplay);

	glutMainLoop();
	return 0;
}

/*#include "Canvas.h"

#include <GL/glut.h>
//#include <iostream>
//#include <fstream>
#include <math.h>


//#define M_PI  3.14157

// display

using namespace std;

Canvas cvs(640, 480, "Test Canvas Class for Task 8");



void display(void)
{
    //cvs.setBackgroundColor(1.0, 1.0, 1.0); //background color is white 
    cvs.clearScreen(); //clear screen

    //cvs.setColor(1.0, 0.0, 0.0); //drawing color is red 
    cvs.setWindow(-10.0, 10.0, -10.0, 10.0);
    cvs.setViewport(10, 460, 10, 460);

	// ***************PRACTICING Simple Line DRAWING************/ 

	// call moveTo() and lineTo();

  // ***************END RELATIVE DRAWING*********************//
	//cvs.moveTo(0, -10.0);
	//cvs.lineTo(0, 10.0);

	//Triangle triangle(0.0, 7.0, 6.0, -1.5);

	//glPointSize(2.0);

	//triangle.draw();

	//RealRect box(-2.0, 2.0, -1.0, 1.0);
	//glLineWidth(2.0);
	//box.draw();

	//glFlush();
//}// end display





//int main(int argc, char** argv)
//{
	//cvs.setBackgroundColor(1.0, 1.0, 1.0);

	//cvs.setColor(0.0, 0.0, 0.0);
	// the window is opened in the Canvas constructor
	//glutDisplayFunc(display);
	//glutMainLoop();

	//return 0;
//}//end main