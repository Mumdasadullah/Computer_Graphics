#include<GL/glut.h>
#include<iostream>
#include<math.h>

using namespace std;

const double PI = 3.14159265358979323846;
GLint n = 4;
const int screenWidth = 640;
const int screenHeight = 480;

void drawRoseCurve(GLdouble radians, GLdouble x, GLdouble y)
{

	glBegin(GL_POLYGON);

	glVertex2d(0.0, 0.0);
	for (GLdouble thetha = 0; thetha <= 360.0; thetha += 2.0)
	{
		radians = (thetha * PI) / 180.0;
		x = cos(n * radians) * cos(radians);
		//x = 2.0 * cos(n * radians);
		//y = 2.0 * sin(n * radians);
		y = cos(n * radians) * sin(radians);
		glVertex2d(x, y);
	}

	glEnd();
}

void myInit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluOrtho2D(0 , (GLint)screenWidth, 0, (GLint)screenHeight);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(200, 55, 134);
	drawRoseCurve(0.0, 0.0, 0.0);
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(10,10);
	glutCreateWindow("Rose Curve");

	glutDisplayFunc(myDisplay);
	myInit();

	glutMainLoop();
	return 0;
}