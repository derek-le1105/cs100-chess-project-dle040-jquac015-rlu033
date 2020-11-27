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
    //Straight lines
    Rook test(WHITE, 'a',1);

    EXPECT_EQ(test.move('a',3), true);
    EXPECT_EQ(test.move('c',1), true);

    EXPECT_EQ(test.move('b',3), false);
    EXPECT_EQ(test.move('c',2), false);
    EXPECT_EQ(test.move('b',7), false);
}
//Collision was basically already tested for Rook

TEST(KnightMove, PieceMove) {
    Knight test(WHITE, 'd', 4);

    //NoMove
    ASSERT_EQ(test.move('d',4), false);

    //InRange
    ASSERT_EQ(test.move('b',3), true);
    ASSERT_EQ(test.move('b',5), true);

    ASSERT_EQ(test.move('f',3), true);
    ASSERT_EQ(test.move('f',5), true);

    ASSERT_EQ(test.move('c',2), true);
    ASSERT_EQ(test.move('e',2), true);

    ASSERT_EQ(test.move('c',6), true);
    ASSERT_EQ(test.move('e',6), true);

    Knight test2(WHITE, 'b', 2);
    //OutOfRange
    EXPECT_EQ(test.move('b'-2,3), false);
    EXPECT_EQ(test.move('b'-2,1), false);

    EXPECT_EQ(test.move('a',0), false);
    EXPECT_EQ(test.move('c',0), false);
}
TEST(KnightMove, MoveRestriction) {
    //L-shapes
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

TEST(BishopMove, PieceMove) {
    Bishop test(WHITE, 'c',3);

    //NoMove
    EXPECT_EQ(test.move('c',3), false);

    //InRange
    ASSERT_EQ(test.move('a',1), true);
    ASSERT_EQ(test.move('b',4), true);

    ASSERT_EQ(test.move('e',5), true);
    ASSERT_EQ(test.move('d',2), true);

    //OutOfRange
    EXPECT_EQ(test.move('c'-3,0), false);
    EXPECT_EQ(test.move('c'-3,6), false);

    EXPECT_EQ(test.move('i',9), false);
    EXPECT_EQ(test.move('f',0), false);
}
TEST(BishopMove, MoveRestriction) {
    Bishop test(WHITE, 'd', 4);

    EXPECT_EQ(test.move('d',3), false);
    EXPECT_EQ(test.move('d',5), false);
    EXPECT_EQ(test.move('c',4), false);
    EXPECT_EQ(test.move('e',4), false);

    //(used Knight test)
    EXPECT_EQ(test.move('b',3), false);
    EXPECT_EQ(test.move('b',5), false);

    EXPECT_EQ(test.move('f',3), false);
    EXPECT_EQ(test.move('f',5), false);

    EXPECT_EQ(test.move('c',2), false);
    EXPECT_EQ(test.move('e',2), false);

    EXPECT_EQ(test.move('c',6), false);
    EXPECT_EQ(test.move('e',6), false);
}
TEST(BishopMove, CollisionTest) {
    Piece* array[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            array[i][j] = nullptr;
        }
    }

    Piece* test = new Bishop(WHITE, 'd', 4);
    array[3][3] = test;

    /*BishopCollisionTest::MoveUpRight*/{
        Piece* bishopPiece1 = new Bishop(WHITE, 'f', 6);
        array[5][5] = bishopPiece1;

        //MoveValid
        EXPECT_EQ(test->move('e',5,array), true);
        //MoveIntoPiece
        EXPECT_EQ(test->move('f',6,array), false);
        //MovePastPiece
        EXPECT_EQ(test->move('g',7,array), false);
        delete bishopPiece1;

        Piece* bishopPiece2 = new Bishop(BLACK, 'f', 6);
        array[5][5] = bishopPiece2;

        //MoveValid
        EXPECT_EQ(test->move('e',5,array), true);
        //MoveIntoPiece
        EXPECT_EQ(test->move('f',6,array), true);
        //MovePastPiece
        EXPECT_EQ(test->move('g',7,array), false);
        
        delete bishopPiece2;
        array[5][5] = nullptr;
    }

    /*BishopCollisionTest::MoveDownLeft*/{
        Piece* bishopPiece1 = new Bishop(WHITE, 'b', 2);
        array[1][1] = bishopPiece1;

        //MoveValid
        EXPECT_EQ(test->move('c',3,array), true);
        //MoveIntoPiece
        EXPECT_EQ(test->move('b',2,array), false);
        //MovePastPiece
        EXPECT_EQ(test->move('a',1,array), false);
        delete bishopPiece1;

        Piece* bishopPiece2 = new Bishop(BLACK, 'b', 2);
        array[1][1] = bishopPiece2;

        //MoveValid
        EXPECT_EQ(test->move('c',3,array), true);
        //MoveIntoPiece
        EXPECT_EQ(test->move('b',2,array), true);
        //MovePastPiece
        EXPECT_EQ(test->move('a',1,array), false);
        delete bishopPiece2;
        array[1][1] = nullptr;
    }

    delete test;
    array[3][3] = nullptr;
}

