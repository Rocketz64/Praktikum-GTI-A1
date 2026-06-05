#include "render.h"
#include "types.h"
#include <string.h>
#include <stdio.h>
#include <math.h>

// Environment Properties Data
const GLfloat light_ambient[]  = { 0.05f, 0.05f, 0.1f, 1.0f };
const GLfloat light_diffuse[]  = { 0.9f, 0.95f, 1.0f, 1.0f };  
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };  
const GLfloat light_position[] = { 0.0f, 10.0f, 0.0f, 1.0f };

const GLfloat light_ambient2[]  = { 0.02f, 0.02f, 0.5f, 1.0f };
const GLfloat light_diffuse2[]  = { 0.9f, 0.95f, 1.0f, 1.0f };  
const GLfloat light_specular2[] = { 1.0f, 1.0f, 1.0f, 1.0f };  

const GLfloat light_ambient3[]  = { 0.4f, 0.02f, 0.4f, 1.0f };
const GLfloat light_diffuse3[]  = { 1.0f, 0.85f, 0.9f, 1.0f };  
const GLfloat light_specular3[] = { 1.0f, 1.0f, 1.0f, 1.0f };

const GLfloat light_ambient4[]  = { 0.12f, 0.05f, 0.18f, 1.0f };
const GLfloat light_diffuse4[]  = { 1.0f, 0.45f, 0.05f, 1.0f };  
const GLfloat light_specular4[] = { 1.0f, 0.85f, 0.30f, 1.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };  
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };  
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };  
const GLfloat high_shininess[] = { 100.0f }; 

void lighting(){   
    glEnable(GL_DEPTH_TEST);    
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);    
    glEnable(GL_NORMALIZE);    
    glEnable(GL_COLOR_MATERIAL);    
    glEnable(GL_LIGHTING);   
    
    if(currentTime >= 100.0f){
    	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient4);    
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse4);    
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular4);   
    }
	else{
		float loopTime = fmod(currentTime, 30.0f);
	
		if (loopTime >= 20.0f) {
	        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient3);    
	        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse3);    
	        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular3);    
	    } 
	    else if (loopTime >= 10.0f) {
	        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient2);    
	        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse2);    
	        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular2);    
	    } 
		else {
	        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);    
	        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);    
	        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);    
	    }   
	    glLightfv(GL_LIGHT0, GL_POSITION, light_position);    
	}
	
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);    
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);    
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);  
} 

void drawBackgroundScene() {
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

	if(currentTime >= 100.0f){
		glBindTexture(GL_TEXTURE_2D, backgroundTexture4);
    }
    else{
    	float loopTime = fmod(currentTime, 30.0f);
	    if (loopTime >= 20.0f) {
	        glBindTexture(GL_TEXTURE_2D, backgroundTexture3);
	    } else if (loopTime >= 10.0f){
	        glBindTexture(GL_TEXTURE_2D, backgroundTexture2);
	    } else {
	        glBindTexture(GL_TEXTURE_2D, backgroundTexture);
	    }
    }

    
    
    glColor3f(1.0f, 1.0f, 1.0f); 

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 1, 0, 1);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2f(0, 0);
        glTexCoord2f(1, 0); glVertex2f(1, 0);
        glTexCoord2f(1, 1); glVertex2f(1, 1);
        glTexCoord2f(0, 1); glVertex2f(0, 1);
    glEnd();

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glDisable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
}

void drawAsteroid() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, asteroidTexture);
    glColor3f(1,1,1);

    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    
    for (int i = 0; i < qnty; i++) {
        glPushMatrix();
        glTranslatef(ast[i].x, ast[i].y, ast[i].z);
        glRotatef(astRotAngle[i], 0.3f, 0.7f, 0.2f);
        gluSphere(quad, ast[i].size, 8, 8);
        glPopMatrix();
    }
    
    gluDeleteQuadric(quad);
    glDisable(GL_TEXTURE_2D);
}

void drawGroundSurface() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, groundTexture);
    glColor3f(1.0f, 1.0f, 1.0f);

    float groundY = -1.05f;      
    float halfWidth = 5.0f;      
    float startZ = 5.0f;         
    float endZ = -120.0f;        

    glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f);
        
        glTexCoord2f(0.0f, groundOffset); 
        glVertex3f(-halfWidth, groundY, startZ);

        glTexCoord2f(5.0f, groundOffset); 
        glVertex3f(halfWidth, groundY, startZ);

        glTexCoord2f(5.0f, groundOffset + 20.0f); 
        glVertex3f(halfWidth, groundY, endZ);

        glTexCoord2f(0.0f, groundOffset + 20.0f); 
        glVertex3f(-halfWidth, groundY, endZ);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void drawPlayerShadow(){
    float groundY = -1.05f;
    if (playerY < groundY) return;
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glPushMatrix();
    glTranslatef(playerX, groundY + 0.002f, playerZ);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor4f(0.0f, 0.0f, 0.0f, 0.5f); 
    
    GLUquadric* quad = gluNewQuadric();
    glScalef(1.2f, 0.6f, 1.0f); 
    gluDisk(quad, 0.0f, 0.25f, 16, 1);
    gluDeleteQuadric(quad);
    
    glPopMatrix();
    glPopAttrib();
}

