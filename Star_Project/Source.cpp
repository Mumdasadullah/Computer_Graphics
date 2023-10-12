
#include<GL/glut.h>
#include<iostream>


void initCT(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void starMotif(void)
{
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_LINE_STRIP);
	glVertex2i(18, 30);
	glVertex2i(0, 90);
	glVertex2i(-30, -14);
	glVertex2i(-20, -18);
	glVertex2i(2, 50);
	glVertex2i(7, 25);
	glVertex2i(18, 30);
	glEnd();
}

void rotate2D(double angle)
{
	glMatrixMode(GL_MODELVIEW);
	glRotated(angle,00,0.0,1.0);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//glColor3f(1.0,1.0,1.0);
	for (int i = 0; i < 5; i++)
	{
		starMotif();
		rotate2D(71.0);
	}

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(640,480);
	glutCreateWindow("Star with Transformation");

	initCT();
	glutDisplayFunc(myDisplay);
	//initCT();
	glutMainLoop();
	return 0;
}