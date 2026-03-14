#include <GL/glut.h>

void drawLineStrip()
{
    glColor3f(1,0,0);

    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.9,0.7);
        glVertex2f(-0.7,0.9);
        glVertex2f(-0.5,0.7);
        glVertex2f(-0.3,0.9);
    glEnd();
}

void drawLineLoop()
{
    glColor3f(0,1,0);

    glBegin(GL_LINE_LOOP);
        glVertex2f(0.3,0.7);
        glVertex2f(0.5,0.9);
        glVertex2f(0.7,0.7);
        glVertex2f(0.6,0.5);
        glVertex2f(0.4,0.5);
    glEnd();
}

void drawTriangleFan()
{
    glColor3f(1,1,0);

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.7,0.2);
        glVertex2f(-0.8,0.0);
        glVertex2f(-0.6,0.0);
        glVertex2f(-0.55,0.15);
        glVertex2f(-0.65,0.3);
    glEnd();
}

void drawTriangleStrip()
{
    glColor3f(1,0,1);

    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.2,0.2);
        glVertex2f(-0.1,0.0);
        glVertex2f(0.0,0.2);
        glVertex2f(0.1,0.0);
        glVertex2f(0.2,0.2);
    glEnd();
}

void drawQuadStrip()
{
    glColor3f(0,1,1);

    glBegin(GL_QUAD_STRIP);
        glVertex2f(0.5,0.2);
        glVertex2f(0.5,0.0);

        glVertex2f(0.65,0.2);
        glVertex2f(0.65,0.0);

        glVertex2f(0.8,0.2);
        glVertex2f(0.8,0.0);
    glEnd();
}

void drawCubes()
{
    glColor3f(0.3,0.6,0.9);

    glBegin(GL_QUADS);

    glVertex2f(-0.6,-0.4);
    glVertex2f(-0.3,-0.4);
    glVertex2f(-0.3,-0.1);
    glVertex2f(-0.6,-0.1);

    glVertex2f(-0.2,-0.4);
    glVertex2f(0.1,-0.4);
    glVertex2f(0.1,-0.1);
    glVertex2f(-0.2,-0.1);

    glVertex2f(0.2,-0.4);
    glVertex2f(0.5,-0.4);
    glVertex2f(0.5,-0.1);
    glVertex2f(0.2,-0.1);

    glVertex2f(-0.45,-0.05);
    glVertex2f(-0.15,-0.05);
    glVertex2f(-0.15,0.25);
    glVertex2f(-0.45,0.25);

    glVertex2f(0.05,-0.05);
    glVertex2f(0.35,-0.05);
    glVertex2f(0.35,0.25);
    glVertex2f(0.05,0.25);

    glEnd();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawLineStrip();
    drawLineLoop();
    drawTriangleFan();
    drawTriangleStrip();
    drawQuadStrip();
    drawCubes();

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(700,700);
    glutCreateWindow("Tugas 1");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}
