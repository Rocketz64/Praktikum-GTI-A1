#ifndef RENDER_H
#define RENDER_H

void lighting();
void display();
void reshape(int x, int y);
void drawBackgroundScene();
void drawAsteroid();
void drawGroundSurface();
void drawPlayerShadow();
void drawAsteroidShadows();
void tulis_teks(float x, float y, const char* text);

#endif
