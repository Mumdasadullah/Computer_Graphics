
#pragma warning(disable : 4996)
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "pixmap.h"
//#include "Spider.h"

class Point2
{
public:
	Point2() { x = y = 0.0f; } // constructor 1
	Point2(float xx, float yy) { x = xx; y = yy; } // constructor 2
	void set(float xx, float yy) { x = xx; y = yy; }
	float getX() { return x; }
	float getY() { return y; }
	void draw(void)
	{
		glPointSize(2.0);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
		glEnable(GL_POINT_SMOOTH);

		glBegin(GL_POINTS); // draw this point
		glVertex2f((GLfloat)x, (GLfloat)y);
		glEnd();

		glDisable(GL_POINT_SMOOTH);

	}// end draw
private:
	float x, y;
}; // end class Point2




class Spider
{
public:

	RGBApixmap pix[2]; // make six empty pixmaps, one for each side of cube
	enum State { LIVE, DIE }state;
	//enum ModeType { STAY, RUN, JUMP, DEAD } mode;
	float pos_X, pos_Y;
	bool ismoving;
	float isspeed;
	float theta;
	float rate_of_change;
	//bool isAlive = true;
	float Spider_getX()
	{
		return pos_X;
	}
	float Spider_getY()
	{
		return pos_Y;
	}
	Spider() {}

	Spider(Point2 pos)
	{
		ismoving = true;
		//isspeed = 4000.0f;
		isspeed = 0.01f;
		//theta = 0.0;
		//rate_of_change = 1.0;
		pos_X = 0.0;
		pos_Y = 0.0;

		//string fname[2] = {"spider.bmp","mak3.bmp"};
		pix[0].readBMPFile("spider.bmp", 1);
		pix[1].readBMPFile("mak3.bmp", 1);  // read texture for side 1 from image

		for (int i = 0; i < 2; i++)
		{
			//this->pix[i].readBMPFile();
			pix[i].setChromaKey(192, 192, 192);
		}

		this->pos_X = pos.getX();
		this->pos_Y = pos.getY();


	};

	void changePosition(float dx, float dy)
	{
		this->pos_X += dx;  this->pos_Y += dy;
	}

	void startMoving()
	{
		ismoving = true;
		glutTimerFunc(100, moveSpider, 0); // Call moveSpider function after 100ms
	}

	static void moveSpider(int value)
	{
		Spider* spider = reinterpret_cast<Spider*>(value);

		if (spider && spider->ismoving && spider->pos_X <= 600)
		{
			spider->pos_X += spider->isspeed;
			glutPostRedisplay(); // Request a redraw
			glutTimerFunc(100, moveSpider, 2); // Call moveSpider again after 100ms
		}
	}

	/*
	void startMoving() {
		ismoving = true;
		glutTimerFunc(100, moveSpider, 0); // Calls moveSpider function after 100ms
	}

	static void moveSpider(int value) {
		Spider* spider = reinterpret_cast<Spider*>(value);
		//spider->pix[0].mDraw();

		if (spider && spider->ismoving && spider->pos_X <= 600) {
			spider->pos_X += 10; // Move the spider horizontally
			//glRasterPos2i(spider->pos_X,spider->pos_Y);
			//spider->pix[0].mDraw();
			glutPostRedisplay(); // Request a redraw
			glutTimerFunc(100, moveSpider, value); // Call moveSpider again after 100ms
		}
	}
	*/

	void render();
	//void die();

};



void Spider::render()
{
	glRasterPos2i(this->pos_X, this->pos_Y);
	//pix[0].mDraw();
	if (this->ismoving)
	{
		//glRasterPos2i(this->pos_X, this->pos_Y);
		pix[0].mDraw();
		//startMoving();
		//moveSpider(10);
	}
	else if (!this->ismoving)
	{
		pix[1].mDraw();
	}

	//int j = 20;
	//while (this->ismoving && this->pos_X <= 600)
	//{
		//this->pos_X = this->pos_X + j;
		//glRasterPos2i(this->pos_X, this->pos_Y);
		//pix[0].mDraw();
		//j += 10;
		//glFlush();
		//glutPostRedisplay();
		//this->ismoving = false;
	//}
	//pix[1].mDraw();
}

class Bullet
{
public:
	float bullet_Xmin, bullet_Xmax, bullet_Ymin, bullet_Ymax;

	Bullet(float xmin, float xmax, float ymin, float ymax)
	{
		bullet_Xmin = xmin;
		bullet_Xmax = xmax;
		bullet_Ymin = ymin;
		bullet_Ymax = ymax;
	}

