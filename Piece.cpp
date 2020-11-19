#include "Piece.h"

/*  -move() template-
bool Piece::move(char c, int y, Piece* **array) {
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

    //check ACTUAL movement restrictions (Bishop in diagonals, etc.)

    if (array == nullptr) {
        return validMove;
    }
} */

// ONLY change x or y, not both
bool Rook::move(char c, int y, Piece* **array) {
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

    if (array == nullptr) {
        return validMove;
    }

    //look at every space BETWEEN the current location and the spot you want to get to
    int a = this->x, b = this->y;
    while (!(x == a && y == b)) {
        if (a < x)
            a++;
        else if (a > x)
            a--;
        else if (b < y)
            b++;
        else if (b > y)
            b--;

        if (array[a-1][b-1] != nullptr) {
            return false;
        }
    }

    //check ending spot for capture or not
    if (array[x][y] != nullptr) {
        if (array[x][y]->getAlignment() == this->getAlignment())
            validMove = false;
        //Capture the piece here
        else {
            b += 0;
        }
    }

    return validMove;
}

void Rook::drawPiece() {}
/*
bool Knight::move(char c, int y, Piece* **array) {
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

    //one HAS to be +-1, the other HAS to be +-2
    if (x + this->x == -1 || x + this->x == 1) {
        if (y + this->y == -2 || y + this->y == 2)
    }

    if (array == nullptr) {
        return validMove;
    }
}*/