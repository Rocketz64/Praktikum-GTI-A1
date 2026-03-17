#include <gl/glut.h>
#include <math.h>

void Mobil(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    glTranslatef(0.85, -0.45, 0.0);
    glRotated(45.0, 0.0, 0.0, 1.0);
    	glColor3f(0.0f, 0.5f, 0.0f);
    	glRectf(-0.75, 0.75, 0.75, -0.75);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0, -0.9, 0.0);
    	glColor3f(0.25f, 0.25f, 0.25f);
    	glRectf(-1.0, 0.5, 1.0, -0.5);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.75, -0.7, 0.0);
    	glColor3f(1.0f, 1.0f, 0.0f);
    	glRectf(-0.25, 0.05, 0.25, -0.05);
    glPopMatrix();

	glPushMatrix();
    glTranslatef(0.0, -0.7, 0.0);
    	glColor3f(1.0f, 1.0f, 0.0f);
    	glRectf(-0.25, 0.05, 0.25, -0.05);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.75, -0.7, 0.0);
    	glColor3f(1.0f, 1.0f, 0.0f);
    	glRectf(-0.25, 0.05, 0.25, -0.05);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0, 0.15, 0.0);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-0.60f, -0.60f, 0.00f);
        
        glVertex3f(0.60f, -0.60f, 0.00f);
        
        glVertex3f(0.00f, -0.10f, 0.00f);
    glEnd();
    glPopMatrix();

	glPushMatrix();
    glTranslatef(-0.3, -0.2, 0.0);
    glRotated(85.5, 0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-0.10f, -0.10f, 0.00f);
        
        glVertex3f(0.10f, -0.10f, 0.00f);
        
        glVertex3f(-0.10f, 0.10f, 0.00f);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.4, -0.6, 0.0);
    	glColor3f(0.5f, 0.5f, 0.5f);
    	float r = 0.15f;
    	int n = 100;
    	float pi = 3.14159265f;
    	glBegin(GL_POLYGON);
    	for (int i = 0; i < n; i++){
        	float sudut = 2.0f * pi * i / n;
        	glVertex2f(r * cos(sudut), r * sin(sudut));
    	}
    	glEnd();
    glPopMatrix();

	glPushMatrix();
    glTranslatef(0.4, -0.6, 0.0);
    	glColor3f(0.5f, 0.5f, 0.5f);
    	float r2 = 0.15f;
    	int n2 = 100;
    	float pi2 = 3.14159265f;
    	glBegin(GL_POLYGON);
    	for (int i = 0; i < n; i++){
        	float sudut = 2.0f * pi * i / n;
        	glVertex2f(r * cos(sudut), r * sin(sudut));
    	}
    	glEnd();
    glPopMatrix();

	glPushMatrix();
    glTranslatef(-0.4, -0.6, 0.0);
    	glColor3f(0.75f, 0.75f, 0.75f);
    	float r4 = 0.05f;
    	int n4 = 100;
    	float pi4 = 3.14159265f;
    	glBegin(GL_POLYGON);
    	for (int i = 0; i < n4; i++){
        	float sudut = 2.0f * pi4 * i / n4;
        	glVertex2f(r4 * cos(sudut), r4 * sin(sudut));
    	}
    	glEnd();
    glPopMatrix();

	glPushMatrix();
    glTranslatef(0.4, -0.6, 0.0);
    	glColor3f(0.75f, 0.75f, 0.75f);
    	float r5 = 0.05f;
    	int n5 = 100;
    	float pi5 = 3.14159265f;
    	glBegin(GL_POLYGON);
    	for (int i = 0; i < n5; i++){
        	float sudut = 2.0f * pi5 * i / n5;
        	glVertex2f(r5 * cos(sudut), r5 * sin(sudut));
    	}
    	glEnd();
    glPopMatrix();

	glPushMatrix();
    glTranslatef(-0.75, 0.75, 0.0);
    	glColor3f(1.0f, 1.0f, 0.0f);
    	float r3 = 0.15f;
    	int n3 = 100;
    	float pi3 = 3.14159265f;
    	glBegin(GL_POLYGON);
    	for (int i = 0; i < n; i++){
        	float sudut = 2.0f * pi * i / n;
        	glVertex2f(r * cos(sudut), r * sin(sudut));
    	}
    	glEnd();
    glPopMatrix();
    
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Mobil");
    glutDisplayFunc(Mobil);
    glClearColor(0.53f, 0.81f, 0.92f, 1.0f);
    glutMainLoop();
    return 0;
}