//literally just Rook+Bishop
TEST(QueenMove, PieceMove) {
    Queen test(WHITE, 'd', 4);

    //NoMove
    ASSERT_EQ(test.move('d',4), false);

    //RookInRange
    ASSERT_EQ(test.move('a',4), true);
    ASSERT_EQ(test.move('h',4), true);

    ASSERT_EQ(test.move('d',1), true);
    ASSERT_EQ(test.move('d',8), true);

    //RookOutOfRange
    EXPECT_EQ(test.move('+',4), false);
    EXPECT_EQ(test.move('i',4), false);

    EXPECT_EQ(test.move('d',0), false);
    EXPECT_EQ(test.move('d',9), false);

    //BishopInRange
    ASSERT_EQ(test.move('a',1), true);
    ASSERT_EQ(test.move('b',6), true);

    ASSERT_EQ(test.move('g',7), true);
    ASSERT_EQ(test.move('f',2), true);

    //BishopOutOfRange
    EXPECT_EQ(test.move('d'-4,0), false);
    EXPECT_EQ(test.move('d'-4,8), false);

    EXPECT_EQ(test.move('i',9), false);
    EXPECT_EQ(test.move('h',0), false);
}
//again, I just tested with Knight test
TEST(QueenMove, MoveRestriction) {
    Queen test(WHITE, 'd', 4);

    //(used Knight test)
    EXPECT_EQ(test.move('b',3), false);
    EXPECT_EQ(test.move('b',5), false);

    EXPECT_EQ(test.move('f',3), false);
    EXPECT_EQ(test.move('f',5), false);

    EXPECT_EQ(test.move('c',2), false);
    EXPECT_EQ(test.move('e',2), false);

    EXPECT_EQ(test.move('c',6), false);
    EXPECT_EQ(test.move('e',6), false);
}

TEST(QueenMove, CollisionTest) {
    Piece* array[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            array[i][j] = nullptr;
        }
    }

    Piece* test = new Queen(WHITE, 'd', 4);
    array[3][3] = test;

    /*RookMovementTest*/{
        Piece* rookPiece1 = new Rook(WHITE, 'f', 4);
        array[5][3] = rookPiece1;
        //MoveRightValid
        ASSERT_EQ(test->move('e',4,array), true);
        //MoveRightIntoPiece
        EXPECT_EQ(test->move('f',4,array), false);
        //MoveRightPastPiece
        EXPECT_EQ(test->move('g',4,array), false);

        delete rookPiece1;

        Piece* rookPiece3 = new Rook(BLACK, 'd', 6);
        array[3][5] = rookPiece3;
        //MoveUpValid
        ASSERT_EQ(test->move('d',5,array), true);
        //MoveUpIntoPiece
        EXPECT_EQ(test->move('d',6,array), true);
        //MoveUpPastPiece
        EXPECT_EQ(test->move('d',7,array), false);

        delete rookPiece3;
        array[3][5] = nullptr;
    }

    /*BishopCollisionTest::MoveUpRight*/{
        Piece* bishopPiece1 = new Bishop(WHITE, 'f', 6);
        array[5][5] = bishopPiece1;

        //MoveValid
        EXPECT_EQ(test->move('e',5,array), true);
        //MoveIntoPiece
        EXPECT_EQ(test->move('f',6,array), false);
        //MovePastPiece
        EXPECT_EQ(test->move('g',7,array), false);
        delete bishopPiece1;

        Piece* bishopPiece2 = new Bishop(BLACK, 'f', 6);
        array[5][5] = bishopPiece2;

        //MoveValid
        EXPECT_EQ(test->move('e',5,array), true);
        //MoveIntoPiece
        EXPECT_EQ(test->move('f',6,array), true);
        //MovePastPiece
        EXPECT_EQ(test->move('g',7,array), false);
        
        delete bishopPiece2;
        array[5][5] = nullptr;
    }

    /*BishopCollisionTest::MoveDownLeft*/{
        Piece* bishopPiece1 = new Bishop(WHITE, 'b', 2);
        array[1][1] = bishopPiece1;

        //MoveValid
        EXPECT_EQ(test->move('c',3,array), true);
        //MoveIntoPiece
        EXPECT_EQ(test->move('b',2,array), false);
        //MovePastPiece
        EXPECT_EQ(test->move('a',1,array), false);
        delete bishopPiece1;

        Piece* bishopPiece2 = new Bishop(BLACK, 'b', 2);
        array[1][1] = bishopPiece2;

        //MoveValid
        EXPECT_EQ(test->move('c',3,array), true);
        //MoveIntoPiece
        EXPECT_EQ(test->move('b',2,array), true);
        //MovePastPiece
        EXPECT_EQ(test->move('a',1,array), false);
        delete bishopPiece2;
        array[1][1] = nullptr;
    }

    delete test;
    array[3][3] = nullptr;
}

