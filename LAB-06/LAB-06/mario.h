#pragma once
#include<GL/glut.h>
//#include<Windows.h>
#include "PixMap.h"

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




class Mario
{
public:

	RGBApixmap pix[6]; // make six empty pixmaps, one for each side of cube
	enum State { STANDING, RUNNING1, RUNNING2, RUNNING3, JUMPING, DIE }state;
	enum ModeType { STAY, RUN, JUMP, DEAD } mode;
	float pos_X, pos_Y;

	Mario(Point2 pos)

	{
		pix[0].readBMPFile("MarioStanding.bmp", 1);
		pix[1].readBMPFile("MarioRun1.bmp", 1);  // read texture for side 1 from image
		pix[2].readBMPFile("MarioRun2.bmp", 1);
		pix[3].readBMPFile("MarioRun3.bmp", 1);  // read texture for side 1 from image
		pix[4].readBMPFile("MarioJump.bmp", 1);
		pix[5].readBMPFile("MarioDead.bmp", 1);

		for (int i = 0; i < 5; i++)
			pix[i].setChromaKey(192, 192, 192);
		
		
		this->pos_X = pos.getX();
		this->pos_Y = pos.getY();


	};

	void changePosition(float dx, float dy)
	{
		this->pos_X += dx;  this->pos_Y += dy;
	}

	void render();
	void changeMode(ModeType m);
	void run();
	//void stay();
	//void jump();
	//void die();


};



void Mario::render()
{

	switch (mode)
	{

	case STAY:
		glRasterPos2i(this->pos_X, 0);
		//glRasterPos2i(this->pos_X, this->pos_Y);
		pix[0].mDraw();
		break;

	case RUN:

		run();
		//pix[1].mDraw();
		break;

	case JUMP:
		//glRasterPos2i(4, 5);
		glRasterPos2i(this->pos_X, this->pos_Y);
		//jump();
		pix[4].mDraw();
		break;

	case DEAD:
		glRasterPos2i(this->pos_X, 0);
		pix[5].mDraw();
		//Sleep(10);
		//die();
		break;
	}
	changeMode(Mario::mode);
}



void Mario::run()
{




	switch (state)
	{
	//case STANDING:
		//state = RUNNING1;
		//break;

	case RUNNING1:

		state = RUNNING2;
		break;

	case RUNNING2:

		state = RUNNING3;
		break;

	case RUNNING3:

		state = RUNNING1;
		//state = STANDING;
		break;

	}
	changePosition(0, 0);
	glRasterPos2i(this->pos_X, 0);
	pix[state].mDraw();

}

void Mario::changeMode(ModeType m)
{
	if (mode == m)
		return;

	switch (m)
	{
	case STAY:

		state = STANDING;
		break;

	case RUN:

		state = RUNNING1;
		break;

	case JUMP:

		state = JUMPING;
		break;

	case DEAD:
		state = DIE;
		break;

	}

	mode = m;
}
