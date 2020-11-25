#ifndef __PIECE_TEST_HPP__
#define __PIECE_TEST_HPP__

#include "gtest/gtest.h"
#include "../Piece.h"
/*
TEST(PieceFunctions, Alignment) {
    Piece p1(WHITE, 'a', 1);
    EXPECT_EQ(p1.getAlignment(), WHITE);
}*/

//Piece is an abstract class, so it cannot be tested directly
//Rook is being used to test Piece since it has the most basic move function: either vertically or horizontally only
TEST(PieceFunctionTest, Alignment) {
    Rook r1(WHITE, 'a', 1);
    EXPECT_EQ(r1.getAlignment(), WHITE);
    Rook r2(BLACK, 'a', 1);
    EXPECT_EQ(r2.getAlignment(), BLACK);
}

TEST(PieceMoveTest, NoMove) {
    Rook test(WHITE, 'a', 1);
    EXPECT_EQ(test.move('a',1), false);

    EXPECT_EQ(test.move('A',1), false);
}

TEST(PieceMoveTest, TestRange) {
    Rook test(WHITE, 'd', 4);

    //InRange
    ASSERT_EQ(test.move('a',4), true);
    ASSERT_EQ(test.move('h',4), true);

    ASSERT_EQ(test.move('d',1), true);
    ASSERT_EQ(test.move('d',1), true);

    //OutOfRange
    int pass = 1;
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

//Basically the same as MoveRight and MoveUp, with second condition flipped to NOT
TEST(PieceMoveTest, CollisionWithOpposite) {
    Piece* array[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            array[i][j] = nullptr;
        }
    }

    Piece* test = new Rook(WHITE, 'd', 4);
    array[3][3] = test;

    int pass;

    Piece* rookPiece5 = new Rook(BLACK, 'f', 4);
    array[5][3] = rookPiece5;
    //MoveRightValid
    pass = 1;
    if (!test->move('e',4,array)) { pass = 0; }
    ASSERT_EQ(pass, 1);
    //MoveRightIntoPiece
    pass = 1;
    if (!test->move('f',4,array)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    //MoveRightPastPiece
    pass = 1;
    if (test->move('g',4,array)) { pass = 0; }
    EXPECT_EQ(pass, 1);

    Piece* rookPiece6 = new Rook(BLACK, 'd', 6);
    array[3][5] = rookPiece6;
    //MoveUpValid
    pass = 1;
    if (!test->move('d',5,array)) { pass = 0; }
    ASSERT_EQ(pass, 1);
    //MoveUpIntoPiece
    pass = 1;
    if (!test->move('d',6,array)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    //MoveUpPastPiece
    pass = 1;
    if (test->move('d',7,array)) { pass = 0; }
    EXPECT_EQ(pass, 1);

    delete rookPiece5;
    delete rookPiece6;
    delete test;
}


//Literally the same test as Piece::move() since I used Rook (easiest movement)
TEST(RookMove, PieceMove) {
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
//also reuses MoveRight and MoveUp
TEST(RookMove, CollisionMove) {
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
TEST(RookMove, MoveRestriction) {
    Rook test(WHITE, 'a',1);
    int pass;

    pass = 1;
    if (!test.move('a',3)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    pass = 1;
    if (!test.move('c',1)) { pass = 0; }
    EXPECT_EQ(pass, 1);

    pass = 1;
    if (test.move('b',3)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    pass = 1;
    if (test.move('c',2)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    pass = 1;
    if (test.move('b',2)) { pass = 0; }
    EXPECT_EQ(pass, 1);
}
//Collision was basically already tested for Rook

TEST(KnightMove, PieceMove) {
    int pass;
    Knight test(WHITE, 'b', 2);

    //NoMove
    pass = 1;
    if (test.move('b',2)) { pass = 0; }
    ASSERT_EQ(pass, 1);

    //InRange
    pass = 1;
    if (!test.move('c',4)) { pass = 0; }
    ASSERT_EQ(pass, 1);
    pass = 1;
    if (!test.move('d',4)) { pass = 0; }
    ASSERT_EQ(pass, 1);

    pass = 1;
    if (!test.move('a',4)) { pass = 0; }
    ASSERT_EQ(pass, 1);
    pass = 1;
    if (!test.move('d',1)) { pass = 0; }
    ASSERT_EQ(pass, 1);

    //OutOfRange
    pass = 1;
    if (test.move('b'-2,3)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    pass = 1;
    if (test.move('b'-2,1)) { pass = 0; }
    EXPECT_EQ(pass, 1);

    pass = 1;
    if (test.move('a',0)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    pass = 1;
    if (test.move('c',0)) { pass = 0; }
    EXPECT_EQ(pass, 1);
}
TEST(KnightMove, MoveRestriction) {
    int pass;
    Knight test(WHITE, 'b', 2);

    pass = 1;
    if (test.move('a',3)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    pass = 1;
    if (test.move('a',2)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    pass = 1;
    if (test.move('c',1)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    pass = 1;
    if (test.move('b',1)) { pass = 0; }
    EXPECT_EQ(pass, 1);
}
TEST(KnightMove, CollisionTest) {
    Piece* array[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            array[i][j] = nullptr;
        }
    }

    Piece* test = new Knight(WHITE, 'b', 2);
    array[1][1] = test;

    int pass;
    Piece* knightPiece1 = new Knight(WHITE, 'c', 4);
    array[2][3] = knightPiece1;

    pass = 1;
    //MoveIntoPiece
    if (test->move('c',4,array)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    delete knightPiece1;

    Piece* knightPiece2 = new Knight(BLACK, 'c', 4);
    array[2][3] = knightPiece2;

    pass = 1;
    //CapturePiece
    if (!test->move('c',4,array)) { pass = 0; }
    EXPECT_EQ(pass, 1);
    delete knightPiece2;

    delete test;
}

#endif
