#include "Piece.h"

class BoardFactory {
  public:
    BoardFactory(){}
    //changes array in argument, does not create a new one
    void CreateBoard(Piece* array[][8]) {
        int i, j;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (array[i][j] != nullptr)
                    delete array[i][j];
                array[i][j] = nullptr;
            }
        }

        Piece* pawn;
        {
            char iter = 'a';
            for (j = 0; j < 8; j++) {
                pawn = new Pawn(BLACK, iter, 7);
                array[j][6] = pawn;
                iter++;
            }

            iter = 'a';
            for (j = 0; j < 8; j++) {
                pawn = new Pawn(WHITE, iter, 2);
                array[j][1] = pawn;
                iter++;
            }
        }

        Piece* bishop;
        {
            bishop = new Bishop(BLACK, 'c', 8);
            array[2][7] = bishop;
            bishop = new Bishop(BLACK, 'f', 8);
            array[5][7] = bishop;

            bishop = new Bishop(WHITE, 'c', 1);
            array[2][0] = bishop;
            bishop = new Bishop(WHITE, 'f', 1);
            array[5][0] = bishop;
        }

        Piece* knight;
        {
            knight = new Knight(BLACK, 'b', 8);
            array[1][7] = knight;
            knight = new Knight(BLACK, 'g', 8);
            array[6][7] = knight;

            knight = new Knight(WHITE, 'b', 1);
            array[1][0] = knight;
            knight = new Knight(WHITE, 'g', 1);
            array[6][0] = knight;
        }

        Piece* rook;
        {
            rook = new Rook(BLACK, 'a', 8);
            array[0][7] = rook;
            rook = new Rook(BLACK, 'h', 8);
            array[7][7] = rook;

            rook = new Rook(WHITE, 'a', 1);
            array[0][0] = rook;
            rook = new Rook(WHITE, 'h', 1);
            array[7][0] = rook;
        }

        Piece* queen;
        {
            queen = new Queen(BLACK, 'd', 8);
            array[3][7] = queen;

            queen = new Queen(WHITE, 'd', 1);
            array[3][0] = queen;
        }

        Piece* king;
        {
            king = new King(BLACK, 'e', 8);
            array[4][7] = king;

            king = new King(WHITE, 'e', 1);
            array[4][0] = king;
        }
    }
};

/* Test functionality
string Pawn::getName() {return " P";}
string Knight::getName() {return " N";}
string Rook::getName() {return " R";}
string Bishop::getName() {return " B";}
string Queen::getName() {return " Q";}
string King::getName() {return " K";}
void BoardFactoryTest() {
    BoardFactory b;
    Piece* array[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            array[i][j] = nullptr;
    }

    b.CreateBoard(array);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << i+1 << j+1;
            if (array[j][i] != nullptr)
                cout << array[j][i]->getName();
            cout << endl;
        }
    }
}
*/