#include "Canvas.h"

#include <GL/glut.h>
//#include <iostream>
//#include <fstream>
#include <math.h>


//#define M_PI  3.14157

// display

using namespace std;

Canvas cvs(640, 480, "Test Canvas Class for Task 8");



void display(void)
{
    //cvs.setBackgroundColor(1.0, 1.0, 1.0); //background color is white 
    cvs.clearScreen(); //clear screen

    //cvs.setColor(1.0, 0.0, 0.0); //drawing color is red 
    cvs.setWindow(-10.0, 10.0, -10.0, 10.0);
    cvs.setViewport(10, 460, 10, 460);

    // ***************PRACTICING Simple Line DRAWING************//

       // call moveTo() and lineTo();

     // ***************END RELATIVE DRAWING*********************//
        cvs.moveTo(0,-10.0);
        cvs.lineTo(0,10.0);

    Triangle triangle(0.0, 7.0, 6.0, -1.5);

    //glPointSize(2.0);

    triangle.draw();

    RealRect box(-2.0, 2.0, -1.0, 1.0);
    glLineWidth(2.0);
    box.draw();

    glFlush();
}// end display





int main(int argc, char** argv)
{
    cvs.setBackgroundColor(1.0, 1.0, 1.0);

    cvs.setColor(0.0, 0.0, 0.0);
    // the window is opened in the Canvas constructor
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}//end main