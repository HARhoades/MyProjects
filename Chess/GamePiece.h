#ifndef GAMEPIECE_H
#define GAMEPIECE_H

#include <string>
#include "ImportObject.h"
#include "Object3D.h"

using namespace std;

class GamePiece
{
    public:
        GamePiece(string name);
        string pieceName;

        ImportObject import;
        Object3D obj3D;

        int getX();
        void setX(int x);
        int getY();
        void setY(int y);
        bool getColor();
        void setColor(bool isWhitePiece);
        bool isValidMove(int x, int y);
        void movePieceTo(int x, int y);
        bool captureTargetSquare(int x, int y);
        bool isActive;

    protected:

    private:
        int xPos;
        int yPos;
        bool isWhite;
};

#endif // GAMEPIECE_H