TEST(KingMove, PieceMoveTest) {
    King test(WHITE, 'b',1);

    //NoMove
    EXPECT_EQ(test.move('b',1), false);

    //KingInRange
    ASSERT_EQ(test.move('a',1), true);
    ASSERT_EQ(test.move('a',2), true);
    ASSERT_EQ(test.move('b',2), true);
    ASSERT_EQ(test.move('c',2), true);
    ASSERT_EQ(test.move('c',1), true);

    //KingOutOfRange
    EXPECT_EQ(test.move('a',0), false);
    EXPECT_EQ(test.move('b',0), false);
    EXPECT_EQ(test.move('c',0), false);
}
TEST(KingMove, MoveRestriction) {
    King test(WHITE, 'd',4);

    EXPECT_EQ(test.move('b',3), false);
    EXPECT_EQ(test.move('b',4), false);
    EXPECT_EQ(test.move('b',5), false);
    EXPECT_EQ(test.move('c',6), false);
    EXPECT_EQ(test.move('d',6), false);
    EXPECT_EQ(test.move('e',6), false);
    EXPECT_EQ(test.move('f',5), false);
    EXPECT_EQ(test.move('f',4), false);
    EXPECT_EQ(test.move('f',3), false);
    EXPECT_EQ(test.move('c',2), false);
    EXPECT_EQ(test.move('d',2), false);
    EXPECT_EQ(test.move('e',2), false);
}
TEST(KingMove, CollisionTest) {
    Piece* array[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            array[i][j] = nullptr;
        }
    }

    Piece* test = new King(WHITE, 'd', 4);
    array[3][3] = test;

    Piece* p1 = new Rook(WHITE, 'c',5);
    array[2][4] = p1;
    EXPECT_EQ(test->move('c',5,array), false);
    delete p1;
    array[2][4] = nullptr;

    Piece* p2 = new Knight(BLACK, 'd',5);
    array[3][4] = p2;
    EXPECT_EQ(test->move('d',5,array), true);
    delete p2;
    array[3][4] = nullptr;

    Piece* p3 = new Bishop(WHITE, 'd',3);
    array[3][2] = p3;
    EXPECT_EQ(test->move('d',3,array), false);
    delete p3;
    array[3][2] = nullptr;

    Piece* p4 = new Queen(BLACK, 'e',3);
    array[4][2] = p4;
    EXPECT_EQ(test->move('e',3,array), true);
    delete p4;
    array[4][2] = nullptr;

    delete test;
}

