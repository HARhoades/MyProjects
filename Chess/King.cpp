#include "King.h"
#include <cmath>

bool King::isValidMove(int x, int y){
    return (abs(x - this->getX()) <= 1 && abs(y - this->getY() <= 1));
}

bool King::captureTargetSquare(int x, int y){
    return (abs(x - this->getX()) <= 1 && abs(y - this->getY() <= 1));
}
