
#include<GL/glut.h>
#include<iostream>


void initCT(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void flakeMotif(void)
{

	glPointSize(3.0f);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINE_STRIP);
	//glVertex2i(-300, 5);
	//glVertex2i(-30,5);
	glVertex2i(10, 5);
	glVertex2i(50, 5);
	glVertex2i(65, 25);
	glVertex2i(70, 24);
	glVertex2i(55, 5);
	glVertex2i(70, 5);
	glVertex2i(85, 25);
	glVertex2i(90, 24);
	glVertex2i(75, 5);
	glVertex2i(85, 5);
	glVertex2i(90, 5);
	glVertex2i(140, 5);
	//glVertex2i(200, 5);
	glEnd();
}

void scale2D(double sx, double sy)
{
	glMatrixMode(GL_MODELVIEW);
	glScaled(sx,sy,1.0);
}

void rotate2D(double angle)
{
	glMatrixMode(GL_MODELVIEW);
	glRotated(angle, 00, 0.0, 1.0);
}

void drawFlake(void)
{
	for (int i = 0; i < 6; i++)
	{
		flakeMotif();
		scale2D(1.0,-1.0);
		flakeMotif();
		scale2D(1.0,-1.0);
		rotate2D(60.0);
	}
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//flakeMotif();
	drawFlake();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Star with Transformation");

	initCT();
	glutDisplayFunc(myDisplay);
	//initCT();
	glutMainLoop();
	return 0;
}