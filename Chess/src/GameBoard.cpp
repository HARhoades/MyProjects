#include "GameBoard.h"

GameBoard::GameBoard()
{
    for (int i = 0; i < this->boardSize; i++){
        for (int j = 0; j < this->boardSize; j++) {
            this->boardSquares[i][j] = 0;
        }
    }
}

bool GameBoard::checkInBoardSpace(int x, int y) {
    if (x < 0 || x > this->boardSize || y < 0 || y > this->boardSize) return false;
    else return true;
}

bool GameBoard::checkIfCapture(GamePiece attacking, int x, int y){
    if (this->checkInBoardSpace(x, y)) {
        int targetPieceID = this->boardSquares[x][y];
        if (targetPieceID == 0) return false;
        else {
            if ((attacking.getPieceIsWhite() && targetPieceID > 15) || !attacking.getPieceIsWhite() && targetPieceID < 16) return true;
            else return false;
        }
    }
}

