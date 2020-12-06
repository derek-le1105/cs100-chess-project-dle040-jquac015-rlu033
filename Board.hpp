#include "Piece.h"

enum ChessType {NORMAL, FISCHER};

class BoardFactory {
  public:
    BoardFactory(){}
    //changes array in argument, does not create a new one
    //array passed in MUST be all nullptr
    //Fischer-random needs test cases, and this function needs retesting
    void CreateBoard(Piece* array[][8], ChessType type = NORMAL) {
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

        if (type == NORMAL) {
            Piece* add;
            /*Pawn*/{
                char iter = 'a';
                for (j = 0; j < 8; j++) {
                    add = new Pawn(BLACK, iter, 7);
                    array[j][6] = add;
                    iter++;
                }

                iter = 'a';
                for (j = 0; j < 8; j++) {
                    add = new Pawn(WHITE, iter, 2);
                    array[j][1] = add;
                    iter++;
                }
            }

            /*Bishop*/{
                add = new Bishop(BLACK, 'c', 8);
                array[2][7] = add;
                add = new Bishop(BLACK, 'f', 8);
                array[5][7] = add;

                add = new Bishop(WHITE, 'c', 1);
                array[2][0] = add;
                add = new Bishop(WHITE, 'f', 1);
                array[5][0] = add;
            }

            /*Knight*/{
                add = new Knight(BLACK, 'b', 8);
                array[1][7] = add;
                add = new Knight(BLACK, 'g', 8);
                array[6][7] = add;

                add = new Knight(WHITE, 'b', 1);
                array[1][0] = add;
                add = new Knight(WHITE, 'g', 1);
                array[6][0] = add;
            }

            /*Rook*/{
                add = new Rook(BLACK, 'a', 8);
                array[0][7] = add;
                add = new Rook(BLACK, 'h', 8);
                array[7][7] = add;

                add = new Rook(WHITE, 'a', 1);
                array[0][0] = add;
                add = new Rook(WHITE, 'h', 1);
                array[7][0] = add;
            }

            /*Queen*/{
                add = new Queen(BLACK, 'd', 8);
                array[3][7] = add;

                add = new Queen(WHITE, 'd', 1);
                array[3][0] = add;
            }

            /*King*/{
                add = new King(BLACK, 'e', 8);
                array[4][7] = add;

                add = new King(WHITE, 'e', 1);
                array[4][0] = add;
            }
        }
        
        //FISCHER-RANDOM algorithm: https://en.wikipedia.org/wiki/Fischer_random_chess_numbering_scheme
        else if (type == FISCHER) {
            srand(2);
            int setupID, remainder;
            bool bArray[8];
            int iter, slot;
            for (iter = 0; i < 8; i++) {
                bArray[i] = false;
            }
            Piece* add;

            setupID = rand() % 960;
            
            //Divide by 4, remainder is Bishop1 (bright square = even)
            remainder = setupID % 4;
            remainder = (remainder * 2) + 1;
            
            add = new Bishop(WHITE, 'a'+remainder, 0);
            array[remainder][0] = add;
            add = new Bishop(BLACK, 'a'+remainder, 7);
            array[remainder][7] = add;
            
            bArray[remainder] = true;
            setupID /= 4;

            //Divide by 4, remainder is Bishop2 (bright square = odd)
            {
                remainder = setupID % 4;
                remainder = (remainder * 2);
                
                add = new Bishop(WHITE, 'a'+remainder, 0);
                array[remainder][0] = add;
                add = new Bishop(BLACK, 'a'+remainder, 7);
                array[remainder][7] = add;

                bArray[remainder] = true;
                setupID /= 4;
            }

            //Divide by 6, remainder is Queen (first free square)
            {
                //FIX THIS ALGORITHM
                remainder = setupID % 6;
                iter = 0;
                while (iter < remainder) {
                    if (bArray[iter] == false)
                        iter++;
                }
                remainder = iter;
                
                add = new Queen(WHITE, 'a'+remainder, 0);
                array[remainder][0] = add;
                add = new Queen(BLACK, 'a'+remainder, 7);
                array[remainder][7] = add;

                bArray[remainder] = true;
                setupID /= 6;
            }

            //Single digit will notate how knights are set up (based on table from website)
            {
            //uses "find the free spot" algorithm from the last one
                remainder = setupID;

                //slot1
                if (remainder <= 3) {
                    slot = 1;
                    iter = 0;
                    while (iter < slot) {
                    if (bArray[iter] == false)
                        iter++;
                    }
                    remainder = iter;
                }

                //slot2
            }

            //Empty spaces: Rook - King - Rook
            {
                bool kingSpot = false;
                
            }
        }
    }
};

/*
0000    11000
0001    10100
0010    10010
0011    10001
0100    01100
0101    01010
0110    01001
0111    00110
1000    00101
1001    00011

*/

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