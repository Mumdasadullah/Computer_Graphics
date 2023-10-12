#include "Turtle.h"
#include<GL/glut.h>
#include<iostream>
#include<fstream>
#include<cmath> // for mathematical functions
using namespace std;


Canvas cvs;

void drawPolyLineFile(const char* fileName)
{
    fstream inStream;

    inStream.open(fileName, ios::in);    // open the file

    if (inStream.fail())
    {
        cout << "can't open it!"; return;
    }

    GLfloat numpolys, numPoints, x, y;
    inStream >> numpolys;                   // read the number of polylines

    for (int j = 0; j < numpolys; j++)  // read each polyline
    {
        inStream >> numPoints;       // number of points in first PolyLine
        glBegin(GL_LINE_STRIP);      // draw the next polyline
        for (int i = 0; i < numPoints; i++)
        {
            inStream >> x >> y;        // read the next x, y pair
            glVertex2f(x, y);
        }
        glEnd();
    }
    inStream.close();
}

void transformDinoRing()
{
    int numMotifs = 12;
    double radius = 300.0;

    for (int i = 0; i < numMotifs; i++)
    {
        double angle = (i * 360.0 / numMotifs);
        //double angle = i * 30.0;
        double x = radius * cos(angle * 3.141592653589793 / 180.0);
        double y = radius * sin(angle * 3.141592653589793 / 180.0);

        glPushMatrix();
        //rotate2D(angle);
        cvs.rotate2D(angle);
        //glRotated(angle,0.0,0.0,1.0);
        //scale2D(-0.3, 0.3);
        cvs.translate2D(100.0, 180.0);
        //cvs.translate2D(x-170, y+80);
        cvs.scale2D(-0.2, 0.2);
        //cvs.scale2D(-0.2, 0.2);
        drawPolyLineFile("dino.dat");
        glPopMatrix();
    }
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //drawPolyLineFile("dino.dat");
    transformDinoRing();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Dino Ring Using Transformation");

    cvs.initCT();
    glutDisplayFunc(myDisplay);

    glutMainLoop();
    return 0;
}


/*void transformDinoRing()
{
    int num_of_dinos = 12;
    double radius = 400.0;

    for (int i = 0; i < 12; i++)
    {
        double angle = (i * 360.0 / num_of_dinos);
        //double angle = i * 30.0;
        double x = radius * cos(angle * 3.141592653589793 / 180.0);
        double y = radius * sin(angle * 3.141592653589793 / 180.0);

        glPushMatrix();
        //rotate2D(20.0);
        //rotate2D(angle);
        //glRotated(angle,0.0,0.0,1.0);
        //translate2D(130.0, 150.0);
        translate2D(x-90, y+140);
        scale2D(-0.4, 0.4);
        drawPolyLineFile("dino.dat");
        glPopMatrix();
    }
}*/