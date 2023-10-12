#include<GL/glut.h>
#include<iostream>
#include<fstream>

using namespace std;

float zoomFactor = 1.0f; // Initial zoom factor

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
	glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
	glMatrixMode(GL_MODELVIEW);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	//glScalef(0.7, 0.7, 0.0);
	glScalef(zoomFactor, zoomFactor, 1.0); // Apply zoom factor Scalef() resize the shape

	drawPolyLineFile("dino.dat");
	glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y) {
	if (key == '+') {
		zoomFactor += 0.1;
		//zoomFactor *= 1.1; // Zoom in by increasing the zoom factor
	}
	else if (key == '-') {
		zoomFactor -= 0.1;
		//zoomFactor /= 1.1; // Zoom out by decreasing the zoom factor
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) { // argc -> argument counter, argv -> argument vector
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Dino Zoom in & Zoom out");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
