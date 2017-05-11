#include "Board.h"

Board::Board()
{
}

void Board::initBoard(){
    this->boardDisplay.importAll("gameBoard");
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            this->boardArray[i][j] = 0;
        }
    }
    int rowIndex = 0;
    for (initIDCounter=1; initIDCounter<=32; initIDCounter++){
        if (initIDCounter % 8 == 0) rowIndex++%2;
        if (initIDCounter <= 16) this->boardArray[rowIndex][initIDCounter%8] = initIDCounter;
        else this->boardArray[8 - rowIndex][initIDCounter%8] = initIDCounter;
    }
}
