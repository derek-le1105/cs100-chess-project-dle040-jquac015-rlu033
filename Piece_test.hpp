#ifndef __PIECE_TEST_HPP__
#define __PIECE_TEST_HPP__

// #include "gtest/gtest.h"
#include "Piece.h"
/*
TEST(PieceFunctions, Alignment) {
    Piece p1(WHITE, 'a', 1);
    EXPECT_EQ(p1.getAlignment(), WHITE);
}*/

#include <iostream>
using namespace std;
bool PieceFunctionsTest(int& count) {
    bool allPass = true;
    Rook r1(WHITE, 'a', 1);
    /*PieceFunctionsTest::Alignment*/ {
        cout << "  ";
        if (r1.getAlignment() != WHITE) {
            cout << "FAILED";
            allPass = false;
        }
        else
            cout << "PASSED";
        cout << ": PieceFunctions::Alignment" << endl;
        count += 1;
    }

    /*PieceFunctionsTest::MoveNoMove*/ {
        cout << "  ";
        if (r1.move('a',1)) {
            cout << "FAILED";
            allPass = false;
        }
        else
            cout << "PASSED";
        cout << ": MoveRange::MoveToSameLower" << endl;
        count += 1;
        
        cout << "  ";
        if (r1.move('A',1)) {
            cout << "FAILED" << endl;
            allPass = false;
        }
        else
            cout << "PASSED";
        cout << ": MoveRange::MoveToSameCap" << endl;
        count += 1;
    }

    /*PieceFunctionsTest::MoveRange*/ {
        cout << "  ";
        if (!r1.move('h',1)) {
            cout << "FAILED";
            allPass = false;
        }
        else
            cout << "PASSED";
        cout << ": MoveRange::MoveToH" << endl;
        count += 1;

        cout << "  ";
        if (!r1.move('a',8)) {
            cout << "FAILED";
            allPass = false;
        }
        else
            cout << "PASSED";
        cout << ": MoveRange::MoveTo8" << endl;
        count += 1;

        cout << "  ";
        if (r1.move('i',1)) {
            cout << "FAILED";
            allPass = false;
        }
        else
            cout << "PASSED";
        cout << ": MoveRange::MoveOverHorizontal" << endl;
        count += 1;

        cout << "  ";
        if (r1.move('a',0)) {
            cout << "FAILED";
            allPass = false;
        }
        else
            cout << "PASSED";
        cout << ": MoveRange::MoveUnderVertical" << endl;
        count += 1;

        cout << "  ";
        if (r1.move('a',9)) {
            cout << "FAILED";
            allPass = false;
        }
        else
            cout << "PASSED";
        cout << ": MoveRange::MoveOverVertical" << endl;
        count += 1;
    }

    // cout << "  ";
    // if (0 == 0) {
    //     cout << "FAILED";
    //     allPass = false;
    // }
    // else
    //     cout << "PASSED";
    // cout << ": FailingTest" << endl;
    // count += 1;

    if (!allPass) {
        cout << "FAILED";
    }
    else
        cout << "PASSED";
    cout << ": PieceFunctionsTest" << endl;
    cout << endl;
    return allPass;
}

bool CollisionMoveTest(int& count) {
    bool allPass = true;

    Piece* array[8][8];
    Piece* test = new Rook(WHITE, 'a', 1);
    array[0][0] = test;
    cout << test->GetCoord() << endl;
    Piece* rookPiece1 = new Rook(WHITE, 'c', 1);
    array[2][0] = rookPiece1;
    Piece* rookPiece2 = new Rook(WHITE, 'a', 3);
    array[0][2] = rookPiece2;

    bool validMove;
    /*CollisionMoveTest::ValidMoveRight*/ {
        cout << "  ";
        if (!test->move('b',1,array)) {
            cout << "FAILED";
            allPass = false;
        }
        else
            cout << "PASSED";
        cout << ": CollisionMoveTest::ValidMoveRight" << endl;
        count += 1;
    }
    /*CollisionMoveTest::MoveIntoPiece1*/ {
        cout << "  ";
        if (test->move('c',1,array)) {
            cout << "FAILED";
            allPass = false;
        }
        else
            cout << "PASSED";
        cout << ": CollisionMoveTest::MoveIntoPiece1" << endl;
        count += 1;
    }
    /*CollisionMoveTest::MovePastPiece1*/ {
        cout << "  ";
        if (test->move('d',1,array)) {
            cout << "FAILED";
            allPass = false;
        }
        else
            cout << "PASSED";
        cout << ": CollisionMoveTest::MovePastPiece1" << endl;
        count += 1;
    }

    /*CollisionMoveTest::ValidMoveUp*/ {
        cout << "  ";
        if (!test->move('a',2,array)) {
            cout << "FAILED";
            allPass = false;
        }
        else
            cout << "PASSED";
        cout << ": CollisionMoveTest::ValidMoveUp" << endl;
        count += 1;
    }
    /*CollisionMoveTest::MoveIntoPiece2*/ {
        cout << "  ";
        if (test->move('a',3,array)) {
            cout << "FAILED";
            allPass = false;
        }
        else
            cout << "PASSED";
        cout << ": CollisionMoveTest::MoveIntoPiece2" << endl;
        count += 1;
    }
    /*CollisionMoveTest::MovePastPiece2*/ {
        cout << "  ";
        if (test->move('a',4,array)) {
            cout << "FAILED";
            allPass = false;
        }
        else
            cout << "PASSED";
        cout << ": CollisionMoveTest::MovePastPiece2" << endl;
        count += 1;
    }
    
    for (int i = 0; i < 8; ++i) { delete [] array[i]; }
    delete[] array;
    delete rookPiece1;
    delete rookPiece2;
    delete test;

    if (!allPass) {
        cout << "FAILED";
    }
    else
        cout << "PASSED";
    cout << ": PieceFunctionsTest" << endl;
    cout << endl;
    return allPass;
}

void RUNALLTESTS() {
    int count = 0;
    PieceFunctionsTest(count);
    CollisionMoveTest(count);
    cout << "Passed " << count << " tests" << endl;
}

#endif