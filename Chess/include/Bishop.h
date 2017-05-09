#ifndef BISHOP_H
#define BISHOP_H

#include "GamePiece.h"
#include <string>

class Bishop : public GamePiece
{
    public:
        Bishop() : GamePiece("Bishop"){};
        bool isValidMove(int x, int y);
        bool captureTargetSquare(int x, int y);

    protected:

    private:
};

#endif // BISHOP_H
