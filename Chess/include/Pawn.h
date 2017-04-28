#ifndef PAWN_H
#define PAWN_H

#include "GamePiece.h"
#include <string>

using namespace std;

class Pawn : public GamePiece
{
    public:
        Pawn(string name, bool pieceIsWhite, int id)
            : GamePiece(name, pieceIsWhite, id) {name="Pawn"};


    protected:

    private:
};

#endif // PAWN_H
