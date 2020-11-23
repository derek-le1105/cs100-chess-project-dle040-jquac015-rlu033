#include "Piece.h"
#include "Piece_test.hpp"
#include <iostream>
using namespace std;

int main() {
    RUNALLTESTS();
    return 0;
    
    Rook r(WHITE, 'a', 1);
    char c;
    int i;

    do {
        cin >> c >> i;
        if (r.move(c,i)) {
            cout << "Valid move" << endl;
        }
        else {
            cout << "Invalid move" << endl;
        }
    } while (c != 'q');

    return 0;
}