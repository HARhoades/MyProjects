#include "GamePiece.h"
#include <string>

using namespace std;

GamePiece::GamePiece(string name)
{
    this->pieceName = name;
    this->isActive = true;
}

bool GamePiece::getColor() {return this->isWhite;}
void GamePiece::setColor(bool isWhitePiece) {this->isWhite = isWhitePiece;}
int GamePiece::getX() {return this->xPos;}
void GamePiece::setX(int x) {this->xPos = x;}
int GamePiece::getY() {return this->yPos;}
void GamePiece::setY(int y) {this->yPos = y;}

bool GamePiece::isValidMove(int x, int y) {return true;}

void GamePiece::movePieceTo(int x, int y) {
    if(this->isValidMove(x, y)) {
        this->setX(x);
        this->setY(y);
    }
}

/*bool GamePiece::captureTargetSquare(int x, int y) {
    return true;
}*/
