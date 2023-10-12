/*
#include <GL/glut.h>
#include<fstream>
#include <iostream>

using namespace std;

// Variables to store the viewport position
float viewportX = 0.0f;
float viewportY = 0.0f;

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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
	glMatrixMode(GL_MODELVIEW);
}

// Function to handle keyboard input for panning
void handleKeyPress(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        viewportY += 0.1f; // Move the viewport up
        break;
    case 's':
        viewportY -= 0.1f; // Move the viewport down
        break;
    case 'a':
        viewportX -= 0.1f; // Move the viewport left
        break;
    case 'd':
        viewportX += 0.1f; // Move the viewport right
        break;
    }
    glutPostRedisplay(); // Trigger a redraw
}

// Function to handle viewport resizing
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0 + viewportX, 1.0 + viewportX, -1.0 + viewportY, 1.0 + viewportY);
	//gluOrtho2D(-0.5 + viewportX, 1.5 + viewportX, -0.5 + viewportY, 1.5 + viewportY);
    glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

// Function to render the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
	drawPolyLineFile("dino.dat");
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Dynamic Viewport");
	init();
	glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyPress);
    glutReshapeFunc(reshape);

    //glClearColor(0.0, 0.0, 0.0, 1.0);

    glutMainLoop();
    return 0;
}


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
	glScalef(zoomFactor, zoomFactor, 1.0); // Apply zoom factor Scalef() resize the shape

	drawPolyLineFile("dino.dat");
	glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y) {
	if (key == '+') {
		zoomFactor *= 1.1; // Zoom in by increasing the zoom factor
	}
	else if (key == '-') {
		zoomFactor /= 1.1; // Zoom out by decreasing the zoom factor
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
	//glMatrixMode(GL_MODELVIEW);
}

void setViewport()
{
	glViewport(ViewportXmin,ViewportYmin, ViewportXmax - ViewportXmin, ViewportYmax - ViewportYmin);

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

*/


#include <GL/glut.h>
#include <fstream>
#include <iostream>

using namespace std;
// Variables to control the viewport position
float viewportX = 0.0f;
float viewportY = 0.0f;

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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Function to display the scene
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(-viewportX, -viewportY, 0.0f);
	// Render your objects here
	drawPolyLineFile("dino.dat");
	// Swap the buffers
	glutSwapBuffers();
}

// Function to handle keyboard input
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'a': // Move left
		viewportX += 1.1f;
		break;
	case 'd': // Move right
		viewportX -= 1.1f;
		break;
	case 'w': // Move up
		viewportY -= 1.1f;
		break;
	case 's': // Move down
		viewportY += 1.1f;
		break;
	case 27: // Escape key to exit
		exit(0);
		break;
	}

	glutPostRedisplay(); // Redraw the scene
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Viewport Movement");

	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//glColor3f(1.0, 1.0, 1.0);
	//glPointSize(2.0);

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	init();

	glutMainLoop();

	return 0;
}
