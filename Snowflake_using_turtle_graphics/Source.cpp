#include "turtle.h"
#include <GL/glut.h>
#include <iostream>


Canvas cvs;

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10 , 10 , -10 , 10);
}

void flakeMotif(float L)
{
	cvs.moveTo(0.12 , 0.1 * L);
	cvs.turnTo(0);
	cvs.forward(2 * L, 1);
	cvs.turn(60);
	cvs.forward(1 * L, 1);
	cvs.turn(270);
	cvs.forward(0.2 * L, 1);
	cvs.turn(270);
	cvs.forward(0.9 * L, 1);
	cvs.turn(120);
	cvs.forward(1 * L, 1);
	cvs.turn(60);
	cvs.forward(0.9 * L, 1);
	cvs.turn(270);
	cvs.forward(0.2 * L, 1);
	cvs.turn(270);
	cvs.forward(0.8 * L, 1);
	cvs.turn(120);
	cvs.forward(1 * L, 1);
	cvs.turn(330);
	cvs.forward(0.2 * L, 1);
	cvs.turn(30);
}

void drawFlake()
{
	for (int count = 0; count < 6; count++)
	{
		flakeMotif(1);
		cvs.scale2D(1.0 , -1.0);
		flakeMotif(1);
		cvs.scale2D(1.0, -1.0);
		cvs.rotate2D(60.0);
	}
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//flakeMotif(1);
	drawFlake();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc , argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50 ,50);
	glutInitWindowSize(640 , 480);
	glutCreateWindow("Snowflake using Turtle Graphics");

	myInit();
	glutDisplayFunc(myDisplay);

	glutMainLoop();
	return 0;
}

/*void drawFlake(void)
{
	for (int i = 0; i < 6; i++)
	{
		flakeMotif();
		scale2D(1.0,-1.0);
		flakeMotif();
		scale2D(1.0,-1.0);
		rotate2D(60.0);
	}
*/