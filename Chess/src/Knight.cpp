#include "Knight.h"
#include <cmath>

bool Knight::isValidMove(int x, int y){
    if (abs(x - this->getX()) == 1 && abs(y - this->getY()) == 2) return true;
    else if (abs(x - this->getX()) == 2 && abs(y - this->getY()) == 1) return true;
    else return false;
}

bool Knight::captureTargetSquare(int x, int y){
    if (abs(x - this->getX()) == 1 && abs(y - this->getY()) == 2) return true;
    else if (abs(x - this->getX()) == 2 && abs(y - this->getY()) == 1) return true;
    else return false;
}
