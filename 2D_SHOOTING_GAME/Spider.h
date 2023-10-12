#pragma once
#include<GL/glut.h>
//#include<windows.h>
#include "pixmap.h"

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
		isspeed = 4000.0f;
		theta = 0.0;
		rate_of_change = 1.0;
		//pos_X = 0.0;
		//pos_Y = 0.0;

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

	void render();
	//void die();

};



void Spider::render()
{
	/*
	switch (state)
	{

	case DIE:
		glRasterPos2i(this->pos_X, this->pos_Y);
		//glRasterPos2i(this->pos_X, this->pos_Y);
		pix[1].mDraw();
		//state = LIVE;
		break;
	case LIVE:
		//while (this->pos_X < 600)
		//{
			//changePosition(this->pos_X + 30, this->pos_Y);
			//glRasterPos2i(this->pos_X + 40, this->pos_Y);
			//pix[0].mDraw();
		//}
		glRasterPos2i(this->pos_X, this->pos_Y);
		pix[0].mDraw();
		//state = DIE;
		break;
	}
	*/

	if (this->ismoving)
	{
		glRasterPos2i(this->pos_X, this->pos_Y);
		pix[0].mDraw();
		//startMoving();
		//moveSpider(10);
	}
	else
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