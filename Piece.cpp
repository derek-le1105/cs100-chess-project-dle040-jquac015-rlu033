#include "Piece.h"
#include <cctype>
Piece::Piece(Color a, char c, int i) {
    alignment = a;
    x = CharToInt(c);
    y = i;
}

int Piece::CharToInt(char c) {
    if (isupper(c))
        return c - 'A' + 1;
    if (islower(c))
        return c - 'a' + 1;
    else
        return 0;
}

//move() template
/*
bool Piece::move(char c, int y) {
    int x = CharToInt(c);
    bool validMove = true;

    //does not move
    if (x == this->x && y == this->y) {
        validMove = false;
    }

    //outside of range
    if (x < 1 || x > 8)
        validMove = false;
    if (y < 1 || y > 8)
        validMove = false;

    return validMove;
} */

// ONLY change x or y, not both
bool Rook::move(char c, int y) {
    int x = CharToInt(c);
    bool validMove = true;

    if (x == this->x && y == this->y) {
        validMove = false;
    }

    if (x < 1 || x > 8)
        validMove = false;
    if (y < 1 || y > 8)
        validMove = false;

    //changing both fails
    if (x != this->x && y != this->y)
        validMove = false;

    return validMove;
}

/*
  x y o
  0 0 0
  0 1 1
  1 0 1
  1 1 0
*/

void Rook::drawPiece() {}