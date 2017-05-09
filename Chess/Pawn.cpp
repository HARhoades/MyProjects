#include "Pawn.h"
#include <string>

bool Pawn::isValidMove(int x, int y) {
    if(this->getColor()) {return (x == this->getX() && y == this->getY()+1);}
    else {return (x == this->getX() && y == this->getY()-1);}
}

bool Pawn::captureTargetSquare(int x, int y) {
    if(x == this->getX()+1 || x == this->getX()-1) {//TODO && boardArray[x][y] within color's range...do logic check in board
        if(y == this->getY()+1 && this->getColor()) return true;
        else if(y == this->getY()-1 && !this->getColor()) return true;
    }
    else return false;
}
