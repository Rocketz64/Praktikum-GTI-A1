#include "global.h"
#include "player.h"
#include "asteroid.h"
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

float playerX = 0.0f, playerY = 0.0f, playerZ = 0.0f;
float velZ = 0.0f;
bool keys[256] = {false};
float speed = 0.002f;
float shipTilt = 0.0f;
float shipTilt2 = 0.0f;
float camYaw = 0.0f;
float camPitch = 0.0f;
float camDistance = 4.0f;

float startTime = 0.0f;
float currentTime = 0.0f;

bool titleScreen = true;
bool gameOver = false;
float highScore = 0.0f;

void keyDown(unsigned char key, int x, int y) {
	key = tolower(key);
    keys[key] = true;
}

void keyUp(unsigned char key, int x, int y) {
	key = tolower(key);
    keys[key] = false;
}

//RESET GAME
void reset() {
    playerX = 0.0f;
    playerY = 0.0f;
    playerZ = 0.0f;
    velZ = 0.0f;

    startTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
    currentTime = 0.0f;

    initAsteroids();

    gameOver = false;
    
    // reset kamera
    camYaw = 0.0f;
    camPitch = 0.0f;
}

//UPDATE GAME
void update() {
	if (gameOver && keys['r']) {
	    reset();
	    return;
	}
	
	if (gameOver) {
	    // kontrol kamera saat game over
	    if (keys['j']) camYaw -= 0.5f;   // kiri
	    if (keys['l']) camYaw += 0.5f;   // kanan
	    if (keys['i']) camPitch += 0.5f; // atas
	    if (keys['k']) camPitch -= 0.5f; // bawah
	    
	    if (keys[27]) exit(0);
	
	    // batas supaya kamera tidak kebalik
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
    
    
    /*TAMBAHAN1*/
    for (int i = 0; i < qnty; i++) {
        astRotAngle[i] += 0.05f; // kecepatan putar
        if (astRotAngle[i] > 360) astRotAngle[i] -= 360;
    }
    
    /*TAMBAHAN1*/

    currentTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f - startTime;

    glutPostRedisplay();
}
