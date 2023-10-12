#include<GL/glut.h>
#include<iostream>
#include<math.h>

using namespace std;

const double PI = 3.14159265358979323846;
const int screenWidth = 640;
const int screenHeight = 480;

void myInit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawCircle(GLdouble radius, GLdouble x, GLdouble y)
{
	GLdouble radian;
	glLineWidth(2.0);
	glBegin(GL_LINE_LOOP);
	//glVertex2d(0.0, 0.0);

	for (GLdouble theta = 1; theta <= 360.0; theta++)
	{
		radian = (theta * PI)/180.0;
		glVertex2d(x + (radius * cos(radian)), y + (radius * sin(radian)));
	}

	glEnd();
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawCircle(0.7, 0.0, 0.0);
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(10,10);
	glutCreateWindow("Circle using equation");

	myInit();
	glutDisplayFunc(myDisplay);

	glutMainLoop();
	return 0;
}