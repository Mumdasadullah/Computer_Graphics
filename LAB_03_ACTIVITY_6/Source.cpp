#include <GL/glut.h>
#include <iostream>
#include <math.h>

const double PI = 3.14159265358979323846;

using namespace std;

const int screenWidth = 640;
const int screenHeight = 480;

void myInit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLint)screenWidth, 0, (GLint)screenHeight);
	glMatrixMode(GL_MODELVIEW);
}

void ngon(int n, double cx, double cy, double radius, double rotAngle)
{
	if (n < 3)
	{
		return;
	}

	glLineWidth(2.0);
	glBegin(GL_LINE_LOOP);

	double angle = rotAngle * PI / 180;
	double angleInc = 2 * PI / n;
	glVertex2f(200 + (radius *cos(angle) + cx),150 + (radius *sin(angle) +cy));
	for (int i = 0; i < n; i++)
	{
		angle += angleInc;
		glVertex2f(200 + (radius * cos(angle) + cx),150 + (radius * sin(angle) + cy));
	}

	glEnd();
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	ngon(40,200,80,100,0);
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(10,10);
	glutInitWindowSize(screenWidth, screenHeight);
	glutCreateWindow("Parameterized Regular Polygon");

	myInit();
	glutDisplayFunc(myDisplay);
	
	glutMainLoop();
	return 0;
}