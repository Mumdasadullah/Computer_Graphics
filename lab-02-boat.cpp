#include<windows.h>
#include<GL/glut.h>
#include<math.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2.0);

    glBegin(GL_POLYGON);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);

    glVertex2f(-6, 2);
    glVertex2f(6, 2);
    glVertex2f(-4, -2);
    glVertex2f(4, -2);

    glVertex2f(-6, 2);
    glVertex2f(-4, -2);
    glVertex2f(6, 2);
    glVertex2f(4, -2);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(1, 1, 1);

    glVertex2f(-4, 3);
    glVertex2f(-4, 5);

    glVertex2f(-4, 3);
    glVertex2f(-3, 2);

    glVertex2f(-4, 3);
    glVertex2f(-5, 2);

    glVertex2f(-4, 5);
    glVertex2f(-2, 4);

    glVertex2f(-4, 5);
    glVertex2f(-5, 4);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 1, 1);

    glVertex2f(-3, 5);
    glVertex2f(0, -3);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 1, 1);

    glVertex2f(5, 2);
    glVertex2f(5, 7);
    glVertex2f(5, 7);
    glVertex2f(0.5, 2);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.5, 0.5);

    glVertex2f(5, 7);
    glVertex2f(6, 7);
    glVertex2f(5, 6);
    glVertex2f(6, 7);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 1, 1);

    glVertex2f(4, -5);
    glVertex2f(6, -5);

    glVertex2f(5, -2);
    glVertex2f(8, -2);

    glVertex2f(6, -3);
    glVertex2f(9, -3);

    glVertex2f(-5, -2);
    glVertex2f(-7, -2);

    glVertex2f(-4, -3);
    glVertex2f(-6, -3);

    glVertex2f(-2, -5);
    glVertex2f(-4, -5);

    glVertex2f(-3, -4);
    glVertex2f(0, -4);

    glVertex2f(1, -3);
    glVertex2f(4, -3);

    glEnd();

    glTranslatef(-4, 5.5, 0);
    glScalef(0.5, 0.5, 0.5);

    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);

    for (int i = 0; i < 1000; i++)
    {
        glVertex3f(cos(2 * 3.14159 * i / 1000.0), sin(2 * 3.14159 * i / 1000.0), 1);
    }
    glEnd();

    glFlush();

}

void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("boat");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
}