#ifndef KNIGHT_H
#define KNIGHT_H

#include "GamePiece.h"
#include <string>

class Knight : public GamePiece
{
    public:
        Knight() : GamePiece("Knight"){};
        bool isValidMove(int x, int y);
        bool captureTargetSquare(int x, int y);

    protected:

    private:
};

#endif // KNIGHT_H
