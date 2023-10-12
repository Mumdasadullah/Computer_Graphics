#include<GL/glut.h>
#include<iostream>
#include<cmath>
#include<math.h>

float deg = 0.0;

void myInit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	//glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void tooth0()
{
	glColor3f(0.0, 0.5, 0.0);
	glBegin(GL_LINE_STRIP);

	glVertex2f(0.0,0.0);
	glVertex2f(0.2,0.2);
	glVertex2f(0.6,0.2);
	glVertex2f(0.6,0.8);
	glVertex2f(0.2,0.8);
	glVertex2f(0.0,1.0);

	glEnd();
}

void tooth1(double r)
{
	double rad = 6.0 * 3.1416 / 180.0;
	double sin6 = r * sin(rad);
	double cos6 = r * cos(rad);

	glPushMatrix();

	glTranslatef(cos6 , -sin6, 0.0);
	glScalef(2.0 * sin6, 2.0 * sin6, 1.0);
	tooth0();

	glPopMatrix();
}

void gear(double r)
{
	glPushMatrix();
	for (int i = 1; i <= 30; ++i)
	{
		tooth1(r);
		glRotatef(12.0,0.0,0.0,1.0);
	}
	glPopMatrix();
}

void move(int val)
{
	float speed = 0.5;
	
	deg += speed;

	//if (deg >= 360)
	//{
		//deg -= 360;
	//}
	glutPostRedisplay();
	glutTimerFunc(0, move, 1);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glRotatef(deg, 0.0,0.0, 1.0);

	//tooth1(0.8);
	gear(0.3);

	int num_segments = 100;
	double radius = 0.05;
	glColor3f(0.0, 0.5, 0.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < num_segments; i++)
	{
		double theta = 2.0 * 3.1415926 * double(i) / double(num_segments);
		double x = radius * cos(theta);
		double y = radius * sin(theta);
		glVertex2f(x, y);
	}
	glEnd();

	glutTimerFunc(20, move, 1);

	glFlush();
	//glutSwapBuffers();

	//glutPostRedisplay();
	//glutSwapBuffers();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Gear With Animation");

	myInit();
	glutDisplayFunc(myDisplay);
	glutTimerFunc(0, move, 1);

	glutMainLoop();
	return 0;
}