TEST(PawnMove, PieceMove) {
    Pawn test(WHITE, 'd', 2);

    //NoMove
    ASSERT_EQ(test.move('d',2), false);

    //PawnInRange
    ASSERT_EQ(test.move('d',3), true);
    ASSERT_EQ(test.move('d',4), true);

    Pawn test2(WHITE, 'd', 8);
    //PawnOutOfRange
    EXPECT_EQ(test.move('d',9), false);
}
TEST(PawnMove, MoveRestriction) {
    Pawn test(WHITE, 'd', 2);

    //PawnInRange
    ASSERT_EQ(test.move('d',3), true);
    ASSERT_EQ(test.move('d',4), true);

    //FAIL
    EXPECT_EQ(test.move('d',5), false);
    EXPECT_EQ(test.move('c',2), false);
    EXPECT_EQ(test.move('e',2), false);
    EXPECT_EQ(test.move('d',1), false);

    EXPECT_EQ(test.move('c',3), false);
    EXPECT_EQ(test.move('e',3), false);

    Pawn test2(BLACK, 'd', 7);

    //PawnInRange
    ASSERT_EQ(test2.move('d',6), true);
    ASSERT_EQ(test2.move('d',5), true);

    //FAIL
    EXPECT_EQ(test2.move('d',4), false);
    EXPECT_EQ(test2.move('c',7), false);
    EXPECT_EQ(test2.move('e',7), false);
    EXPECT_EQ(test2.move('d',8), false);

    EXPECT_EQ(test2.move('c',6), false);
    EXPECT_EQ(test2.move('e',6), false);
}
TEST(PawnMove, CollisionTest) {
    Piece* array[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            array[i][j] = nullptr;
        }
    }

    Piece* test = new Pawn(WHITE, 'd', 2);
    array[3][1] = test;

    /*White: moving upwards*/{
        Piece* p1 = new Rook(WHITE, 'd',3);
        array[3][2] = p1;
        EXPECT_EQ(test->move('d',3,array), false);
        EXPECT_EQ(test->move('d',4,array), false);
        delete p1;
        array[3][2] = nullptr;

        p1 = new Pawn(WHITE, 'd', 4);
        array[3][3] = p1;
        EXPECT_EQ(test->move('d',3,array), true);
        EXPECT_EQ(test->move('d',4,array), false);
        delete p1;
        array[3][3] == nullptr;

        Piece* p2 = new Rook(BLACK, 'd',3);
        array[3][2] = p2;
        EXPECT_EQ(test->move('d',3,array), false);
        EXPECT_EQ(test->move('d',4,array), false);
        delete p2;
        array[3][2] = nullptr;

        p2 = new Pawn(BLACK, 'd', 4);
        array[3][3] = p2;
        EXPECT_EQ(test->move('d',3,array), true);
        EXPECT_EQ(test->move('d',4,array), false);
        delete p2;
        array[3][3] == nullptr;
    }
    delete test;
    array[3][1] == nullptr;

    test = new Pawn(WHITE, 'd', 4);
    array[3][3] = test;

    /*White: Capturing*/{
        Piece* p1 = new Rook(BLACK, 'c',5);
        array[2][4] = p1;
        EXPECT_EQ(test->move('d',5,array), true);
        EXPECT_EQ(test->move('d',6,array), false);

        EXPECT_EQ(test->move('c',5,array), true);
        delete p1;
        array[2][4] = nullptr;

        p1 = new Pawn(WHITE, 'c', 5);
        array[2][3] = p1;
        EXPECT_EQ(test->move('d',5,array), true);
        EXPECT_EQ(test->move('d',6,array), false);

        EXPECT_EQ(test->move('c',5,array), false);
        delete p1;
        array[2][4] = nullptr;
    }
    delete test;
    array[3][3] = test;

    test = new Pawn(BLACK, 'd', 7);
    array[3][6] = test;

    /*Black: moving downwards*/{
        Piece* p1 = new Rook(BLACK, 'd',6);
        array[3][5] = p1;
        EXPECT_EQ(test->move('d',6,array), false);
        EXPECT_EQ(test->move('d',5,array), false);
        delete p1;
        array[3][5] = nullptr;

        p1 = new Pawn(WHITE, 'd', 5);
        array[3][4] = p1;
        EXPECT_EQ(test->move('d',6,array), true);
        EXPECT_EQ(test->move('d',5,array), false);
        delete p1;
        array[3][4] == nullptr;

        Piece* p2 = new Rook(BLACK, 'd',6);
        array[3][5] = p2;
        EXPECT_EQ(test->move('d',6,array), false);
        EXPECT_EQ(test->move('d',5,array), false);
        delete p2;
        array[3][5] = nullptr;

        p2 = new Pawn(BLACK, 'd', 5);
        array[3][4] = p2;
        EXPECT_EQ(test->move('d',6,array), true);
        EXPECT_EQ(test->move('d',5,array), false);
        delete p2;
        array[3][4] == nullptr;
    }
    delete test;
    array[3][6] == nullptr;

    test = new Pawn(BLACK, 'd', 4);
    array[3][3] = test;

    /*Black: Capturing*/{
        Piece* p1 = new Rook(WHITE, 'c',3);
        array[2][2] = p1;
        EXPECT_EQ(test->move('d',3,array), true);
        EXPECT_EQ(test->move('d',2,array), false);

        EXPECT_EQ(test->move('c',3,array), true);
        delete p1;
        array[2][2] = nullptr;

        p1 = new Pawn(BLACK, 'c', 3);
        array[2][2] = p1;
        EXPECT_EQ(test->move('d',3,array), true);
        EXPECT_EQ(test->move('d',2,array), false);

        EXPECT_EQ(test->move('c',3,array), false);
        delete p1;
        array[2][2] = nullptr;
    }
    delete test;
    array[3][3] = nullptr;
}

#endif
