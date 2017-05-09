#ifndef ROOK_H
#define ROOK_H

#include "GamePiece.h"
#include <string>

using namespace std;

class Rook : public GamePiece
{
    public:
        Rook() : GamePiece("Rook"){};
        bool isValidMove(int x, int y);
        bool captureTargetSquare(int x, int y);

    protected:

    private:
};

#endif // ROOK_H
