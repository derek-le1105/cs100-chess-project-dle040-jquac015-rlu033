#ifndef __PIECE_TEST_HPP__
#define __PIECE_TEST_HPP__

#include "gtest/gtest.h"
#include "Piece.h"
/*
TEST(PieceFunctions, Alignment) {
    Piece p1(WHITE, 'a', 1);
    EXPECT_EQ(p1.getAlignment(), WHITE);
}*/

TEST(PieceFunctionTest, Alignment) {
    Rook r1(WHITE, 'a', 1);
    EXPECT_EQ(r1.getAlignment(), WHITE);
    Rook r2(BLACK, 'a', 1);
    EXPECT_EQ(r2.getAlignment(), BLACK);
}

TEST(PieceMoveTest, NoMove) {
    int pass = 1;
    Rook test(WHITE, 'a', 1);
    if (test.move('a',1)) { pass = 0; }
    EXPECT_EQ(pass, 1);

    pass = 1;
    if (test.move('A',1)) { pass = 0; }
    EXPECT_EQ(pass, 1);
}

TEST(PieceMoveTest, TestRange) {
    int pass;
    Rook test(WHITE, 'd', 4);

    //InRange
    pass = 1;
    if (!test.move('a',4)) { pass = 0; }
    ASSERT_EQ(pass, 1);
    pass = 1;
    if (!test.move('h',4)) { pass = 0; }
    ASSERT_EQ(pass, 1);

    pass = 1;
    if (!test.move('d',1)) { pass = 0; }
    ASSERT_EQ(pass, 1);
    pass = 1;
    if (!test.move('d',8)) { pass = 0; }
    ASSERT_EQ(pass, 1);

    //OutOfRange
    pass = 1;
    if (test.move('+',4)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    pass = 1;
    if (test.move('i',4)) { pass = 0; }
    EXPECT_EQ(pass, 1);

    pass = 1;
    if (test.move('d',0)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    pass = 1;
    if (test.move('d',9)) { pass = 0; }
    EXPECT_EQ(pass, 1);
}

TEST(PieceMoveCollision, MoveRight) {
    Piece* array[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            array[i][j] = nullptr;
        }
    }

    Piece* test = new Rook(WHITE, 'd', 4);
    array[3][3] = test;

    int pass;

    Piece* rookPiece1 = new Rook(WHITE, 'f', 4);
    array[5][3] = rookPiece1;
    //MoveRightValid
    pass = 1;
    if (!test->move('e',4,array)) { pass = 0; }
    ASSERT_EQ(pass, 1);
    //MoveRightIntoPiece
    pass = 1;
    if (test->move('f',4,array)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    //MoveRightPastPiece
    pass = 1;
    if (test->move('g',4,array)) { pass = 0; }
    EXPECT_EQ(pass, 1);

    delete rookPiece1;
    delete test;
}
TEST(PieceMoveCollision, MoveLeft) {
    Piece* array[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            array[i][j] = nullptr;
        }
    }

    Piece* test = new Rook(WHITE, 'd', 4);
    array[3][3] = test;

    int pass;

    Piece* rookPiece2 = new Rook(WHITE, 'b', 4);
    array[1][3] = rookPiece2;
    //MoveLeftValid
    pass = 1;
    if (!test->move('c',4,array)) { pass = 0; }
    ASSERT_EQ(pass, 1);
    //MoveLeftIntoPiece
    pass = 1;
    if (test->move('b',4,array)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    //MoveLeftPastPiece
    pass = 1;
    if (test->move('a',4,array)) { pass = 0; }
    EXPECT_EQ(pass, 1);

    delete rookPiece2;
    delete test;
}
TEST(PieceMoveCollision, MoveUp) {
    Piece* array[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            array[i][j] = nullptr;
        }
    }

    Piece* test = new Rook(WHITE, 'd', 4);
    array[3][3] = test;

    int pass;

    Piece* rookPiece3 = new Rook(WHITE, 'd', 6);
    array[3][5] = rookPiece3;
    //MoveUpValid
    pass = 1;
    if (!test->move('d',5,array)) { pass = 0; }
    ASSERT_EQ(pass, 1);
    //MoveUpIntoPiece
    pass = 1;
    if (test->move('d',6,array)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    //MoveUpPastPiece
    pass = 1;
    if (test->move('d',7,array)) { pass = 0; }
    EXPECT_EQ(pass, 1);

    delete rookPiece3;
    delete test;
}
TEST(PieceMoveCollision, MoveDown) {
    Piece* array[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            array[i][j] = nullptr;
        }
    }

    Piece* test = new Rook(WHITE, 'd', 4);
    array[3][3] = test;

    int pass;

    Piece* rookPiece4 = new Rook(WHITE, 'd', 2);
    array[3][1] = rookPiece4;
    //MoveDownValid
    pass = 1;
    if (!test->move('d',3,array)) { pass = 0; }
    ASSERT_EQ(pass, 1);
    //MoveDownIntoPiece
    pass = 1;
    if (test->move('d',2,array)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    //MoveDownPastPiece
    pass = 1;
    if (test->move('d',1,array)) { pass = 0; }
    EXPECT_EQ(pass, 1);

    delete rookPiece4;
    delete test;
}

TEST(PieceMoveTest, CollisionWithOpposite) {
    Piece* array[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            array[i][j] = nullptr;
        }
    }

    Piece* test = new Rook(WHITE, 'a', 1);
    array[0][0] = test;
    Piece* rookPiece1 = new Rook(BLACK, 'd', 1);
    array[3][0] = rookPiece1;
    Piece* rookPiece2 = new Rook(BLACK, 'a', 4);
    array[0][3] = rookPiece2;

   EXPECT_EQ(0,1);   

    delete rookPiece1;
    delete rookPiece2;
    delete test;
}

#endif
