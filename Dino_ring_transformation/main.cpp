#include<GL/glut.h>
#include<iostream>
#include<fstream>
#include<cmath> // for mathematical functions
using namespace std;

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

void initCT(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 300.0, 0.0, 250.0);
}

void scale2D(double sx, double sy)
{
    glMatrixMode(GL_MODELVIEW);
    glScaled(sx, sy, 1.0);
}

void rotate2D(double angle)
{
    glMatrixMode(GL_MODELVIEW);
    glRotated(angle, 0.0, 0.0, 1.0);
}

void translate2D(double dx, double dy)
{
    glMatrixMode(GL_MODELVIEW);
    glTranslated(dx, dy, 0.0); // Z-coordinate should remain 0 for 2D transformations
}

void transformDinoRing()
{
    int num_of_dinos = 12;
    //double radius = 100.0;

    for (int i = 0; i < 12; i++)
    {
        double angle = (i * 360.0 / num_of_dinos);
        //double angle = i * 30.0;
        //double x = radius * cos(angle * 3.141592653589793 / 180.0);
        //double y = radius * sin(angle * 3.141592653589793 / 180.0);

        glPushMatrix();
        //rotate2D(angle);
        rotate2D(angle);
        //glRotated(angle,0.0,0.0,1.0);
        //scale2D(-0.3, 0.3);
        translate2D(100.0, 180.0);
        //translate2D(x, y);
        scale2D(-0.2, 0.2);
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

    initCT();
    glutDisplayFunc(myDisplay);

    glutMainLoop();
    return 0;
}