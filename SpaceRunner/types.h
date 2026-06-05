#ifndef TYPES_H
#define TYPES_H

#include <GL/glut.h>

#define qnty 32

// Game Structures
struct Asteroid {
    float x, y, z;
    float size;
};

// External Shared Variables
extern float playerX, playerY, playerZ;
extern float velZ;
extern bool keys[256];
extern float speed;
extern float shipTilt;
extern float shipTilt2;
extern float camYaw;
extern float camPitch;
extern float camDistance;

extern GLuint backgroundTexture;
extern GLuint backgroundTexture2;
extern GLuint backgroundTexture3;
extern GLuint backgroundTexture4;
extern GLuint groundTexture;
extern GLuint asteroidTexture;
extern float groundOffset;

extern float startTime;
extern float currentTime;

extern bool titleScreen;
extern bool gameOver;
extern float highScore;

extern Asteroid ast[qnty];
extern float astRotAngle[qnty];
extern float worldSpeed;

// Lighting Constants
extern const GLfloat light_ambient[];
extern const GLfloat light_diffuse[];
extern const GLfloat light_specular[];
extern const GLfloat light_position[];
extern const GLfloat light_ambient2[];
extern const GLfloat light_diffuse2[];
extern const GLfloat light_specular2[];
extern const GLfloat light_ambient3[];
extern const GLfloat light_diffuse3[];
extern const GLfloat light_specular3[];
extern const GLfloat light_ambient4[];
extern const GLfloat light_diffuse4[];
extern const GLfloat light_specular4[];

extern const GLfloat mat_ambient[];
extern const GLfloat mat_diffuse[];
extern const GLfloat mat_specular[];
extern const GLfloat high_shininess[];

#endif
