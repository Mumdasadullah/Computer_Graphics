#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


int screenWidth = 640;	   // width of screen window in pixels 
int screenHeight = 480;	   // height of screen window in pixels

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

void setWindow(float left, float right, float bottom, float top)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);


	setWindow(0, 640.0, 0, 480.0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 11; j++) {

			glViewport(i * 64, j * 44, 64, 44);
			drawPolyLineFile("dino.dat");

		}

	}
	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(10, 10);

	glutCreateWindow("Tiling of a Dino"); // open the screen window


	glutDisplayFunc(myDisplay);


	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(2.0);

	glutMainLoop();

	return 1;
}