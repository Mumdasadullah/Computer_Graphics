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

void myDisplay(void)
{
    //float t[10]
    glBegin(GL_LINES);
    for (int i = 0; i < 8; i++)
    {
        glVertex2f(40,60);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1000, 600);

    glutCreateWindow("2D House in OPENGL using C++");

    init();
    glutDisplayFunc(myDisplay);

    glutMainLoop();
}