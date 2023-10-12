#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

const double PI = 3.14159265358979323846;
const int screenWidth = 640;
const int screenHeight = 480;

class Point2
{
public:
	float x;
	float y;

	Point2()
	{
		x = 0.0;
		y = 0.0;
	}

	float getX()
	{
		return x;
	}
	float getY()
	{
		return y;
	}
};

void myInit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.1,0.1,0.1);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluOrtho2D(0, (GLint)screenWidth, 0, (GLint)screenHeight);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
}

void drawArc(Point2 centre, float radius, float startAngle, float sweep)
{
	const int n = 20;
	float angle = startAngle * PI/180;
	float angleInc = sweep * PI / (180 * n);
	float cx = centre.getX();
	float cy = centre.getY();

	glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);

	glVertex2f(cx + radius * cos(angle), cy + radius * sin(angle));
	for (int i = 1; i < n; ++i, angle += angleInc)
	{
		glVertex2f(cx + radius * cos(angle), cy + radius * sin(angle));
	}

	glEnd();
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	Point2 centre;
	float radius = 0.5;       // Radius of the arc
	float startAngle = 30.0;  // Starting angle in degrees
	float sweepAngle = 120.0;
	drawArc(centre, radius, startAngle, sweepAngle);
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(10,10);
	glutInitWindowSize(screenWidth, screenHeight);
	glutCreateWindow("Arc Window");

	myInit();
	glutDisplayFunc(myDisplay);

	glutMainLoop();
	return 0;
}