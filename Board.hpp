#include "Piece.h"
#include <iostream> //used for displaying the setupID in Fischer

enum ChessType {NORMAL, FISCHER};

class BoardFactory {
  public:
    BoardFactory(){}
    //should NOT be used if the board holds allocated data
    void ClearBoard(Piece* array[][8]) {
        int i, j;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                array[i][j] = nullptr;
            }
        }
    }
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
                pawn = new Pawn(WHITE, iter, 7);
                array[j][6] = pawn;
                iter++;
            }

            iter = 'a';
            for (j = 0; j < 8; j++) {
                pawn = new Pawn(BLACK, iter, 2);
                array[j][1] = pawn;
                iter++;
            }
        }

        if (type == NORMAL) {
            Piece* add;

            /*Bishop*/{
                add = new Bishop(WHITE, 'c', 8);
                array[2][7] = add;
                add = new Bishop(WHITE, 'f', 8);
                array[5][7] = add;

                add = new Bishop(BLACK, 'c', 1);
                array[2][0] = add;
                add = new Bishop(BLACK, 'f', 1);
                array[5][0] = add;
            }

            /*Knight*/{
                add = new Knight(WHITE, 'b', 8);
                array[1][7] = add;
                add = new Knight(WHITE, 'g', 8);
                array[6][7] = add;

                add = new Knight(BLACK, 'b', 1);
                array[1][0] = add;
                add = new Knight(BLACK, 'g', 1);
                array[6][0] = add;
            }

            /*Rook*/{
                add = new Rook(WHITE, 'a', 8);
                array[0][7] = add;
                add = new Rook(WHITE, 'h', 8);
                array[7][7] = add;

                add = new Rook(BLACK, 'a', 1);
                array[0][0] = add;
                add = new Rook(BLACK, 'h', 1);
                array[7][0] = add;
            }

            /*Queen*/{
                add = new Queen(WHITE, 'd', 8);
                array[3][7] = add;

                add = new Queen(BLACK, 'd', 1);
                array[3][0] = add;
            }

            /*King*/{
                add = new King(WHITE, 'e', 8);
                array[4][7] = add;

                add = new King(BLACK, 'e', 1);
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
            std::cout << setupID << std::endl;  //can be commented out later
            
            //Divide by 4, remainder is Bishop1 (bright square = even)
            remainder = setupID % 4;
            remainder = (remainder * 2) + 1;
            
            add = new Bishop(BLACK, 'a'+remainder, 1);
            array[remainder][0] = add;
            add = new Bishop(WHITE, 'a'+remainder, 8);
            array[remainder][7] = add;
            
            bArray[remainder] = true;
            setupID /= 4;

            //Divide by 4, remainder is Bishop2 (bright square = odd)
            {
                remainder = setupID % 4;
                remainder = (remainder * 2);
                
                add = new Bishop(BLACK, 'a'+remainder, 1);
                array[remainder][0] = add;
                add = new Bishop(WHITE, 'a'+remainder, 8);
                array[remainder][7] = add;

                bArray[remainder] = true;
                setupID /= 4;
            }

            //Divide by 6, remainder is Queen (first free square)
            {
                //CHECK THIS ALGORITHM
                remainder = setupID % 6;
                iter = 0;
                while (iter < remainder) {
                    if (bArray[iter] == false)
                        iter++;
                }
                remainder = iter;
                
                add = new Queen(BLACK, 'a'+remainder, 1);
                array[remainder][0] = add;
                add = new Queen(WHITE, 'a'+remainder, 8);
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
                else if ((remainder >= 4 && remainder <= 6) || remainder == 0) {
                    iter++;
                }
            }

            //Empty spaces: Rook - King - Rook
            {
                bool kingSpot = false;
                for (iter = 0; iter < 8; iter++) {
                    if (bArray[iter] != true && !kingSpot) {
                        if (!kingSpot) {
                            add = new Rook(BLACK, 'a'+iter, 1);
                            array[iter][0] = add;
                            add = new Rook(WHITE, 'a'+iter, 8);
                            array[iter][7] = add;
                            kingSpot = true;
                        }
                        else {
                            add = new King(BLACK, 'a'+iter, 1);
                            array[iter][0] = add;
                            add = new King(WHITE, 'a'+iter, 8);
                            array[iter][7] = add;
                            kingSpot = false;
                        }
                    }
                }
            }
        }
    }
};

/* Knight Diagram
0    11000
1    10100
2    10010
3    10001
4    01100
5    01010
6    01001
7    00110
8    00101
9    00011
*/