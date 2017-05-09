#ifndef QUEEN_H
#define QUEEN_H

#include "GamePiece.h"
#include <string>

class Queen : public GamePiece
{
    public:
        Queen() : GamePiece("Queen"){};
        bool isValidMove(int x, int y);
        bool captureTargetSquare(int x, int y);

    protected:

    private:
};

#endif // QUEEN_H