void drawAsteroidShadows() {
    float groundY = -1.05f;

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    GLUquadric* quad = gluNewQuadric();

    for (int i = 0; i < qnty; i++) {
        if (ast[i].z > 4.0f || ast[i].z < -100.0f) continue;
        if (ast[i].y < groundY) continue;

        float distanceToGround = ast[i].y - groundY;
        float maxFadeDistance = 3.0f;
        
        float alpha = 0.4f * (1.0f - (distanceToGround / maxFadeDistance));
        if (alpha < 0.0f) alpha = 0.0f;
        if (alpha > 0.4f) alpha = 0.4f;

        float shadowScale = ast[i].size * (1.0f + (distanceToGround * 0.1f));

        glPushMatrix();
        glTranslatef(ast[i].x, groundY + 0.001f, ast[i].z); 
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glColor4f(0.0f, 0.0f, 0.0f, alpha);
        gluDisk(quad, 0.0f, shadowScale, 12, 1);
        glPopMatrix();
    }

    gluDeleteQuadric(quad);
    glPopAttrib();
}

void tulis_teks(float x, float y, const char* text) {
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glRasterPos2f(x, y);
    for (size_t i = 0; i < strlen(text); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    lighting();
    drawBackgroundScene();
    glLoadIdentity();
    
    if (titleScreen) {
        glColor3f(2.0f, 0.5f, 1.0f);
        tulis_teks(210, 300, "S P A C E   R U N N E R");
        
        glColor3f(1.0f, 1.0f, 1.0f);
        tulis_teks(200, 220, "Press 'S' or 'Enter' to Start");
        
        glColor3f(0.7f, 0.7f, 0.7f);
        tulis_teks(225, 160, "Controls: W, A, S, D");
        tulis_teks(240, 140, "Press Esc to Exit");
        
        glutSwapBuffers();
        return;
    }

    if (!gameOver) {
        gluLookAt(
            playerX, playerY + 0.5f, playerZ + 4.0f,
            playerX, playerY, playerZ,
            0.0f, 1.0f, 0.0f
        );
    } else {
        float yawRad = camYaw * 3.14159f / 180.0f;
        float pitchRad = camPitch * 3.14159f / 180.0f;
    
        float camX = playerX + camDistance * cos(pitchRad) * sin(yawRad);
        float camY = playerY + camDistance * sin(pitchRad);
        float camZ = playerZ + camDistance * cos(pitchRad) * cos(yawRad);
    
        gluLookAt(
            camX, camY, camZ,
            playerX, playerY, playerZ,
            0.0f, 1.0f, 0.0f
        );
    }

    glPushMatrix();
    glScalef(2.0f, 2.0f, 256.0f);
    glColor3f(1.0f, 0.3f, 1.0f);
    glutWireCube(1.001);
    glPopMatrix();
    
    glEnable(GL_LIGHTING);

    glPushMatrix();
    glTranslatef(playerX, playerY, playerZ);

    glPushMatrix();
    glRotatef(shipTilt, 0.0f, 0.0f, 1.0f);
    glRotatef(shipTilt2, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -0.04f, 0.0f);
    glColor3f(0.6f, 0.6f, 0.6f);
    glScalef(1.0f, 0.3f, 1.0f);
    glutSolidSphere(0.20, 8, 8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.4f, 0.9f, 0.9f);
    glutSolidSphere(0.10, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glRotatef(shipTilt, 0.0f, 0.0f, 1.0f);
    glRotatef(shipTilt2, 1.0f, 0.0f, 0.0f);
    glColor3f(0.9f, 0.9f, 0.4f);
    glTranslatef(0.0f, 0.01f, 0.0f);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glutSolidTorus(0.008, 0.11, 24, 24);
    glPopMatrix();

    glPopMatrix();

    drawAsteroid();
    drawGroundSurface();
    
    drawPlayerShadow();
    drawAsteroidShadows();

    char buffer[50];
    sprintf(buffer, "Score: %.0f", currentTime * 100);
    glColor3f(1.0f, 1.0f, 0.0f);
    tulis_teks(10, 450, buffer);
    
    sprintf(buffer, "High Score: %.0f", highScore * 100);
    glColor3f(1.0f, 1.0f, 0.0f);
    tulis_teks(10, 425, buffer);
    
    if (gameOver) {
        glColor3f(1.0f, 0.0f, 0.0f);
        tulis_teks(265, 240, "GAME OVER");
        tulis_teks(256, 220, "Press R to retry");
        tulis_teks(247, 200, "Press Esc to quit");
    }

    glutSwapBuffers();
}

void reshape(int x, int y) {
    if (x == 0 || y == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)x/(GLdouble)y, 0.5, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, x, y);
}
