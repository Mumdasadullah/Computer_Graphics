#include<GL/glut.h>
#include<iostream>
//#include<cmath>

#define M_PI 3.141
const double HEX_RADIUS = 0.05; // Radius of the hexagons

void myInit();
void motif();
void myDisplay();
void pushCT();
void checkStack();
void translate2D(double dx, double dy);
void popCT();
void tiling();

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-0.1, 1, -0.1, 1);
	//gluOrtho2D(-1, 0, -1, 0);
}

void motif()
{
	glColor3f(0.5, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < 6; i++)
	{
		double angle = 2.0 * M_PI * i / 6; // Angle for each vertex
		double x = HEX_RADIUS * cos(angle);
		double y = HEX_RADIUS * sin(angle);
		glVertex2f(x, y);
	}

	glEnd();
}

/*void motif()
{
	glColor3f(0.5, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);

	glVertex2f(-0.85, -0.95);
	glVertex2f(-0.8, -0.95);
	glVertex2f(-0.78, -0.9);
	glVertex2f(-0.8, -0.85);
	glVertex2f(-0.85, -0.85);
	glVertex2f(-0.87, -0.9);
	glVertex2f(-0.85, -0.95);

	glEnd();
}*/

void tiling()
{
	pushCT();
	translate2D(0.0,0.0);
	for (int row = 0; row < 7; row++)
	{
		pushCT();
		for (int col = 0; col < 11; col++)
		{
			motif();
			//translate2D(0.07,0.05);
			if (col % 2 != 0)
			{
				translate2D(0.075, -0.045);
			}
			else
			{
				translate2D(0.075, 0.045);
			}
			
		}
		popCT();
		translate2D(0.0, 0.087);
	}
	popCT();
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	tiling();

	glFlush();
}

void pushCT()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
}

void checkStack()
{
	if (GL_MODELVIEW_STACK_DEPTH == 1)
	{
		pushCT();
	}
	else
	{
		popCT();
	}
}

void popCT()
{
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void translate2D(double dx, double dy)
{
	glMatrixMode(GL_MODELVIEW);
	glTranslated(dx, dy, 0.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Hexagonal Tiling");

	myInit();
	glutDisplayFunc(myDisplay);

	glutMainLoop();
	return 0;
}