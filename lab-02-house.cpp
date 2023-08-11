#include<windows.h>
#include<GL/glut.h>

void init() {
    // DISPLAY WINDOW COLOR
    glClearColor(0.5, 0.9, 0.4, 0.0);
    //glClearColor(0.3, 0.5, 0.6, 0.0);

    // PROJECTION PARAMETER
    glMatrixMode(GL_PROJECTION);

    // 2D TRANSFORMATION
    gluOrtho2D(0.0, 800, 0.0, 600);
}

void home() {

    glClear(GL_COLOR_BUFFER_BIT);

    // MOUNTAINS


    // SET ROOF
    glColor3f(0.3, 0.5, 0.8);
    //glColor3f(0.7, 0.3, 0.0);

    glBegin(GL_POLYGON);

    glVertex2i(200, 500);
    glVertex2i(600, 500);
    glVertex2i(700, 350);
    glVertex2i(300, 350);

    glEnd();


    // FRONT ROOF TOP
    glColor3f(0.5, 0.2, 0.0);

    glBegin(GL_TRIANGLES);

    glVertex2i(200, 500);
    glVertex2i(100, 350);
    glVertex2i(300, 350);

    glEnd();


    // FRONT WALL
    //glColor3f(0.1, 0.3, 0.4);
    glColor3f(0.1, 0.2, 0.3);

    glBegin(GL_POLYGON);

    glVertex2i(100, 350);
    glVertex2i(300, 350);
    glVertex2i(300, 100);
    glVertex2i(100, 100);

    glEnd();


    // SIDE WALL
    //glColor3f(0.1, 0.2, 0.3);
    glColor3f(0.1, 0.3, 0.4);

    glBegin(GL_POLYGON);

    glVertex2i(300, 350);
    glVertex2i(700, 350);
    glVertex2i(700, 100);
    glVertex2i(300, 100);

    glEnd();


    // DOOR
    glColor3f(0.5, 0.2, 0.0);

    glBegin(GL_POLYGON);

    glVertex2i(150, 250);
    glVertex2i(250, 250);
    glVertex2i(250, 100);
    glVertex2i(150, 100);

    glEnd();



    // HANDLE
    glColor3f(0.3, 0.5, 0.8);

    glBegin(GL_POLYGON);

    glVertex2i(160, 180);
    glVertex2i(170, 180);
    glVertex2i(170, 170);
    glVertex2i(160, 170);

    glEnd();

    // ROAD
    glColor3f(0.0, 0.0, 0.0);

    //glLineWidth(280.0);
    glBegin(GL_POLYGON_BIT);

    glVertex2i(0, 0);
    glVertex2i(900, 0);
    glVertex2i(0, 50);
    glVertex2i(900, 50);

    glEnd();

    // ROAD
    // glColor3f(0.3, 0.5, 0.6);
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_POLYGON);

    glVertex2i(150, 100);
    glVertex2i(250, 100);
    glVertex2i(200, 50);
    glVertex2i(60, 50);

    glEnd();

    // LINE
    glColor3f(1.0, 1.0, 1.0);

    glLineWidth(4.0);
    glBegin(GL_LINES);

    glVertex2i(10, 25);
    glVertex2i(30, 25);

    glVertex2i(70, 25);
    glVertex2i(90, 25);

    glVertex2i(130, 25);
    glVertex2i(150, 25);

    glVertex2i(190, 25);
    glVertex2i(210, 25);

    glVertex2i(250, 25);
    glVertex2i(270, 25);

    glVertex2i(310, 25);
    glVertex2i(330, 25);

    glVertex2i(370, 25);
    glVertex2i(390, 25);

    glVertex2i(430, 25);
    glVertex2i(450, 25);

    glVertex2i(490, 25);
    glVertex2i(510, 25);

    glVertex2i(550, 25);
    glVertex2i(570, 25);

    glVertex2i(610, 25);
    glVertex2i(630, 25);

    glVertex2i(670, 25);
    glVertex2i(690, 25);

    glVertex2i(730, 25);
    glVertex2i(750, 25);

    glVertex2i(790, 25);
    glVertex2i(810, 25);

    glVertex2i(850, 25);
    glVertex2i(870, 25);

    glEnd();


    // CAR
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_QUAD_STRIP);

    glVertex2i(540, 40);
    glVertex2i(580, 40);
    glVertex2i(540, 80);
    glVertex2i(580, 80);

    glVertex2i(580, 40);
    glVertex2i(670, 40);
    glVertex2i(580, 120);
    glVertex2i(670, 120);

    glVertex2i(670, 40);
    glVertex2i(740, 40);
    glVertex2i(670, 80);
    glVertex2i(740, 80);

    glEnd();

    // CAR TIRES

    glColor3f(1.0, 1.0, 0.0);

    // FIRST TIRE
    glPushMatrix();
    glTranslatef(590, 40, 150);
    glutSolidSphere(150, 50, 50);
    glPopMatrix();

    // SECOND TIRE
    glPushMatrix();
    glTranslatef(690, 40, 150);
    glutSolidSphere(150, 50, 50);
    glPopMatrix();


    // WINDOW 350 - 700 X - AXIS 350 - 100 Y - AXIS

    glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_QUAD_STRIP);

    glVertex2i(450, 290);
    glVertex2i(600, 290);
    glVertex2i(450, 180);
    glVertex2i(600, 180);

    glEnd();



    // LINES

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(3.0);

    glBegin(GL_LINES);

    glVertex2i(525, 180);
    glVertex2i(525, 290);
    glVertex2i(450, 235);
    glVertex2i(600, 235);

    glEnd();



    // TREE STEM

    glColor3f(0.5, 0.2, 0.0);

    glBegin(GL_QUADS);

    glVertex2i(730, 130);
    glVertex2i(760, 130);
    glVertex2i(760, 385);
    glVertex2i(730, 385);

    glEnd();

    // TREE LEAVES

    glColor3f(0.0, 0.9, 0.0);

    glBegin(GL_TRIANGLES);

    glVertex2i(650, 385);
    glVertex2i(820, 385);
    glVertex2i(745, 600);

    glEnd();


    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1000, 600);

    glutCreateWindow("2D House in OPENGL using C++");

    init();
    glutDisplayFunc(home);

    glutMainLoop();
}