#ifndef BOARD_H
#define BOARD_H



class Board
{
    public:
        Board();

        int boardArray[8][8];
        void initBoard();
        int initIDCounter;

        bool checkForPieceCollision;

    protected:

    private:
};

#endif // BOARD_H
