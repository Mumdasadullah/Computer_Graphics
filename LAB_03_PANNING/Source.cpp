#include <GL/glut.h>
#include<fstream>
#include <iostream>

using namespace std;

int ReferenceX = 0;
int ReferenceY = 0;
int ViewportXmin = 0;
int ViewportXmax = 640;
int ViewportYmin = 0;
int ViewportYmax = 480;

void drawPolyLineFile(const char* fileName)
{
	fstream inStream;

	inStream.open(fileName, ios::in);	// open the file

	if (inStream.fail())
	{
		cout << "can't open it!";
		return;
	}

	//glClear(GL_COLOR_BUFFER_BIT);
	GLint numpolys, numPoints, x, y;
	inStream >> numpolys;		           // read the number of polylines

	for (int j = 0; j < numpolys; j++)  // read each polyline
	{
		inStream >> numPoints;       //number of points in first PolyLine
		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numPoints; i++)
		{
			inStream >> x >> y;        // read the next x, y pair
			glVertex2f(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
	glViewport(0, 0, 640, 480);
}

void setViewport()
{
	glViewport(ViewportXmin, ViewportYmin, ViewportXmax - ViewportXmin, ViewportYmax - ViewportYmin);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(ViewportXmin, ViewportXmax, ViewportYmin, ViewportYmax);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		ReferenceX = x;
		ReferenceY = y;
	}
}

void myMotion(int x, int y)
{
	int dx = x - ReferenceX;
	int dy = -(y - ReferenceY);

	ViewportXmin += dx;
	ViewportXmax += dx;
	ViewportYmin += dy;
	ViewportYmax += dy;
	setViewport();

	ReferenceX = x;
	ReferenceY = y;

	glutPostRedisplay();
}

void myKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		ViewportYmin += 2;
		break;
	case 's':
		ViewportYmax -= 2;
		break;
	case 'a':
		ViewportXmin += 2;
		break;
	case 'd':
		ViewportXmax -= 2;
		break;
	default:
		break;
	}
	setViewport();
	glutPostRedisplay();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawPolyLineFile("dino.dat");
	glutSwapBuffers();
}

int main(int argc, char** argv) { // argc -> argument counter, argv -> argument vector
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Dino Zoom in & Zoom out");
	glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboard);
	glutMouseFunc(myMouse);
	glutMotionFunc(myMotion);
	init();
	glutMainLoop();
	return 0;
}