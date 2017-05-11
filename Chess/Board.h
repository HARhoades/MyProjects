#ifndef BOARD_H
#define BOARD_H

#include "ImportObject.h"


class Board
{
    public:
        Board();
        ImportObject boardDisplay;
        int boardArray[8][8];
        void initBoard();
        int initIDCounter;

        bool checkForPieceCollision;

    protected:

    private:
};

#endif // BOARD_H
