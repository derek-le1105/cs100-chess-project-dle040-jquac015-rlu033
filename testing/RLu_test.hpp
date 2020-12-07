#ifndef __RLU_TEST__
#define __RLU_TEST__

#include "gtest/gtest.h"
#include "../Board.hpp"
//#include "../BoardArray.h"
#include "../Piece.h"

TEST(FactoryTest, NormalTest) {
    Piece* array[8][8];

    BoardFactory b;
    b.ClearBoard(array);
    b.CreateBoard(array);

    ASSERT_NE(array, nullptr);

    for (int j = 1; j <= 6; j++) {
        for (int i = 0; i < 8; i++) {
            if (j == 1) {
                ASSERT_NE(array[i][j], nullptr);
                EXPECT_EQ(array[i][j]->getType(), PType::ptype);
                EXPECT_EQ(array[i][j]->getAlignment(), BLACK);
            }
            else if (j == 6) {
                ASSERT_NE(array[i][j], nullptr);
                EXPECT_EQ(array[i][j]->getType(), PType::ptype);
                EXPECT_EQ(array[i][j]->getAlignment(), WHITE);
            }
            else {
                EXPECT_EQ(array[i][j], nullptr);
            }
        }
    }

    //The black pieces
    ASSERT_NE(array[0][0], nullptr);
    EXPECT_EQ(array[0][0]->getType(), PType::rtype);
    EXPECT_EQ(array[0][0]->getAlignment(), BLACK);
    ASSERT_NE(array[1][0], nullptr);
    EXPECT_EQ(array[1][0]->getType(), PType::ntype);
    EXPECT_EQ(array[1][0]->getAlignment(), BLACK);
    ASSERT_NE(array[2][0], nullptr);
    EXPECT_EQ(array[2][0]->getType(), PType::btype);
    EXPECT_EQ(array[2][0]->getAlignment(), BLACK);
    ASSERT_NE(array[3][0], nullptr);
    EXPECT_EQ(array[3][0]->getType(), PType::qtype);
    EXPECT_EQ(array[3][0]->getAlignment(), BLACK);
    ASSERT_NE(array[4][0], nullptr);
    EXPECT_EQ(array[4][0]->getType(), PType::ktype);
    EXPECT_EQ(array[4][0]->getAlignment(), BLACK);
    ASSERT_NE(array[5][0], nullptr);
    EXPECT_EQ(array[5][0]->getType(), PType::btype);
    EXPECT_EQ(array[5][0]->getAlignment(), BLACK);
    ASSERT_NE(array[6][0], nullptr);
    EXPECT_EQ(array[6][0]->getType(), PType::ntype);
    EXPECT_EQ(array[6][0]->getAlignment(), BLACK);
    ASSERT_NE(array[7][0], nullptr);
    EXPECT_EQ(array[7][0]->getType(), PType::rtype);
    EXPECT_EQ(array[7][0]->getAlignment(), BLACK);

    //The white pieces
    ASSERT_NE(array[0][7], nullptr);
    EXPECT_EQ(array[0][7]->getType(), PType::rtype);
    EXPECT_EQ(array[0][7]->getAlignment(), WHITE);
    ASSERT_NE(array[1][7], nullptr);
    EXPECT_EQ(array[1][7]->getType(), PType::ntype);
    EXPECT_EQ(array[1][7]->getAlignment(), WHITE);
    ASSERT_NE(array[2][7], nullptr);
    EXPECT_EQ(array[2][7]->getType(), PType::btype);
    EXPECT_EQ(array[2][7]->getAlignment(), WHITE);
    ASSERT_NE(array[3][7], nullptr);
    EXPECT_EQ(array[3][7]->getType(), PType::qtype);
    EXPECT_EQ(array[3][7]->getAlignment(), WHITE);
    ASSERT_NE(array[4][7], nullptr);
    EXPECT_EQ(array[4][7]->getType(), PType::ktype);
    EXPECT_EQ(array[4][7]->getAlignment(), WHITE);
    ASSERT_NE(array[5][7], nullptr);
    EXPECT_EQ(array[5][7]->getType(), PType::btype);
    EXPECT_EQ(array[5][7]->getAlignment(), WHITE);
    ASSERT_NE(array[6][7], nullptr);
    EXPECT_EQ(array[6][7]->getType(), PType::ntype);
    EXPECT_EQ(array[6][7]->getAlignment(), WHITE);
    ASSERT_NE(array[7][7], nullptr);
    EXPECT_EQ(array[7][7]->getType(), PType::rtype);
    EXPECT_EQ(array[7][7]->getAlignment(), WHITE);

    b.FreeBoard(array);
}

