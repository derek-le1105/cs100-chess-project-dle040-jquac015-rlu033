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

#endif