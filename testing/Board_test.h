#ifndef __BOARD_TEST_H__
#define __BOARD_TEST_H__

#include "gtest/gtest.h"
#include "../Board.h"

/* (BW) signifies who's turn was last
Checkmate: https://www.chess.com/forum/view/general/13-checkmates-you-must-know
    0 = normal
    1 = 2 turn win (B)
    2 = Two major pieces back rank mate (B)
    3 = Diagonal checkmate (W)
    4 = Bishop and Knight fianchetto checkmate (W)
*/
class TestFactory : public BoardFactory {
    BoardFactory b;

    public:
    TestFactory() {}
    void BulidTests (int array[][8], int input = 0) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++)
                array[i][j] = nullptr;
        }

        switch (input) {
            case 0:
                CreateBoard(array);
                break;
            case 1:
                CreateBoard(array);
                array[5][5] = array[5][6];
                array[5][6] = nullptr;
                array[4][2] = array[4][1];
                array[4][1] = nullptr;
                array[6][4] = array[6][6];
                array[6][6] = nullptr;
                array[7][4] = array[3][0];
                array[3][0] = nullptr;
                break;
            case 2:
                array[7][7] = new King(WHITE,'h',8);
                array[0][0] = new King(BLACK,'a',1);
                array[0][6] = new Rook(BLACK,'a',7);
                array[1][7] = new Rook(BLACK,'b',8);
                break;
            case 3:
                array[0][0] = new Rook(BLACK,'a',1);
                array[5][0] = new Rook(BLACK,'f',1);
                array[6][0] = new King(BLACK,'g',1);
                array[0][1] = new Pawn(BLACK,'a',2);
                array[1][1] = new Pawn(BLACK,'b',2);
                array[2][1] = new Pawn(BLACK,'c',2);
                array[5][1] = new Pawn(BLACK,'f',2);
                array[6][1] = new Queen(WHITE,'g',2);
                array[7][1] = new Pawn(BLACK,'h',2);
                array[1][5] = new Pawn(WHITE,'b',6);
                array[0][6] = new Pawn(WHITE,'a',7);
                array[5][6] = new Pawn(WHITE,'f',7);
                array[6][6] = new Pawn(WHITE,'g',7);
                array[7][6] = new Pawn(WHITE,'h',7);
                array[0][7] = new Bishop(WHITE,'a',8);
                array[5][7] = new Rook(WHITE,'f',8);
                array[6][7] = new King(WHITE,'g',8);
                break;
            case 4:
                array[0][0] = new Rook(BLACK,'a',1);
                array[5][0] = new Rook(BLACK,'f',1);
                array[6][0] = new King(BLACK,'g',1);
                array[0][1] = new Pawn(BLACK,'a',2);
                array[1][1] = new Pawn(BLACK,'b',2);
                array[2][1] = new Pawn(BLACK,'c',2);
                array[5][1] = new Pawn(BLACK,'f',2);
                array[7][1] = new Pawn(BLACK,'h',2);
                array[5][2] = new Bishop(WHITE,'f',3);
                array[6][2] = new Pawn(BLACK,'g',3);
                array[7][2] = new Knight(WHITE,'h',3);
                array[1][5] = new Pawn(WHITE,'b',6);
                array[0][6] = new Pawn(WHITE,'a',7);
                array[5][6] = new Pawn(WHITE,'f',7);
                array[6][6] = new Pawn(WHITE,'g',7);
                array[7][6] = new Pawn(WHITE,'h',7);
                array[5][7] = new Rook(WHITE,'f',8);
                array[6][7] = new King(WHITE,'g',8);
                break;
        }
    }
}

#endif