TEST(FactoryTest, FischerSeed2Cycled0) {
    srand(2);

    //I needed to look at the ID first to test it
    //ID: 570
    //Layout: RNKNBBRQ
    Piece* array[8][8];
    BoardFactory b;
    b.ClearBoard(array);
    b.CreateBoard(array,FISCHER);

    ASSERT_NE(array, nullptr);

    for (int j = 1; j <= 6; j++) {
        for (int i = 0; i < 8; i++) {
            if (j == 1) {
                ASSERT_NE(array[i][j], nullptr);
                EXPECT_EQ(array[i][j]->getType(), PType::ptype);
                EXPECT_EQ(array[i][j]->getAlignment(), BLACK);
            }
            else if (j == 6) {
                ASSERT_NE(array[i][j], nullptr);
                EXPECT_EQ(array[i][j]->getType(), PType::ptype);
                EXPECT_EQ(array[i][j]->getAlignment(), WHITE);
            }
            else {
                EXPECT_EQ(array[i][j], nullptr);
            }
        }
    }

    //The black pieces
    ASSERT_NE(array[4][0], nullptr);
    EXPECT_EQ(array[4][0]->getType(), PType::btype);
    EXPECT_EQ(array[4][0]->getAlignment(), BLACK);
    ASSERT_NE(array[5][0], nullptr);
    EXPECT_EQ(array[5][0]->getType(), PType::btype);
    EXPECT_EQ(array[5][0]->getAlignment(), BLACK);
    ASSERT_NE(array[7][0], nullptr);
    EXPECT_EQ(array[7][0]->getType(), PType::qtype);
    EXPECT_EQ(array[7][0]->getAlignment(), BLACK);
    ASSERT_NE(array[1][0], nullptr);
    EXPECT_EQ(array[1][0]->getType(), PType::ntype);
    EXPECT_EQ(array[1][0]->getAlignment(), BLACK);
    ASSERT_NE(array[3][0], nullptr);
    EXPECT_EQ(array[3][0]->getType(), PType::ntype);
    EXPECT_EQ(array[3][0]->getAlignment(), BLACK);
    ASSERT_NE(array[0][0], nullptr);
    EXPECT_EQ(array[0][0]->getType(), PType::rtype);
    EXPECT_EQ(array[0][0]->getAlignment(), BLACK);
    ASSERT_NE(array[2][0], nullptr);
    EXPECT_EQ(array[2][0]->getType(), PType::ktype);
    EXPECT_EQ(array[2][0]->getAlignment(), BLACK);
    ASSERT_NE(array[6][0], nullptr);
    EXPECT_EQ(array[6][0]->getType(), PType::rtype);
    EXPECT_EQ(array[6][0]->getAlignment(), BLACK);

    //The white pieces
    ASSERT_NE(array[4][7], nullptr);
    EXPECT_EQ(array[4][7]->getType(), PType::btype);
    EXPECT_EQ(array[4][7]->getAlignment(), WHITE);
    ASSERT_NE(array[5][7], nullptr);
    EXPECT_EQ(array[5][7]->getType(), PType::btype);
    EXPECT_EQ(array[5][7]->getAlignment(), WHITE);
    ASSERT_NE(array[7][7], nullptr);
    EXPECT_EQ(array[7][7]->getType(), PType::qtype);
    EXPECT_EQ(array[7][7]->getAlignment(), WHITE);
    ASSERT_NE(array[1][7], nullptr);
    EXPECT_EQ(array[1][7]->getType(), PType::ntype);
    EXPECT_EQ(array[1][7]->getAlignment(), WHITE);
    ASSERT_NE(array[3][7], nullptr);
    EXPECT_EQ(array[3][7]->getType(), PType::ntype);
    EXPECT_EQ(array[3][7]->getAlignment(), WHITE);
    ASSERT_NE(array[0][7], nullptr);
    EXPECT_EQ(array[0][7]->getType(), PType::rtype);
    EXPECT_EQ(array[0][7]->getAlignment(), WHITE);
    ASSERT_NE(array[2][7], nullptr);
    EXPECT_EQ(array[2][7]->getType(), PType::ktype);
    EXPECT_EQ(array[2][7]->getAlignment(), WHITE);
    ASSERT_NE(array[6][7], nullptr);
    EXPECT_EQ(array[6][7]->getType(), PType::rtype);
    EXPECT_EQ(array[6][7]->getAlignment(), WHITE);

    b.FreeBoard(array);
}
TEST(FactoryTest, FischerSeed2Cycled1) {
    //I needed to look at the ID first to test it
    //ID: 319
    //Layout: NQRKRNBB
    Piece* array[8][8];
    BoardFactory b;
    b.ClearBoard(array);
    b.CreateBoard(array,FISCHER);

    ASSERT_NE(array, nullptr);

    for (int j = 1; j <= 6; j++) {
        for (int i = 0; i < 8; i++) {
            if (j == 1) {
                ASSERT_NE(array[i][j], nullptr);
                EXPECT_EQ(array[i][j]->getType(), PType::ptype);
                EXPECT_EQ(array[i][j]->getAlignment(), BLACK);
            }
            else if (j == 6) {
                ASSERT_NE(array[i][j], nullptr);
                EXPECT_EQ(array[i][j]->getType(), PType::ptype);
                EXPECT_EQ(array[i][j]->getAlignment(), WHITE);
            }
            else {
                EXPECT_EQ(array[i][j], nullptr);
            }
        }
    }

    //The black pieces
    ASSERT_NE(array[6][0], nullptr);
    EXPECT_EQ(array[6][0]->getType(), PType::btype);
    EXPECT_EQ(array[6][0]->getAlignment(), BLACK);
    ASSERT_NE(array[7][0], nullptr);
    EXPECT_EQ(array[7][0]->getType(), PType::btype);
    EXPECT_EQ(array[7][0]->getAlignment(), BLACK);
    ASSERT_NE(array[1][0], nullptr);
    EXPECT_EQ(array[1][0]->getType(), PType::qtype);
    EXPECT_EQ(array[1][0]->getAlignment(), BLACK);
    ASSERT_NE(array[0][0], nullptr);
    EXPECT_EQ(array[0][0]->getType(), PType::ntype);
    EXPECT_EQ(array[0][0]->getAlignment(), BLACK);
    ASSERT_NE(array[5][0], nullptr);
    EXPECT_EQ(array[5][0]->getType(), PType::ntype);
    EXPECT_EQ(array[5][0]->getAlignment(), BLACK);
    ASSERT_NE(array[2][0], nullptr);
    EXPECT_EQ(array[2][0]->getType(), PType::rtype);
    EXPECT_EQ(array[2][0]->getAlignment(), BLACK);
    ASSERT_NE(array[3][0], nullptr);
    EXPECT_EQ(array[3][0]->getType(), PType::ktype);
    EXPECT_EQ(array[3][0]->getAlignment(), BLACK);
    ASSERT_NE(array[4][0], nullptr);
    EXPECT_EQ(array[4][0]->getType(), PType::rtype);
    EXPECT_EQ(array[4][0]->getAlignment(), BLACK);

    //The white pieces
    ASSERT_NE(array[6][7], nullptr);
    EXPECT_EQ(array[6][7]->getType(), PType::btype);
    EXPECT_EQ(array[6][7]->getAlignment(), WHITE);
    ASSERT_NE(array[7][7], nullptr);
    EXPECT_EQ(array[7][7]->getType(), PType::btype);
    EXPECT_EQ(array[7][7]->getAlignment(), WHITE);
    ASSERT_NE(array[1][7], nullptr);
    EXPECT_EQ(array[1][7]->getType(), PType::qtype);
    EXPECT_EQ(array[1][7]->getAlignment(), WHITE);
    ASSERT_NE(array[0][7], nullptr);
    EXPECT_EQ(array[0][7]->getType(), PType::ntype);
    EXPECT_EQ(array[0][7]->getAlignment(), WHITE);
    ASSERT_NE(array[5][7], nullptr);
    EXPECT_EQ(array[5][7]->getType(), PType::ntype);
    EXPECT_EQ(array[5][7]->getAlignment(), WHITE);
    ASSERT_NE(array[2][7], nullptr);
    EXPECT_EQ(array[2][7]->getType(), PType::rtype);
    EXPECT_EQ(array[2][7]->getAlignment(), WHITE);
    ASSERT_NE(array[3][7], nullptr);
    EXPECT_EQ(array[3][7]->getType(), PType::ktype);
    EXPECT_EQ(array[3][7]->getAlignment(), WHITE);
    ASSERT_NE(array[4][7], nullptr);
    EXPECT_EQ(array[4][7]->getType(), PType::rtype);
    EXPECT_EQ(array[4][7]->getAlignment(), WHITE);

    b.FreeBoard(array);
}
TEST(FactoryTest, FischerSeed2Cycled2) {
    //I needed to look at the ID first to test it
    //ID: 68
    //Layout: NBBNRKQR
    Piece* array[8][8];
    BoardFactory b;
    b.ClearBoard(array);
    b.CreateBoard(array,FISCHER);

    ASSERT_NE(array, nullptr);

    for (int j = 1; j <= 6; j++) {
        for (int i = 0; i < 8; i++) {
            if (j == 1) {
                ASSERT_NE(array[i][j], nullptr);
                EXPECT_EQ(array[i][j]->getType(), PType::ptype);
                EXPECT_EQ(array[i][j]->getAlignment(), BLACK);
            }
            else if (j == 6) {
                ASSERT_NE(array[i][j], nullptr);
                EXPECT_EQ(array[i][j]->getType(), PType::ptype);
                EXPECT_EQ(array[i][j]->getAlignment(), WHITE);
            }
            else {
                EXPECT_EQ(array[i][j], nullptr);
            }
        }
    }

    //The black pieces
    ASSERT_NE(array[1][0], nullptr);
    EXPECT_EQ(array[1][0]->getType(), PType::btype);
    EXPECT_EQ(array[1][0]->getAlignment(), BLACK);
    ASSERT_NE(array[2][0], nullptr);
    EXPECT_EQ(array[2][0]->getType(), PType::btype);
    EXPECT_EQ(array[2][0]->getAlignment(), BLACK);
    ASSERT_NE(array[6][0], nullptr);
    EXPECT_EQ(array[6][0]->getType(), PType::qtype);
    EXPECT_EQ(array[6][0]->getAlignment(), BLACK);
    ASSERT_NE(array[0][0], nullptr);
    EXPECT_EQ(array[0][0]->getType(), PType::ntype);
    EXPECT_EQ(array[0][0]->getAlignment(), BLACK);
    ASSERT_NE(array[3][0], nullptr);
    EXPECT_EQ(array[3][0]->getType(), PType::ntype);
    EXPECT_EQ(array[3][0]->getAlignment(), BLACK);
    ASSERT_NE(array[4][0], nullptr);
    EXPECT_EQ(array[4][0]->getType(), PType::rtype);
    EXPECT_EQ(array[4][0]->getAlignment(), BLACK);
    ASSERT_NE(array[5][0], nullptr);
    EXPECT_EQ(array[5][0]->getType(), PType::ktype);
    EXPECT_EQ(array[5][0]->getAlignment(), BLACK);
    ASSERT_NE(array[7][0], nullptr);
    EXPECT_EQ(array[7][0]->getType(), PType::rtype);
    EXPECT_EQ(array[7][0]->getAlignment(), BLACK);

    //The white pieces
    ASSERT_NE(array[1][7], nullptr);
    EXPECT_EQ(array[1][7]->getType(), PType::btype);
    EXPECT_EQ(array[1][7]->getAlignment(), WHITE);
    ASSERT_NE(array[2][7], nullptr);
    EXPECT_EQ(array[2][7]->getType(), PType::btype);
    EXPECT_EQ(array[2][7]->getAlignment(), WHITE);
    ASSERT_NE(array[6][7], nullptr);
    EXPECT_EQ(array[6][7]->getType(), PType::qtype);
    EXPECT_EQ(array[6][7]->getAlignment(), WHITE);
    ASSERT_NE(array[0][7], nullptr);
    EXPECT_EQ(array[0][7]->getType(), PType::ntype);
    EXPECT_EQ(array[0][7]->getAlignment(), WHITE);
    ASSERT_NE(array[3][7], nullptr);
    EXPECT_EQ(array[3][7]->getType(), PType::ntype);
    EXPECT_EQ(array[3][7]->getAlignment(), WHITE);
    ASSERT_NE(array[4][7], nullptr);
    EXPECT_EQ(array[4][7]->getType(), PType::rtype);
    EXPECT_EQ(array[4][7]->getAlignment(), WHITE);
    ASSERT_NE(array[5][7], nullptr);
    EXPECT_EQ(array[5][7]->getType(), PType::ktype);
    EXPECT_EQ(array[5][7]->getAlignment(), WHITE);
    ASSERT_NE(array[7][7], nullptr);
    EXPECT_EQ(array[7][7]->getType(), PType::rtype);
    EXPECT_EQ(array[7][7]->getAlignment(), WHITE);

    b.FreeBoard(array);
}

//hehe I kinda can't test this yet...
//I need to know how the board is created
/*
TEST(Stalemate, StartingPosition) {
    Piece* array[8][8];
    BoardFactory b;
    b.ClearBoard(array);
    b.CreateBoard(array);

    ASSERT_NE(array, nullptr);
    EXPECT_EQ()
}*/

#endif
