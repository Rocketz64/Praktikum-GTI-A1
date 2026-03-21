#include <GL/glut.h>
static int shoulder = 0, elbow = 0, hand = 0, thumb = 0, index = 0, middle = 0, ring = 0, pinky = 0;
void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}
void display(void) {
    glClear (GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    
    glTranslatef (-1.0, 0.0, 0.0);
    glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);
    
    glPushMatrix();
    glScalef (2.0, 0.4, 1.0);
    glutWireCube (1.0);
    glPopMatrix();
    
    glTranslatef (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);
    
    glPushMatrix();
    glScalef (2.0, 0.4, 1.0);
    glutWireCube (1.0);
    glPopMatrix();
    
    glTranslatef (0.75, 0.0, 0.0);
    glRotatef ((GLfloat) hand, 1.0, 0.0, 0.0);
    glTranslatef (0.75, 0.0, 0.0);
    
    glPushMatrix();
    glScalef (1.0, 1.0, 0.2);
    glutWireCube (1.0);
    glPopMatrix();
    
    //Thumb
    glPushMatrix();
    glTranslatef (-0.2, 0.4, 0.0);
    glRotatef ((GLfloat) thumb, 1.0, 0.0, 0.0);
    glTranslatef (-0.2, 0.4, 0.0);
    
    glPushMatrix();
    glScalef (0.2, 0.75, 0.2);
    glutWireCube (1.0);
    glPopMatrix();
    glPopMatrix();
    
    //Index
    glPushMatrix();
    glTranslatef (0.5, 0.2, 0.0);
    glRotatef ((GLfloat) index, 0.0, 1.0, 0.0);
    glTranslatef (0.5, 0.2, 0.0);
    
    glPushMatrix();
    glScalef (0.75, 0.2, 0.2);
    glutWireCube (1.0);
    glPopMatrix();
    glPopMatrix();
    
    //Middle
    glPushMatrix();
    glTranslatef (0.52, 0.05, 0.0);
    glRotatef ((GLfloat) middle, 0.0, 1.0, 0.0);
    glTranslatef (0.52, 0.05, 0.0);
    
    glPushMatrix();
    glScalef (0.85, 0.2, 0.2);
    glutWireCube (1.0);
    glPopMatrix();
    glPopMatrix();
    
    //Ring
    glPushMatrix();
    glTranslatef (0.51, -0.1, 0.0);
    glRotatef ((GLfloat) ring, 0.0, 1.0, 0.0);
    glTranslatef (0.51, -0.1, 0.0);
    
    glPushMatrix();
    glScalef (0.8, 0.2, 0.2);
    glutWireCube (1.0);
    glPopMatrix();
    glPopMatrix();
    
    //Pinky
    glPushMatrix();
    glTranslatef (0.45, -0.25, 0.0);
    glRotatef ((GLfloat) pinky, 0.0, 1.0, 0.0);
    glTranslatef (0.45, -0.25, 0.0);
    
    glPushMatrix();
    glScalef (0.5, 0.2, 0.2);
    glutWireCube (1.0);
    glPopMatrix();
    glPopMatrix();
    
    glPopMatrix();
    
    glutSwapBuffers();
}
void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glTranslatef (0.0, 0.0, -5.0);
}
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 's': shoulder = (shoulder + 5) % 360;
        glutPostRedisplay();
        break;
    case 'S': shoulder = (shoulder - 5) % 360;
        glutPostRedisplay();
        break;
    case 'e': elbow = (elbow + 5) % 360;
        glutPostRedisplay();
        break;
    case 'E': elbow = (elbow - 5) % 360;
        glutPostRedisplay();
        break;
    case 'h': hand = (hand + 5) % 360;
        glutPostRedisplay();
        break;
    case 'H': hand = (hand - 5) % 360;
        glutPostRedisplay();
        break;
    case 't': thumb = (thumb + 5) % 360;
        glutPostRedisplay();
        break;
    case 'T': thumb = (thumb - 5) % 360;
        glutPostRedisplay();
        break;
    case 'i': index = (index - 5) % 360;
        glutPostRedisplay();
        break;
    case 'I': index = (index + 5) % 360;
        glutPostRedisplay();
        break;
    case 'm': middle = (middle - 5) % 360;
        glutPostRedisplay();
        break;
    case 'M': middle = (middle + 5) % 360;
        glutPostRedisplay();
        break;
    case 'r': ring = (ring - 5) % 360;
        glutPostRedisplay();
        break;
    case 'R': ring = (ring + 5) % 360;
        glutPostRedisplay();
        break;
    case 'p': pinky = (pinky - 5) % 360;
        glutPostRedisplay();
        break;
    case 'P': pinky = (pinky + 5) % 360;
        glutPostRedisplay();
        break;
    case 27: exit(0);
    default: break;
    }
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
