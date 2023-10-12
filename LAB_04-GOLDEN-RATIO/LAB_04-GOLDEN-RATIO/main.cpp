#include <GL/glut.h>
#include <cmath>

// Function to draw a rectangle
void drawRectangle(float x, float y, float width, float height) {
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);  //(0 , 14.59)  (229.18 , 14.59)  (229.18 , 243.77)
	glVertex2f(x + width, y);  //(600.0, 14.59)  (458.36 , 14.59)  (458.36 , 243.77)
	glVertex2f(x + width, y + height);  //(600.0 , 385.41) (458.36 , 385.41)  (458.36 , 385.41)
	glVertex2f(x, y + height);  //(0 , 385.41)  (229.18 , 385.41)  (229.18 , 385.41)
	glEnd();
}

// Function to draw the regression of golden rectangles
void drawGoldenRectangles(float x, float y, float width, float height, int depth) {
	if (depth <= 0 || width < 1 || height < 1) {
		return;
	}

	drawRectangle(x, y, width, height);  // (0 , 14.59 , 600.0 , 370.82)  (229.18 , 14.59 , 229.18 , 370.82)
										// (229.18 , 243.77 , 229.18 , 141.64)
										// (141.6 , 0 , 458.4 , 300)

	float nextX, nextY, nextWidth, nextHeight;

	if (width / height > 1.618) {
		nextWidth = width - height;  // 229.18
		nextHeight = height;  // 370.82
		nextX = x + nextWidth;  // 229.18
		nextY = y;  // 14.59
	}
	else {
		nextWidth = width;  // 229.18
		nextHeight = width / 1.618;  // 141.64
		nextX = x;  // 229.18
		nextY = y + (height - nextHeight);  // 243.77
	}

	drawGoldenRectangles(nextX, nextY, nextWidth, nextHeight, depth - 1);  // (229.18 , 14.59 , 229.18 , 370.82 , 14)
																		// (229.18 , 243.77 , 229.18 , 141.64 , 13)
}

// Display callback function
void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f); // Set color to black

	int depth = 15; // Number of iterations for the regression
	float initialWidth = 600.0f;
	float initialHeight = 400.0f;
	//float initialHeight = 300.0f;

	float x = 0;
	float y = 0;

	// Calculate the largest golden rectangle that fits within the screen
	float largestWidth, largestHeight;
	if (initialWidth / initialHeight > 1.618) {
		largestWidth = initialHeight * 1.618;  // 485.4
		largestHeight = initialHeight;  // 300.0
	}
	else {
		largestWidth = initialWidth;  // 600.0
		largestHeight = initialWidth / 1.618;  // 370.82
	}

	x = (initialWidth - largestWidth) / 2;  // 0  // 141.6
	y = (initialHeight - largestHeight) / 2;  // 14.59  // 0

	drawGoldenRectangles(x, y, largestWidth, largestHeight, depth);  // (0 , 14.59 , 600.0 , 370.82 , 15)
																	 // (141.6 , 0 , 458.4 , 300.0 , 15)

	glFlush();
}

// Reshape callback function
void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 400);
	glutCreateWindow("Golden Ratio Rectangles ");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
