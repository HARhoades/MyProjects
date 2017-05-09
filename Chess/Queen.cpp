#include "Queen.h"
#include <cmath>

bool Queen::isValidMove(int x, int y){
    if(abs(x - this->getX()) == abs(y - this->getY())) return true;
    else if(x == this->getX() || y == this->getY()) return true;
    else return false;
}

bool Queen::captureTargetSquare(int x, int y){
    if(abs(x - this->getX()) == abs(y - this->getY())) return true;
    else if(x == this->getX() || y == this->getY()) return true;
    else return false;
}
