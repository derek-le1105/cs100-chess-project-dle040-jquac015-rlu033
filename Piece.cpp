#include "Piece.h"

/*  -move() template-
bool Piece::move(char c, int y) {
    bool validMove = true;
    int x = CharToInt(c);
    x--; y--;
    //does not move
    if (x == posX && y == posY) {
        validMove = false;
    }
    //outside of range
    if (x < 1 || x > 8)
        validMove = false;
    if (y < 1 || y > 8)
        validMove = false;
    //check ACTUAL movement restrictions (Bishop in diagonals, etc.)
    //if (array == nullptr) {
        return validMove;
    //}
    //look at every space up to the one we want to move to
    //going along the movement of the piece
} */

#include <iostream>
#include <cmath>
using namespace std;
// ONLY change x or y, not both
bool Rook::move(char c, int y, Piece* array[][8]) {
    bool validMove = true;
    int x = CharToInt(c);
    x--; y--;

    if (x == posX && y == posY) {
        validMove = false;
    }

    if (x < 0 || x > 7)
        validMove = false;
    if (y < 0 || y > 7)
        validMove = false;

    //Is the given coordinate within the piece's movement restriction?
    //changing both fails
    if (x != posX && y != posY) {
        validMove = false;
    }

    //used for testing
    if (array == nullptr) {
        return validMove;
    }

    //look at every space BETWEEN the current location and the spot you want to get to
    int a = posX, b = posY;
    do {
        if ((array[a][b] != nullptr && array[a][b] != 0) && array[a][b] != this) {
            return false;
        }

        //algorithm based on how the rook moves
        if (a < x)
            a++;
        else if (a > x)
            a--;
        if (b < y)
            b++;
        else if (b > y)
            b--;
    } while (!(x == a && y == b));

    //check ending spot for capture or not
    if (array[x][y] != nullptr && array[a][b] != 0) {
        if ((array[x][y])->getAlignment() == this->getAlignment())
            validMove = false;
        //Else capture the piece
    }

    return validMove;
}


bool Knight::move(char c, int y, Piece* array[][8]) {
    bool validMove = true;
    int x = CharToInt(c);
    x--; y--;

    if (x == posX && y == posY) {
        validMove = false;
    }

    if (x < 0 || x > 7)
        validMove = false;
    if (y < 0 || y > 7)
        validMove = false;

    //one HAS to be +-1, the other HAS to be +-2
    if (!((abs(x - posX) == 1 && abs(y - posY) == 2) || (abs(x - posX) == 2 && abs(y - posY) == 1)) ){
        validMove = false;
    }

    if (array == nullptr) {
        return validMove;
    }

    //collision only needs to check the location it's going to, and it just can't be a same alignment piece
    if (array[x][y] != nullptr && array[x][y] != 0) {
        if (array[x][y]->getAlignment() == this->getAlignment())
            return false;
        //Else capture the piece
    }

    return validMove;
}

bool Bishop::move(char c, int y, Piece* array[][8]) {
    bool validMove = true;
    int x = CharToInt(c);
    x--; y--;

    if (x == posX && y == posY) {
        validMove = false;
    }

    if (x < 0 || x > 7)
        validMove = false;
    if (y < 0 || y > 7)
        validMove = false;

    //Is the given coordinate within the piece's movement restriction?
    //"slope" must be 1 or -1 (changes linearly)
    if (!(abs((static_cast<double>(x) - posX) / (static_cast<double>(y) - posY)) == 1.0)) {
        validMove = false;
    }

    //used for testing
    if (array == nullptr) {
        return validMove;
    }

    //look at every space BETWEEN the current location and the spot you want to get to
    int a = posX, b = posY;
    do {
        if ((array[a][b] != nullptr && array[a][b] != 0) && array[a][b] != this) {
            return false;
        }

        //algorithm based on how the bishop moves
        //-already checked if the final location is within the move restriction
        if (a < x)
            a++;
        else if (a > x)
            a--;
        if (b < y)
            b++;
        else if (b > y)
            b--;
    } while (!(x == a && y == b));

    //check ending spot for capture or not
    if (array[x][y] != nullptr && array[a][b] != 0) {
        if ((array[x][y])->getAlignment() == this->getAlignment())
            validMove = false;
        //Else capture the piece here
    }

    return validMove;
}

