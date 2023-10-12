#include<GL/glut.h>
#include<cmath>

class Canvas {
public:
	float x, y;
	float angle;
	Canvas() {
		this->x = 225;
		this->y = 200;
	}
	void turnTo(float angle) {
		this->angle = angle;
	}
	void turn(float angle) {
		this->angle += angle;
	}
	void lineTo(float x, float y) {
		float t_x = x; float t_y = y;
		glColor3f(0.0, 0.0, 0.0);
		glLineWidth(2.0);
		glBegin(GL_LINES);
		glVertex2f(this->x, this->y);
		glVertex2f(x, y);
		glEnd();
		glFlush();
		moveTo(t_x, t_y);
	}
	void moveTo(float x, float y) {
		this->x = x;
		this->y = y;

	}

	void scale2D(double sx, double sy)
	{
		glMatrixMode(GL_MODELVIEW);
		glScaled(sx, sy, 1.0);
	}

	void rotate2D(double angle)
	{
		glMatrixMode(GL_MODELVIEW);
		glRotated(angle, 00, 0.0, 1.0);
	}

	void forward(float dist, int isVisible) {
		const float RadPerDeg = 0.017453393;
		float x = this->x + dist * cos(RadPerDeg * this->angle);
		float y = this->y + dist * sin(RadPerDeg * this->angle);
		if (isVisible >= 1) {
			lineTo(x, y);
		}
		else {
			moveTo(x, y);
		}
	}
};


/*void scale2D(double sx, double sy)
{
	glMatrixMode(GL_MODELVIEW);
	glScaled(sx,sy,1.0);
}

void rotate2D(double angle)
{
	glMatrixMode(GL_MODELVIEW);
	glRotated(angle, 00, 0.0, 1.0);
}*/