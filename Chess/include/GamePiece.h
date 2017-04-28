#ifndef GAMEPIECE_H
#define GAMEPIECE_H

#include <string>

using namespace std;

class GamePiece
{
    public:
        GamePiece(string name, bool pieceIsWhite, int id);

        int pieceID; //0-15 white, 16-31 black

        bool isValidPieceMove(int x, int y);
        bool getPieceIsWhite();
        bool isValidCaptureMove(int x, int y);
        void movePieceTo(int x, int y);

    protected:

        int xPos;
        int yPos;
        bool isWhite;
        string pieceName;

    private:

};

#endif // GAMEPIECE_H
