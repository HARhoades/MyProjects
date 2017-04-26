#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "GamePiece.h"

class GameBoard
{
    public:
        GameBoard();

        void initializeGame();
        bool checkInBoardSpace(int x, int y);
        bool checkIfValidMove(); //king in check?
        bool checkIfCapture(GamePiece attacking, int x, int y);

    protected:

    private:
        int boardSquares[8][8];
        int boardSize=8;
};

#endif // GAMEBOARD_H
