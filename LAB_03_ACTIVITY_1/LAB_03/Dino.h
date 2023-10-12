#pragma once
#include<GL/glut.h>

void drawPolyLineFile(const char* fileName);
void setWindow(int xs, int xe, int ys, int ye);
void setViewport(GLint left, GLint right, GLint bottom, GLint top);
void myInit(void);
void myDisplay(void);
void zoom_in();
void zoom_out();
void keyboard(unsigned char key, int x, int y);
int main(int argc, char** argv);