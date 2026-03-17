#include <gl/glut.h>
#include <math.h>

void Lingkaran(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);

    float r = 0.5f;
    int n = 100;
    float pi = 3.14159265f;

    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
    {
        float sudut = 2.0f * pi * i / n;
        glVertex2f(r * cos(sudut), r * sin(sudut));
    }
    glEnd();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Lingkaran");
    glutDisplayFunc(Lingkaran);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
