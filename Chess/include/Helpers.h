#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <GL/freeglut.h>

double screenToWorld(int mouseLoc, double worldMin, double worldMax, int screenMin, int screenMax, bool invert);
void drawStringBitmap(double drawX, double drawY, std::string drawStr, void* font=GLUT_BITMAP_9_BY_15);
void drawStringStroke(std::string drawStr, void* font=GLUT_STROKE_ROMAN);


#endif // HELPERS_H
