#include "game.h"
#include "types.h"
#include <stdlib.h>
#include <math.h>

// Instantiate Game State variables
float playerX = 0.0f, playerY = 0.0f, playerZ = 0.0f;
float velZ = 0.0f;
float speed = 0.002f;
float shipTilt = 0.0f;
float shipTilt2 = 0.0f;
float camYaw = 0.0f;
float camPitch = 0.0f;
float camDistance = 4.0f;
float groundOffset = 0.0f;

float startTime = 0.0f;
float currentTime = 0.0f;

bool titleScreen = true;
bool gameOver = false;
float highScore = 0.0f;

Asteroid ast[qnty];
float astRotAngle[qnty];
float worldSpeed = 0.005f;

void initAsteroids() {
    for (int i = 0; i < qnty; i++) {
        ast[i].x = ((rand() % 200) / 100.0f - 1.0f) * 0.95f;
        ast[i].y = ((rand() % 200) / 100.0f - 1.0f) * 0.95f;
        ast[i].z = -(rand() % 100 + 10);
        ast[i].size = 0.2f + (rand() % 100) / 400.0f;
        astRotAngle[i] = rand() % 360;
    }
}

void reset() {
    playerX = 0.0f;
    playerY = 0.0f;
    playerZ = 0.0f;
    velZ = 0.0f;

    startTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
    currentTime = 0.0f;

    initAsteroids();
    gameOver = false;
    camYaw = 0.0f;
    camPitch = 0.0f;
}

void update() {
	if (titleScreen) {
        if (keys['s'] || keys[13]) { 
            titleScreen = false;
            reset(); 
        }
        if (keys[27]) exit(0);
        glutPostRedisplay();
        return;
    }
    
    if (gameOver && keys['r']) {
        reset();
        return;
    }
    
    if (!gameOver) {
        groundOffset += worldSpeed * 0.5f;
        if (groundOffset > 1.0f) groundOffset -= 1.0f;
    }
    
    if (gameOver) {
        if (keys['j']) camYaw -= 0.5f;
        if (keys['l']) camYaw += 0.5f;
        if (keys['i']) camPitch += 0.5f;
        if (keys['k']) camPitch -= 0.5f;
        
        if (keys[27]) exit(0);

        if (camPitch > 89.0f) camPitch = 89.0f;
        if (camPitch < -89.0f) camPitch = -89.0f;

        glutPostRedisplay();
        return;
    }
    
    float moveX = 0.0f, moveY = 0.0f;
    float limit = 0.95f;
    shipTilt = 0.0f;
    shipTilt2 = 0.0f;

    if (keys['w']) moveY += 1.5f;
    if (keys['s']) moveY -= 1.5f;
    if (keys['a']) moveX -= 1.5f;
    if (keys['d']) moveX += 1.5f;
    
    if (keys['w']) shipTilt2 = 20.0f;
    if (keys['s']) shipTilt2 = -20.0f;
    
    if ((keys['w'] && keys['d']) && (playerX < limit && playerX > -limit && playerY < limit && playerY > -limit)) shipTilt = 30.0f;
    if ((keys['w'] && keys['a']) && (playerX < limit && playerX > -limit && playerY < limit && playerY > -limit)) shipTilt = -30.0f;
    if ((keys['s'] && keys['d']) && (playerX < limit && playerX > -limit && playerY < limit && playerY > -limit)) shipTilt = -30.0f;
    if ((keys['s'] && keys['a']) && (playerX < limit && playerX > -limit && playerY < limit && playerY > -limit)) shipTilt = 30.0f;
    
    if (keys[27]) exit(0);
    
    playerX += moveX * speed;
    playerY += moveY * speed;

    if (playerX > limit) playerX = limit;
    if (playerX < -limit) playerX = -limit;
    if (playerY > limit) playerY = limit;
    if (playerY < -limit) playerY = -limit;

    velZ -= 0.01f;
    playerZ += velZ;

    float floorZ = 0.05f;
    if (playerZ < floorZ + 0.05f) {
        playerZ = floorZ + 0.05f;
        velZ = 0.0f;
    }

    worldSpeed = 0.01f + currentTime * 0.00001f;

    for (int i = 0; i < qnty; i++) {
        ast[i].z += worldSpeed;

        if (ast[i].z > 3.0f) {
            ast[i].z = -(rand() % 100 + 50);
            ast[i].x = ((rand() % 200) / 100.0f - 1.0f) * 0.95f;
            ast[i].y = ((rand() % 200) / 100.0f - 1.0f) * 0.95f;
            ast[i].size = 0.2f + (rand() % 100) / 400.0f;
        }

        float dx = ast[i].x - playerX;
        float dy = ast[i].y - playerY;
        float dz = ast[i].z - playerZ;
        float dist = sqrt(dx*dx + dy*dy + dz*dz);
        
        if (dist < ast[i].size + 0.005f) {
            gameOver = true;
            if (currentTime > highScore) highScore = currentTime;
        }
    }
    
    for (int i = 0; i < qnty; i++) {
        astRotAngle[i] += 0.05f;
        if (astRotAngle[i] > 360) astRotAngle[i] -= 360;
    }
    
    currentTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f - startTime;
    glutPostRedisplay();
}
