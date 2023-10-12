
#pragma warning(disable : 4996)
#include <stdio.h>
#include <iostream>
//#include<Windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "PixMap.h"
#include "mario.h"

Mario m(Point2(0, 0));


void myInit(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_EQUAL, 1.0);
	glViewport(0, 0, 640, 480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	m.changeMode(Mario::STAY);

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m.render();
	glFlush();
}

//void spinner(int t)
//{
//	glutPostRedisplay();
//	glutTimerFunc(500, spinner, t);
//
//}

void PressKeySpecial(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		m.changePosition(-5, 0);
		m.changeMode(Mario::RUN);
		break;
	case GLUT_KEY_RIGHT:
		m.changePosition(5, 0);
		m.changeMode(Mario::RUN);
		break;
	case GLUT_KEY_UP:
		m.changePosition(4, 5);
		m.changeMode(Mario::JUMP);
		break;
	case GLUT_KEY_DOWN:
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void ReleaseKeySpecial(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		m.changePosition(5,0);
		m.changeMode(Mario::STAY);
		break;
	case GLUT_KEY_RIGHT:
		m.changePosition(5, 0);
		m.changeMode(Mario::STAY);
		break;
	case GLUT_KEY_UP:
		if (m.pos_Y != 0)
		{
			m.changePosition(4,0);
		}
		//m.changePosition(4, 0);
		m.changeMode(Mario::STAY);
		break;
	case GLUT_KEY_DOWN:
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


void myKB_Handler(unsigned char key, int mx, int my)
{
	switch (key)
	{
	case 'f':

		m.changeMode(Mario::RUN);
		break;

	case 'j':

		m.changeMode(Mario::JUMP);
		break;
	case 'd':
		m.changePosition(0,0);
		m.changeMode(Mario::DEAD);
		//Sleep(10);
		//exit(-1);
		break;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("My Mario");

	myInit();
	glutDisplayFunc(display);
	glutSpecialFunc(PressKeySpecial);
	glutSpecialUpFunc(ReleaseKeySpecial);
	glutKeyboardFunc(myKB_Handler);

	glutIdleFunc(display);
	glutMainLoop();

	return 0;
}

