#ifndef PAWN_H
#define PAWN_H

#include "GamePiece.h"
#include <string>

using namespace std;

class Pawn : public GamePiece
{
    public:
        Pawn() : GamePiece("Pawn"){};
        bool isValidMove(int x, int y);
        bool captureTargetSquare(int x, int y);

    protected:

    private:
};

#endif // PAWN_H
