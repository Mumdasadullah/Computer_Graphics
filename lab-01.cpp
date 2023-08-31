#include<istream>
#include<fstream>
#include<string>
#include<GL/glut.h>
#include<windows.h>
#include<mmsystem.h>
using namespace std;

int screenWidth = 640;
int screenHeight = 480;
float minX = -10;
float minY = -10;
float maxX = 10;
float maxY = 10;
int VP_bottom = 0;
int VP_left = 0;
int VP_width = 640;
int VP_height = 480;
bool drawMountainFlag = false;


GLfloat mountainVertices[] = {
    -10.0f, -10.0f,
    0.0f, 10.0f,
    10.0f, -10.0f
};

void drawMountain()
{
    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 6; i += 2) {
        glVertex2f(mountainVertices[i], mountainVertices[i + 1]);
    }
    glEnd();
}


void drawAxis()
{
    glBegin(GL_LINES);
    glVertex2f(minX, 0);
    glVertex2f(maxX, 0);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0, minY);
    glVertex2f(0, maxY);
    glEnd();

}


void bitmap_output(int x, int y, string s, void* font)
{
    int len, i;
    glRasterPos2f(x, y);
    len = s.length();
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, s[i]);
    }

}


void myInit()
{
    glClearColor(0.9f, 0.9f, 0.9, 0.0);
    glColor3f(1, 0, 0);
}

void myReshape(int w, int h)
{
    screenWidth = w;
    screenHeight = h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myMotion(int x, int y)
{
    glutPostRedisplay();
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (drawMountainFlag)
    {
        drawMountain();
    }

    glColor3f(1, 0, 0);
    bitmap_output(40, 230, "This is written in a GLUT bitmap font", GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(1, 0, 0);
    bitmap_output(30, 210, "More bitmap text is a forced 9 by 15 font", GLUT_BITMAP_9_BY_15);

    glColor3f(0, 1, 0);
    bitmap_output(70, 35, "Helvetica is yet another bitmap font", GLUT_BITMAP_HELVETICA_18);

    glViewport(VP_left, VP_bottom, VP_width, VP_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(minX, maxX, minY, maxY);
    drawAxis();

    glFlush();
}

void drawDot(int x, int y)
{
    glPointSize(25.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}


void myMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        drawDot(mx, screenHeight - my);
    }

    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        // glClear(GL_COLOR_BUFFER_BIT);
        exit(0);
    }
    glutPostRedisplay();
}

void myKeyboard(unsigned char key, int x, int y)
{
    // switch (key)
    // {
    // case 'q': exit(0);
    // case 'f': glClearColor(0.2, 0.4, 0.3, 0.0);
    // case 's': glutFullScreen();
    // case 'm':
    //     drawMountainFlag = !drawMountainFlag;
    //     glutPostRedisplay();
    //     break;
    // case 'c':
    //     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //     glutPostRedisplay();
    //     break;
    // default:
    //     break;
    // }

    if (key == 'q')
    {
        exit(0);
    }
    else if (key == 'f')
    {
        glClearColor(0.2, 0.4, 0.3, 0.0);
    }
    else if (key == 's')
    {
        glutFullScreen();
    }
    else if (key == 'm')
    {
        drawMountainFlag = !drawMountainFlag;
    }
    else if (key == 'c')
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }



    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("Experiment with images");

    glutReshapeFunc(myReshape);
    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
    glutKeyboardFunc(myKeyboard);
    glutMotionFunc(myMotion);
    myInit();

    //PlaySound(TEXT("test_music_file.wav"), NULL, SND_SYNC);
    glutMainLoop();

    return 0;
}