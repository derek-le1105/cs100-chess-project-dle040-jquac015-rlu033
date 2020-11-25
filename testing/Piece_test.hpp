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
    EXPECT_EQ(test.move('+',4), false);
    EXPECT_EQ(test.move('i',4), false);

    EXPECT_EQ(test.move('d',0), false);
    EXPECT_EQ(test.move('d',9), false);
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

    Piece* rookPiece1 = new Rook(WHITE, 'f', 4);
    array[5][3] = rookPiece1;
    //MoveRightValid
    ASSERT_EQ(test->move('e',4,array), true);
    //MoveRightIntoPiece
    EXPECT_EQ(test->move('f',4,array), false);
    //MoveRightPastPiece
    EXPECT_EQ(test->move('g',4,array), false);

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

    Piece* rookPiece2 = new Rook(WHITE, 'b', 4);
    array[1][3] = rookPiece2;
    //MoveLeftValid
    ASSERT_EQ(test->move('c',4,array), true);
    //MoveLeftIntoPiece
    EXPECT_EQ(test->move('b',4,array), false);
    //MoveLeftPastPiece
    EXPECT_EQ(test->move('a',4,array), false);

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

    Piece* rookPiece3 = new Rook(WHITE, 'd', 6);
    array[3][5] = rookPiece3;
    //MoveUpValid
    ASSERT_EQ(test->move('d',5,array), true);
    //MoveUpIntoPiece
    EXPECT_EQ(test->move('d',6,array), false);
    //MoveUpPastPiece
    EXPECT_EQ(test->move('d',7,array), false);

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

    Piece* rookPiece4 = new Rook(WHITE, 'd', 2);
    array[3][1] = rookPiece4;
    //MoveDownValid
    ASSERT_EQ(test->move('d',3,array), true);
    //MoveDownIntoPiece
    EXPECT_EQ(test->move('d',2,array), false);
    //MoveDownPastPiece
    EXPECT_EQ(test->move('d',1,array), false);

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

    Piece* rookPiece5 = new Rook(BLACK, 'f', 4);
    array[5][3] = rookPiece5;
    //MoveRightValid
    ASSERT_EQ(test->move('e',4,array), true);
    //MoveRightIntoPiece
    EXPECT_EQ(test->move('f',4,array), true);
    //MoveRightPastPiece
    EXPECT_EQ(test->move('g',4,array), false);

    Piece* rookPiece6 = new Rook(BLACK, 'd', 6);
    array[3][5] = rookPiece6;
    //MoveUpValid
    ASSERT_EQ(test->move('d',5,array), true);
    //MoveUpIntoPiece
    EXPECT_EQ(test->move('d',6,array), true);
    //MoveUpPastPiece
    EXPECT_EQ(test->move('d',7,array), false);

    delete rookPiece5;
    delete rookPiece6;
    delete test;
}


//Literally the same test as Piece::move() since I used Rook (easiest movement)
TEST(RookMove, PieceMove) {
    Rook test(WHITE, 'd', 4);

    //InRange
    ASSERT_EQ(test.move('a',4), true);
    ASSERT_EQ(test.move('h',4), true);

    ASSERT_EQ(test.move('d',1), true);
    ASSERT_EQ(test.move('d',8), true);

    //OutOfRange
    EXPECT_EQ(test.move('+',4), false);
    EXPECT_EQ(test.move('i',4), false);

    EXPECT_EQ(test.move('d',0), false);
    EXPECT_EQ(test.move('d',9), false);
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

    Piece* rookPiece1 = new Rook(WHITE, 'f', 4);
    array[5][3] = rookPiece1;
    //MoveRightValid
    ASSERT_EQ(test->move('e',4,array), true);
    //MoveRightIntoPiece
    EXPECT_EQ(test->move('f',4,array), false);
    //MoveRightPastPiece
    EXPECT_EQ(test->move('g',4,array), false);

    delete rookPiece1;

    Piece* rookPiece3 = new Rook(WHITE, 'd', 6);
    array[3][5] = rookPiece3;
    //MoveUpValid
    ASSERT_EQ(test->move('d',5,array), true);
    //MoveUpIntoPiece
    EXPECT_EQ(test->move('d',6,array), false);
    //MoveUpPastPiece
    EXPECT_EQ(test->move('d',7,array), false);

    delete rookPiece3;
    delete test;
}
TEST(RookMove, MoveRestriction) {
    Rook test(WHITE, 'a',1);

    EXPECT_EQ(test.move('a',3), true);
    EXPECT_EQ(test.move('c',1), true);

    EXPECT_EQ(test.move('b',3), false);
    EXPECT_EQ(test.move('c',2), false);
    EXPECT_EQ(test.move('b',7), false);
}
//Collision was basically already tested for Rook

TEST(KnightMove, PieceMove) {
    Knight test(WHITE, 'b', 2);

    //NoMove
    ASSERT_EQ(test.move('b',2), false);

    //InRange
    ASSERT_EQ(test.move('c',4), true);
    ASSERT_EQ(test.move('a',4), true);

    ASSERT_EQ(test.move('d',3), true);
    ASSERT_EQ(test.move('d',1), true);

    //OutOfRange
    EXPECT_EQ(test.move('b'-2,3), false);
    EXPECT_EQ(test.move('b'-2,1), false);

    EXPECT_EQ(test.move('a',0), false);
    EXPECT_EQ(test.move('c',0), false);
}
TEST(KnightMove, MoveRestriction) {
    int pass;
    Knight test(WHITE, 'b', 2);

    EXPECT_EQ(test.move('a',3), false);
    EXPECT_EQ(test.move('a',2), false);
    EXPECT_EQ(test.move('c',1), false);
    EXPECT_EQ(test.move('b',1), false);
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

    Piece* knightPiece1 = new Knight(WHITE, 'c', 4);
    array[2][3] = knightPiece1;

    //MoveIntoPiece
    EXPECT_EQ(test->move('c',4,array), false);
    delete knightPiece1;

    Piece* knightPiece2 = new Knight(BLACK, 'c', 4);
    array[2][3] = knightPiece2;

    //CapturePiece
    EXPECT_EQ(test->move('c',4,array), true);
    delete knightPiece2;

    delete test;
}

#endif
