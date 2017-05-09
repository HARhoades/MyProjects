#include "Rook.h"

bool Rook::isValidMove(int x, int y){
    return (x == this->getX() || y == this->getY());
}

bool Rook::captureTargetSquare(int x, int y){
    return (x == this->getX() || y == this->getY());
}