	void render()
	{
		/*
		glColor3f(1.0, 0.8, 0.0);
		//glPointSize(10.0);
		glBegin(GL_QUAD_STRIP);
		glVertex2i(300, 5);
		glVertex2i(310, 5);
		glVertex2i(300, 30);
		glVertex2i(310, 30);
		glEnd();

		glColor3f(1.0, 0.8, 0.0);
		glBegin(GL_TRIANGLES);
		glVertex2i(300, 30);
		glVertex2i(305, 40);
		glVertex2i(310, 30);
		glEnd();

		glFlush();
		//glutPostRedisplay();
		//glutSwapBuffers();
		*/

		glColor3f(1.0, 0.8, 0.0);
		glBegin(GL_QUAD_STRIP);
		glVertex2i(this->bullet_Xmin, this->bullet_Ymin);
		glVertex2i(this->bullet_Xmax, this->bullet_Ymin);
		glVertex2i(this->bullet_Xmin, this->bullet_Ymax);
		glVertex2i(this->bullet_Xmax, this->bullet_Ymax);
		glEnd();

		glColor3f(1.0, 0.8, 0.0);
		glBegin(GL_TRIANGLES);
		glVertex2i(this->bullet_Xmin, this->bullet_Ymax);
		glVertex2i((this->bullet_Xmin + this->bullet_Xmax)/2,  this->bullet_Ymax + 10);
		glVertex2i(this->bullet_Xmax, this->bullet_Ymax);
		glEnd();
	}

	void setPosition(float xmin, float xmax, float ymin, float ymax)
	{
		this->bullet_Xmin = xmin;
		this->bullet_Xmax = xmax;
		this->bullet_Ymin = ymin;
		this->bullet_Ymax = ymax;
	}

	void changePosition(float dxmin, float dxmax, float dymin, float dymax)
	{
		bullet_Xmin += dxmin;
		bullet_Xmax += dxmax;
		bullet_Ymin += dymin;
		bullet_Ymax += dymax;
	}
};

Point2 pin(280.0f, 400.0f);
Spider m(pin);
Bullet b(300.0,320.0 ,5.0, 30.0);


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
	//m.changeMode(Mario::STAY);

}



void tt(int y)
{
	//m.pos_X = 5.1;
	m.pos_X += m.isspeed;
	glutPostRedisplay();
	glutTimerFunc(100, tt, 1);
}


void timer(int t)
{
	if (m.pos_X <= 5.0)
	{
		glutTimerFunc(100, tt, 1);
	}
	else
	{
		m.pos_X -= m.isspeed;
		glutPostRedisplay();
		glutTimerFunc(100, timer, 1);
	}

}

void myTimer(int value)
{
	if (m.pos_X < 580)
	{
		m.pos_X += m.isspeed;
		glutPostRedisplay();
		
		glutTimerFunc(100, myTimer, 1);
	}

	else if (m.pos_X >= 580)
	{
		
		glutTimerFunc(100, timer, 1);
	}
	
}

void check_collision()
{
	if (m.pos_X < b.bullet_Xmax && m.pos_X > b.bullet_Xmin && m.pos_Y < b.bullet_Ymax && m.pos_Y > b.bullet_Ymin)
	{
		m.pix[1].mDraw();
		m.render();
		glutPostRedisplay();
	}
}

void bulletTimer(int kk)
{
	if (b.bullet_Ymax < 500)
	{
		//check_collision();
		//b.bullet_Ymax += 10.0f;
		b.changePosition(0.0f, 0.0f, 30.0f, 30.0f);
		glutPostRedisplay();
		glutTimerFunc(100, bulletTimer, 1);
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m.render();
	myTimer(4);

	b.render();
	if (m.pos_X >= b.bullet_Xmin && m.pos_X <= b.bullet_Xmax &&
		m.pos_Y >= b.bullet_Ymin && m.pos_Y <= b.bullet_Ymax)
	{
		m.ismoving = false;
		m.render();
	}
	glFlush();
}


void myKeyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		if (b.bullet_Xmin > 8.0)
		{
			b.changePosition(-10.0f, -10.0f, 0.0f, 0.0f);
		}
		break;
	case GLUT_KEY_RIGHT:
		if (b.bullet_Xmax < 635.0)
		{
			b.changePosition(10.0f, 10.0f, 0.0f, 0.0f);
		}
		break;
	case GLUT_KEY_UP:
		
		bulletTimer(4);
		break;
	case GLUT_KEY_DOWN:
		b.setPosition(300.0, 320.0, 5.0, 30.0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("My Spider");

	myInit();
	glutDisplayFunc(display);
	glutSpecialFunc(myKeyboard);

	//sndPlaySound(TEXT("test_music_file.wav"), SND_ASYNC);
	glutMainLoop();

	return 0;
}