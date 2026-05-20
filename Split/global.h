#pragma once
#include <GL/glut.h>

// PLAYER
extern float playerX, playerY, playerZ;
extern float velZ, speed, shipTilt, shipTilt2;
extern bool keys[256];
extern float camYaw, camPitch, camDistance;

// TIME, SCORE, AND STATE
extern float startTime, currentTime, highScore;
extern bool gameOver;

// TEXTURES
extern GLuint backgroundTexture, backgroundTexture2, backgroundTexture3;
extern GLuint asteroidTexture;

// SPACE
extern float worldSpeed;
