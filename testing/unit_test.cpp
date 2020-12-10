#include "gtest/gtest.h"
#include "Piece_test.hpp"
#include "BoardFactory_test.hpp"
#include "Board_test.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
