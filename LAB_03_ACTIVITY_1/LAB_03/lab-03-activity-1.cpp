#include "Dino.h"

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawPolyLineFile("dino.dat");

    glutSwapBuffers();
}