#ifndef __PIECE_H__
#define __PIECE_H__

enum Color {WHITE, BLACK};
class Piece {
  private:
    Color alignment;
  public:
    Piece(Color a, char c, int i);
    Color getAlignment() { return alignment; }
    virtual bool move(char, int) = 0;
    virtual void drawPiece() = 0;

  protected:
    int x, y;
    int CharToInt(char);
};

//move: one forward, unless it hasn't moved yet (start)
//if it hasn't moved, it can either move one or two forward
//moves diagonally upwards by capturing
class Pawn : public Piece {
  public:
    Pawn(Color a, char c, int i) : Piece(a, c, i) {}
    bool move(char, int);
    void drawPiece();
};

//moves diagonally
//another way to see it is as only on one color
class Bishop : public Piece {
  public:
    Bishop(Color a, char c, int i) : Piece(a, c, i) {}
    bool move(char, int);
    void drawPiece();
};

//moves in an L-shape and can jump over pieces
class Knight : public Piece {
  public:
    Knight(Color a, char c, int i) : Piece(a, c, i) {}
    bool move(char, int);
    void drawPiece();
};

//moves horizontally or vertically
class Rook : public Piece {
  public:
    Rook(Color a, char c, int i) : Piece(a, c, i) {}
    bool move(char, int);
    void drawPiece();
};

//moves horizontally or vertically or diagonally
class Queen : public Piece {
  public:
    Queen(Color a, char c, int i) : Piece(a, c, i) {}
    bool move(char, int);
    void drawPiece();
};

//moves one space in any direction
//can also castle with rook
class King : public Piece {
  public:
    King(Color a, char c, int i) : Piece(a, c, i) {}
    bool move(char, int);
    void drawPiece();
};
#endif

//current problems: check(), stalemate(), checkmate(), castling, en passant