bool Queen::move(char c, int y, Piece* array[][8]) {
    bool validMove = true;
    int x = CharToInt(c);
    x--; y--;

    if (x == posX && y == posY) {
        validMove = false;
    }

    if (x < 0 || x > 7)
        validMove = false;
    if (y < 0 || y > 7)
        validMove = false;

    //Is the given coordinate within the piece's movement restriction?
    //can only change either x or y, OR "slope" must be 1 or -1 (changes linearly)
    //Rook OR Bishop
    if ((x != posX && y != posY) && !(abs((static_cast<double>(x) - posX) / (static_cast<double>(y) - posY)) == 1.0)) {
        validMove = false;
    }

    //used for testing
    if (array == nullptr) {
        return validMove;
    }

    //look at every space BETWEEN the current location and the spot you want to get to
    int a = posX, b = posY;
    do {
        if ((array[a][b] != nullptr && array[a][b] != 0) && array[a][b] != this) {
            return false;
        }

        //algorithm based on how the bishop moves, since it also encapsulates the way the rook moves
        //-already checked if the final location is within the move restriction
        if (a < x)
            a++;
        else if (a > x)
            a--;
        if (b < y)
            b++;
        else if (b > y)
            b--;
    } while (!(x == a && y == b));

    //check ending spot for capture or not
    if (array[x][y] != nullptr && array[a][b] != 0) {
        if ((array[x][y])->getAlignment() == this->getAlignment())
            validMove = false;
        //Else capture the piece here
    }

    return validMove;
}

bool King::move(char c, int y, Piece* array[][8]) {
    bool validMove = true;
    int x = CharToInt(c);
    x--; y--;

    if (x == posX && y == posY) {
        validMove = false;
    }

    if (x < 0 || x > 7)
        validMove = false;
    if (y < 0 || y > 7)
        validMove = false;

    //both have to be +-1 or 0
    if (!((abs(x - posX) <= 1 && abs(y - posY) <= 1))){
        validMove = false;
    }

    if (array == nullptr) {
        return validMove;
    }

    //collision only needs to check the location it's going to, and it just can't be a same alignment piece
    if (array[x][y] != nullptr && array[x][y] != 0) {
        if (array[x][y]->getAlignment() == this->getAlignment())
            return false;
        //Else capture the piece
    }

    return validMove;
}

/*pawn has specific moves
    can only move forward, based on alignment:
      black moves down, white moves up
    can move two spaces at the beginning:
      black on y=7 (array[x][6]), white on y=2 (array[x][1])
    can only capture moving diagonally upwards
*/
/*
 X Y1  S  B  C
 0 -1  0  1  0
 0 -1  1  1  0
 0  1  0  0  0
 0  1  1  0  0
 0 -2  1  1  0
 0  2  1  0  0
 1 -1  0  1  1
 1 -1  1  1  1
 1  1  0  0  1
 1  1  1  0  1
y = (-,B) || (+,W)
x0 & y1 & ~C        (x0 && y1 && !C)
x0 & y2 & S & ~C    (x0 && y2 && S && !C)
x1 & y1 & C          (x1 && y1 && C)
(x - posX == 0) && ((y - posY == 1 && this->getAlignment() == WHITE) || (y - posY == -1 && this->getAlignment() == BLACK)) && ~C
*/
bool Pawn::move(char c, int y, Piece* array[][8]) {
    bool validMove = true;
    int x = CharToInt(c);
    x--; y--;

    if (x == posX && y == posY) {
        validMove = false;
    }

    if (x < 0 || x > 7)
        validMove = false;
    if (y < 0 || y > 7)
        validMove = false;

    /*  x0 & y1 & ~C
        x0 & y2 & S & ~C
        x1 & y1 & C
    */
    //has to be x = 0 and +-1
    if ((x - posX == 0) && ((y - posY == 1 && this->getAlignment() == BLACK) || (y - posY == -1 && this->getAlignment() == WHITE))) {
        //cannot move forward due to collision
        if (array != nullptr) {
            if(array[x][y] != nullptr && array[x][y] != 0)
                validMove = false;
        }
    }
    //can move 2 spaces if it's at the starting position
    else if ((x - posX == 0) && ((y - posY == 2 && posY == 1 && this->getAlignment() == BLACK) || (y - posY == -2 && posY == 6 && this->getAlignment() == WHITE))) {
        //cannot move forward due to collision
        int b = posY;
        if (array != nullptr) {
            for (int i = 0; i < 2; i++) {
                if (b < y)
                    b++;
                else if (b > y)
                    b--;

                if ((array[x][b] != nullptr && array[x][b] != 0) && array[x][b] != this)
                    return false;
            }
        }
    }

    //can only move diagonally one space if there is a piece to capture
    else if ((abs(x - posX) == 1) && ((y - posY == 1 && this->getAlignment() == BLACK) || (y - posY == -1 && this->getAlignment() == WHITE)) && array != nullptr) {
        if (array[x][y] == nullptr)
            validMove = false;
        else if (array[x][y] != nullptr && array[x][y] != 0 && array[x][y]->getAlignment() == this->getAlignment())
            validMove = false;
    }
    else {
        validMove = false;
    }

    return validMove;
}