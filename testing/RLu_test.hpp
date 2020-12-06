#ifndef __RLU_TEST__
#define __RLU_TEST__

#include "gtest/gtest.h"
#include "../Board.hpp"
//#include "../BoardArray.h"
#include "../Piece.h"

TEST(FactoryTest, NormalTest) {
    Piece* array[8][8];
    BoardFactory b;
    b.CreateBoard(array, NORMAL);

    ASSERT_NE(array, nullptr);
    EXPECT_EQ(array[0][0]->getType(), PType::rtype);
    EXPECT_EQ(array[0][0]->getAlignment(), BLACK);
}

#endif
