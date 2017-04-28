#include "Pawn.h"
#include <string>

Pawn::Pawn(string name, bool pieceIsWhite, int id)
{
    this->pieceName = name;
    this->isWhite = pieceIsWhite;
    this->pieceID = id;
}
