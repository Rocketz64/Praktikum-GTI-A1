#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "types.h"
#include "textures.h"
#include "game.h"
#include "render.h"
#include "input.h"

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Space Runner");
    glEnable(GL_DEPTH_TEST);
    
    int maxSize;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxSize);
    printf("Max texture size: %d\n", maxSize);
    
    loadBackground();
    loadAsteroidTexture();
    loadGroundTexture();
    
    glClearColor(0.0, 0.0, 0.05, 0.0);
    srand(time(NULL));
    initAsteroids();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);
    glutIdleFunc(update);
    
    startTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
    lighting();
    
    glutMainLoop();
    return 0;
}
