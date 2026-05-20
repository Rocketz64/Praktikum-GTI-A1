#pragma once
#define qnty 32

struct Asteroid {
    float x, y, z;
    float size;
};

extern Asteroid ast[qnty];
extern float astRotAngle[qnty];

void loadAsteroidTexture();
void initAsteroids();
void drawAsteroid();
