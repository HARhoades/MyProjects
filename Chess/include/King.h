#ifndef KING_H
#define KING_H

#include "GamePiece.h"
#include <string>

class King : public GamePiece
{
    public:
        King() : GamePiece("King"){};
        bool isValidMove(int x, int y);
        bool captureTargetSquare(int x, int y);

    protected:

    private:
};

#endif // KING_H
