#include "Bishop.h"
#include <string>
#include <cmath>

bool Bishop::isValidMove(int x, int y) {
    return (abs(x - this->getX()) == abs(y - this->getY()));
}

bool Bishop::captureTargetSquare(int x, int y) {
    return (abs(x - this->getX()) == abs(y - this->getY()));
}
