#include "GamePiece.h"
#include <string>

using namespace std;

GamePiece::GamePiece(string name, bool pieceIsWhite)
{
    this->pieceName = name;
    this->isWhite = pieceIsWhite;
    this->xPos = 0;
    this->yPos = 0;
}

bool GamePiece::getPieceIsWhite() {
    if (this->isWhite) return true;
    else return false;
}

bool GamePiece::isValidPieceMove(int x, int y){
    return true;
}

bool GamePiece::isValidCaptureMove(int x, int y) {
    return this->isValidPieceMove(x, y);
}

void GamePiece::movePieceTo(int x, int y) {
    if (this->isValidPieceMove(x, y)) {
        this->xPos = x;
        this->yPos = y;
    }
}

