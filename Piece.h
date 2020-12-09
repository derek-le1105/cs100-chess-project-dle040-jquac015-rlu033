#ifndef __PIECE_H__
#define __PIECE_H__

#include <string>
#include <cctype>
#include <SFML/Graphics/Sprite.hpp>

using namespace std;
enum Color {WHITE, BLACK};
class Piece {
private:
    Color alignment;
public:
    sf::Sprite currentSprite;

    Piece(Color a, char c, int i) {
        alignment = a;
        setCoord(c, i);
    }
    //Coords are arrayCoords
    void setCoord(char c, int i) {
        posX = CharToInt(c)-1;
        posY = i-1;
    }
    Color getAlignment() { return alignment; }
    /*std::string GetCoord() const {
        std::string final;
        final.push_back('a'+this->x);
        final.push_back('1'+this->y);
        return final;
    }*/
    virtual bool move(char, int, Piece* array[][8] = nullptr) = 0; //size of array is 64 for board

    virtual void drawPiece() = 0;

protected:
    int posX, posY;
    int CharToInt(char c) {
        if (isupper(c))
            return c - 'A' + 1;
        if (islower(c))
            return c - 'a' + 1;
        else
            return 0;
    }
};

//moves horizontally or vertically
class Rook : public Piece {
public:
    Rook(Color a, char c, int i) : Piece(a, c, i) {}
    bool move(char, int, Piece* array[][8] = nullptr);
    void drawPiece();
};

//moves in an L-shape and can jump over pieces
class Knight : public Piece {
public:
    Knight(Color a, char c, int i) : Piece(a, c, i) {}
    bool move(char, int, Piece* array[][8] = nullptr);
    void drawPiece();
};

//moves diagonally
//another way to see it is as only on one color
class Bishop : public Piece {
public:
    Bishop(Color a, char c, int i) : Piece(a, c, i) {}
    bool move(char, int, Piece* array[][8] = nullptr);
    void drawPiece();
};

//moves horizontally or vertically or diagonally
class Queen : public Piece {
public:
    Queen(Color a, char c, int i) : Piece(a, c, i) {}
    bool move(char, int, Piece* array[][8] = nullptr);
    void drawPiece();
};

//moves one space in any direction
//can also castle with rook
class King : public Piece {
public:
    King(Color a, char c, int i) : Piece(a, c, i) {}
    bool move(char, int, Piece* array[][8] = nullptr);
    void drawPiece();
};

//move: one forward, unless it hasn't moved yet (start)
//if it hasn't moved, it can either move one or two forward
//moves diagonally upwards by capturing
class Pawn : public Piece {
public:
    Pawn(Color a, char c, int i) : Piece(a, c, i) {}
    bool move(char, int, Piece* array[][8] = nullptr);
    void drawPiece();
};

#endif
