#include "Helpers.h"

#include <cmath>

using namespace std;

double screenToWorld(int mouseLoc, double worldMin, double worldMax, int screenMin, int screenMax, bool invert) {
    double ratioScreen = (double)mouseLoc / (screenMax - screenMin);
    if (invert) ratioScreen = 1 - ratioScreen;
    return ratioScreen * (worldMax - worldMin) + worldMin;
}

void drawStringBitmap(double drawX, double drawY, string drawStr, void* font) {
    glRasterPos2f(drawX, drawY);
    for (unsigned int i = 0; i < drawStr.size(); i++)
        glutBitmapCharacter(font, drawStr[i]);
}

void drawStringStroke(string drawStr, void* font) {
    for (unsigned int i = 0; i < drawStr.size(); i++)
        glutStrokeCharacter(font, drawStr[i]);
}
