#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// =======================
// Variabel Rotasi
// =======================
double rx = 0.0;
double ry = 0.0;

// Koordinat sumber cahaya
float l[] = { 0.0f, 80.0f, 0.0f };

// Normal bidang lantai
float n[] = { 0.0f, -40.0f, 0.0f };

// Titik bidang lantai
float e[] = { 0.0f, -60.0f, 0.0f };

void help();

// =======================
// Obyek yang akan digambar
// =======================
void draw() {

    // Pilih salah satu objek

    // glutSolidTeapot(30.0);
    // glutSolidTorus(20, 40, 20, 10);
    // glutWireSphere(60, 10, 10);
    // glutSolidCube(40);

    glutSolidCone(20, 50, 40, 50);
}

// =======================
// Membuat proyeksi bayangan
// =======================
void glShadowProjection(float* l, float* e, float* n) {

    float d, c;
    float mat[16];

    d = n[0] * l[0] +
        n[1] * l[1] +
        n[2] * l[2];

    c = e[0] * n[0] +
        e[1] * n[1] +
        e[2] * n[2] - d;

    // OpenGL menggunakan kolom matriks

    mat[0]  = l[0] * n[0] + c;
    mat[4]  = n[1] * l[0];
    mat[8]  = n[2] * l[0];
    mat[12] = -l[0] * c - l[0] * d;

    mat[1]  = n[0] * l[1];
    mat[5]  = l[1] * n[1] + c;
    mat[9]  = n[2] * l[1];
    mat[13] = -l[1] * c - l[1] * d;

    mat[2]  = n[0] * l[2];
    mat[6]  = n[1] * l[2];
    mat[10] = l[2] * n[2] + c;
    mat[14] = -l[2] * c - l[2] * d;

    mat[3]  = n[0];
    mat[7]  = n[1];
    mat[11] = n[2];
    mat[15] = -d;

    // Kalikan matriks
    glMultMatrixf(mat);
}

// =======================
// Render Scene
// =======================
void render() {

    glClearColor(0.0f, 0.6f, 0.9f, 0.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Posisi cahaya
    glLightfv(GL_LIGHT0, GL_POSITION, l);

    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHTING);

    // Titik cahaya
    glColor3f(1.0f, 1.0f, 0.0f);

    glBegin(GL_POINTS);
        glVertex3f(l[0], l[1], l[2]);
    glEnd();

    // Lantai
    glColor3f(0.8f, 0.8f, 0.8f);

    glBegin(GL_QUADS);

        glNormal3f(0.0f, 1.0f, 0.0f);

        glVertex3f(-1300.0f, e[1] - 0.1f,  1300.0f);
        glVertex3f( 1300.0f, e[1] - 0.1f,  1300.0f);
        glVertex3f( 1300.0f, e[1] - 0.1f, -1300.0f);
        glVertex3f(-1300.0f, e[1] - 0.1f, -1300.0f);

    glEnd();

    // =======================
    // Gambar objek asli
    // =======================
    glPushMatrix();

        glRotatef(ry, 0, 1, 0);
        glRotatef(rx, 1, 0, 0);

        glEnable(GL_LIGHTING);

        glColor3f(0.0f, 0.0f, 0.8f);

        draw();

    glPopMatrix();

    // =======================
    // Gambar bayangan
    // =======================
    glPushMatrix();

        glShadowProjection(l, e, n);

        glRotatef(ry, 0, 1, 0);
        glRotatef(rx, 1, 0, 0);

        glDisable(GL_LIGHTING);

        glColor3f(0.4f, 0.4f, 0.4f);

        draw();

    glPopMatrix();

    glutSwapBuffers();
}

// =======================
// Keyboard Control
// =======================
void keypress(unsigned char c, int a, int b) {

    if (c == 27) {
        exit(0);
    }
    else if (c == 's') {
        l[1] -= 5.0f;
    }
    else if (c == 'w') {
        l[1] += 5.0f;
    }
    else if (c == 'a') {
        l[0] -= 5.0f;
    }
    else if (c == 'd') {
        l[0] += 5.0f;
    }
    else if (c == 'q') {
        l[2] -= 5.0f;
    }
    else if (c == 'e') {
        l[2] += 5.0f;
    }
    else if (c == 'h') {
        help();
    }
}

// =======================
// Bantuan
// =======================
void help() {

    printf("Proyeksi contoh bayangan sebuah objek OpenGL\n");
}

// =======================
// Idle Animation
// =======================
void idle() {

    rx += 0.1;
    ry += 0.1;

    render();
}

// =======================
// Resize Window
// =======================
void resize(int w, int h) {

    glViewport(0, 0, w, h);
}

// =======================
// Main Program
// =======================
int main(int argc, char* argv[]) {

    glutInit(&argc, argv);

    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB |
        GLUT_DEPTH
    );

    glutInitWindowPosition(300, 30);

    glutCreateWindow("Proyeksi Bayangan");

    glutReshapeFunc(resize);
    glutReshapeWindow(400, 400);

    glutKeyboardFunc(keypress);
    glutDisplayFunc(render);
    glutIdleFunc(idle);

    // Enable fitur OpenGL
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_TEXTURE_2D);

    // Projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(
        60.0f,
        1.0f,
        1.0f,
        400.0f
    );

    // Modelview
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -150.0f);

    glutMainLoop();

    return 0;
}
