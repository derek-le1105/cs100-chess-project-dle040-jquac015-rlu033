CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    testing/unit_test.cpp
    Piece.cpp
    BoardArray.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
