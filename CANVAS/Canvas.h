#include <GL/glut.h>
class Point2
{
public:
    Point2() { x = y = 0.0f; };// constructor 1
    Point2(float xx, float yy) { x = xx; y = yy; }; // constructor 2
    void set(float xx, float yy) { x = xx; y = yy; }
    float getX() { return x; }
    float getY() { return y; }
    void draw(void)
    {
        glBegin(GL_POINTS); // draw this point
        glVertex2f((GLfloat)x, (GLfloat)y);
        glEnd();
    }// end draw
private:
    float x, y;
}; // end class Point2

class IntRect
{
public:
    IntRect() { l = 0; r = 100; b = 0; t = 100; } // constructors
    IntRect(int left, int right, int bottom, int top)
    {
        l = left; r = right; b = bottom; t = top;
    } // constructors
    void set(int left, int right, int bottom, int top)
    {
        l = left; r = right; b = bottom; t = top;
    }
    int getl() { return l; }
    int getr() { return r; }
    int getb() { return b; }
    int gett() { return t; }
    void draw(void); // draw this rectangle using OpenGL
private:
    int l, r, b, t;
}; //end class IntRect:

void IntRect::draw(void)
{
    glBegin(GL_LINE_LOOP);
    glVertex2i(l, b);
    glVertex2i(r, b);
    glVertex2i(r, t);
    glVertex2i(l, t);
    glEnd();
}// end IntRect::draw

class RealRect
{
public:
    RealRect() { l = 0; r = 100; b = 0; t = 100; } // constructors
    RealRect(float left, float right, float bottom, float top)
    {
        l = left; r = right; b = bottom; t = top;
    } // constructors
    void set(float left, float right, float bottom, float top)
    {
        l = left; r = right; b = bottom; t = top;
    }
    float getl() { return l; }
    float getr() { return r; }
    float getb() { return b; }
    float gett() { return t; }
    void draw(void); // draw this rectangle using OpenGL
private:
    float l, r, b, t;
}; //end class RealRect:
void RealRect::draw(void)
{
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(l, b);
    glVertex2f(r, b);
    glVertex2f(r, t);
    glVertex2f(l, t);
    glEnd();
}// end RealRect

//glVertex2i(200, 500);
//glVertex2i(100, 350);
//glVertex2i(300, 350);

class Triangle
{
public:
    Triangle()
    {
        w = 0.0;
        x = 0.0;
        y = 0.0;
        z = 0.0;
    }
    Triangle(float ww, float xx, float yy, float zz)
    {
        w = ww;
        x = xx;
        y = yy;
        z = zz;
    }
    void set(int left, int right, int bottom, int top)
    {
        int l = left;
        int r = right;
        int b = bottom;
        int t = top;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    int getZ()
    {
        return z;
    }
    void draw()
    {
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_TRIANGLES);
        //glVertex2f(0.0, 7.0);
        //glVertex2f(4.0, -1.5);
        //glVertex2f(-4.0, -1.5);
        glVertex2f(w, x); // w = 0.0 x = 7.0 y = 4.0, z=-1.5
        glVertex2f(y, z);
        glVertex2f(-y, z);
        glEnd();
    }
private:
    float w, x, y, z;
};

class Canvas
{
public:
    Canvas(int width, int height, const char* windowTitle);// constructor
    void setWindow(float l, float r, float b, float t);
    // changed setViewport float to int
    void setViewport(int l, int r, int b, int t);
    void clearScreen();
    void setBackgroundColor(float r, float g, float b);
    void setColor(float r, float g, float b);


    IntRect getViewport(void); // divulge or make known the viewport data
    RealRect getWindow(void); // divulge or make known the window data


    float getWindowAspectRatio(void);
    float getCP_X(void);
    float getCP_Y(void);


    void moveTo(float x, float y);
    void moveTo(Point2 p);

    void lineTo(float x, float y);
    void lineTo(Point2 p);


    // others later
private:
    Point2 CP; // current position in the world
    IntRect viewport; // the current viewport
    RealRect window; // the current window
    Triangle tri;
}; // end class Cavas

//************************ End of file "canvas.h" ***************************




Canvas::Canvas(int width, int height, const char* windowTitle)// constructor
{
    char* argv[1]; // dmmy argument list for glutInit()
    char dummyString[8];
    argv[0] = dummyString; // hook up the pointer
    //char** V;
    int argc = 1; // to satisfy glutInit()

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(20, 20);
    glutCreateWindow(windowTitle); // open the screen window
    //setWindow((int)0, (int)width, (int)0, (int)height);
    //setWindow(0, (float)width, 0, (float)height); //default world window
    //setViewport(0, width, 0, height); //default viewport
    //CP.set(0.0f, 0.0f); //initialize the CP to (0,0)
}//end Canvas constructor

void Canvas::setWindow(float l, float r, float b, float t)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(l, r, b, t); //set the world window
    tri.set(l,r,b,t);
    //window.set(l,r,b,t);
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
}// end setWindow

// Changed float to int in void Canvas
void Canvas::setViewport(int l, int r, int b, int t)
{
    glViewport(l, b, r - l, t - b);
} // end setViewport


void Canvas::clearScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);
}// clearScreen

void Canvas::setBackgroundColor(float r, float g, float b)
{
    glClearColor(r, g, b, 0.0);
}// end setBackgroundColor

void Canvas::setColor(float r, float g, float b)
{
    glColor3f(r, g, b);
}//edn setColor

void Canvas::moveTo(float x, float y)
{
    CP.set(x,y);
}

void Canvas::lineTo(float x, float y)
{
    glBegin(GL_LINES);
    glVertex2f((GLfloat)CP.getX(), (GLfloat)CP.getY());
    glVertex2f((GLfloat)x,(GLfloat)y);
    glEnd();

    CP.set(x, y);
    glFlush();
}

void Canvas::moveTo(Point2 p)
{
    CP.set(p.getX(),p.getY());
}

void Canvas::lineTo(Point2 p)
{
    glBegin(GL_LINES);
        
    glVertex2f((GLfloat)CP.getX(), (GLfloat)CP.getY());
    glVertex2f((GLfloat)p.getX(), (GLfloat)p.getY());

    glEnd();

    CP.set(p.getX(), p.getY());

    glFlush();
}

float Canvas::getCP_X()
{
    return CP.getX();
}

float Canvas::getCP_Y()
{
    return CP.getY();
}

RealRect Canvas::getWindow()
{
    return RealRect(window.getl(),window.getr(),window.getb(),window.gett());
}

IntRect Canvas::getViewport()
{
    return IntRect(viewport.getl(),viewport.getr(),viewport.getb(),viewport.gett());
}