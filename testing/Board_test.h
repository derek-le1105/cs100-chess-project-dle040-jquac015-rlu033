#ifndef __BOARD_TEST_H__
#define __BOARD_TEST_H__

#include "gtest/gtest.h"
#include "../BoardArray.h"

/* (BW) signifies who's turn was last
Checkmate: https://www.chess.com/forum/view/general/13-checkmates-you-must-know
Stalemate: https://www.ichess.net/blog/stalemate-in-chess/
    0 = normal
    1 = 2 turn win (B)
    2 = Two major pieces back rank mate (B)
    3 = Diagonal checkmate (W)
    4 = Bishop and Knight fianchetto checkmate (W)

    6 = One Pawn (W)
    7 = Two Rooks (B)
    8 = One Queen (W)
*/
class TestFactory : public BoardFactory {
    BoardFactory b;
    int testNum;

    public:
    TestFactory(int num = 0) { testNum = num; }
    void BuildTests (Piece* array[][8]) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++)
                array[i][j] = nullptr;
        }

        switch (testNum) {
            case 1:
                CreateBoard(array);
                array[5][5] = array[5][6];
                array[5][6] = nullptr;
                array[5][5]->setCoord('f',6);
                array[4][2] = array[4][1];
                array[4][1] = nullptr;
                array[4][2]->setCoord('e',3);
                array[6][4] = array[6][6];
                array[6][6] = nullptr;
                array[6][4]->setCoord('e',3);
                array[7][4] = array[3][0];
                array[3][0] = nullptr;
                array[7][4]->setCoord('f',3);
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

            //-----------------------------

                case 6:
                array[3][0] = new King(BLACK,'d',1);
                array[3][2] = new King(WHITE,'d',3);
                array[3][1] = new Pawn(WHITE,'d',2);
                break;

                case 7:
                array[7][7] = new King(WHITE,'h',8);
                array[0][0] = new King(BLACK,'a',1);
                array[0][6] = new Rook(BLACK,'a',7);
                array[6][0] = new Rook(BLACK,'g',1);
                break;

                case 8:
                array[0][0] = new King(BLACK,'a',1);
                array[3][5] = new King(WHITE,'d',6);
                array[2][1] = new Queen(WHITE,'c',2);

            //-----------------------------

                default:
                CreateBoard(array);
                break;
        }
    }
};

TEST(BoardTest, NoFlags0) {
    BoardArray test;
    BoardFactory* b = new TestFactory(0);
    test.setFactory(b);
    test.ResetBoard();
    EXPECT_EQ(test.checkmate(),false);
    EXPECT_EQ(test.stalemate(),false);
}
TEST(BoardTest, Checkmate1) {
    BoardArray test;
    BoardFactory* b = new TestFactory(1);
    test.setFactory(b);
    test.ResetBoard();
    EXPECT_EQ(test.check(),true);
    EXPECT_EQ(test.checkmate(),true);
    EXPECT_EQ(test.stalemate(),false);
}
TEST(BoardTest, Checkmate2) {
    BoardArray test;
    BoardFactory* b = new TestFactory(2);
    test.setFactory(b);
    test.ResetBoard();
    EXPECT_EQ(test.check(),true);
    EXPECT_EQ(test.checkmate(),true);
    EXPECT_EQ(test.stalemate(),false);
}
TEST(BoardTest, Checkmate3) {
    BoardArray test;
    BoardFactory* b = new TestFactory(3);
    test.setFactory(b);
    test.ResetBoard();
    EXPECT_EQ(test.check(),true);
    EXPECT_EQ(test.checkmate(),true);
    EXPECT_EQ(test.stalemate(),false);
}
TEST(BoardTest, Checkmate4) {
    BoardArray test;
    BoardFactory* b = new TestFactory(4);
    test.setFactory(b);
    test.ResetBoard();
    EXPECT_EQ(test.check(),true);
    EXPECT_EQ(test.checkmate(),true);
    EXPECT_EQ(test.stalemate(),false);
}

TEST(BoardTest, Stalemate6) {
    BoardArray test;
    BoardFactory* b = new TestFactory(6);
    test.setFactory(b);
    test.ResetBoard();
    EXPECT_EQ(test.check(),false);
    EXPECT_EQ(test.checkmate(),false);
    EXPECT_EQ(test.stalemate(),true);
}
TEST(BoardTest, Stalemate7) {
    BoardArray test;
    BoardFactory* b = new TestFactory(7);
    test.setFactory(b);
    test.ResetBoard();
    EXPECT_EQ(test.check(),false);
    EXPECT_EQ(test.checkmate(),false);
    EXPECT_EQ(test.stalemate(),true);
}
TEST(BoardTest, Stalemate8) {
    BoardArray test;
    BoardFactory* b = new TestFactory(8);
    test.setFactory(b);
    test.ResetBoard();
    EXPECT_EQ(test.check(),false);
    EXPECT_EQ(test.checkmate(),false);
    EXPECT_EQ(test.stalemate(),true);
}
#endif
