#ifndef __BOARDARRAY_H__
#define __BOARDARRAY_H__
#include <string>
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
    //should be used to free all pointers on the board
    void FreeBoard(Piece* array[][8]) {
        int i, j;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (array[i][j] != nullptr)
                    delete array[i][j];
                array[i][j] = nullptr;
            }
        }
    }
    //changes array in argument, does not create a new one
    //array passed in MUST be all nullptr
    //Fischer-random needs test cases, and this function needs retesting
    void CreateBoard(Piece* array[][8], ChessType type = NORMAL) {
        FreeBoard(array);

	int j;

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
        
        //FISCHER-RANDOM algorithm: https://en.wikipedia.org/wiki/Fischer_random_chess_numbering_scheme#Direct_derivation
        else if (type == FISCHER) {
            int setupID, remainder;
            bool bArray[8];
            int iter, slot1, slot2;
            for (iter = 0; iter < 8; iter++) {
                bArray[iter] = false;
            }
            Piece* add;

            setupID = rand() % 960;
            // std::cout << "Fischer-Random ID: " << setupID << std::endl;  //can be commented out later
            
            //Divide by 4, remainder is Bishop1 (bright square = even (0=b, 1=d, 2=f, 3=h))
            {
                remainder = setupID % 4;
                remainder = (remainder * 2) + 1;
                
                add = new Bishop(BLACK, 'a'+remainder, 1);
                array[remainder][0] = add;
                add = new Bishop(WHITE, 'a'+remainder, 8);
                array[remainder][7] = add;
                
                bArray[remainder] = true;
                setupID /= 4;
            }

            //Divide by 4, remainder is Bishop2 (dark square = odd (0=a, 1=c, 2=e, 3=g))
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
                remainder = setupID % 6;
                iter = 0, slot1 = 0;
                //skip initial filled squares
                while (bArray[iter] == true) {
                    iter++;
                }
                while (slot1 < remainder) {
                    slot1++;
                    iter++;

                    //skip any filled squares
                    while(bArray[iter] == true) {
                        iter++;
                    }
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
                remainder = setupID;
                slot1 = 0, slot2 = 1;

                while (remainder != 0) {
                    slot2++;
                    remainder--;
                    if (slot2 == 5) {
                        slot1++;
                        slot2 = slot1 + 1;
                    }
                }

                {
                    remainder = slot1;
                    iter = 0, slot1 = 0;

                    //skip initial filled squares
                    while (bArray[iter] == true) {
                        iter++;
                    }
                    while (slot1 < remainder) {
                        slot1++;
                        iter++;

                        //skip any filled squares
                        while(bArray[iter] == true) {
                            iter++;
                        }
                    }

                    remainder = iter;
                    
                    add = new Knight(BLACK, 'a'+remainder, 1);
                    array[remainder][0] = add;
                    add = new Knight(WHITE, 'a'+remainder, 8);
                    array[remainder][7] = add;

                    bArray[remainder] = true;
                }

                {
                    remainder = --slot2; //remove one free space since it was taken by slot1
                    iter = 0, slot2 = 0;

                    //skip initial filled squares
                    while (bArray[iter] == true) {
                        iter++;
                    }
                    while (slot2 < remainder) {
                        slot2++;
                        iter++;

                        //skip any filled squares
                        while(bArray[iter] == true) {
                            iter++;
                        }
                    }

                    remainder = iter;
                    
                    add = new Knight(BLACK, 'a'+remainder, 1);
                    array[remainder][0] = add;
                    add = new Knight(WHITE, 'a'+remainder, 8);
                    array[remainder][7] = add;

                    bArray[remainder] = true;
                }
            }

            //Empty spaces: Rook - King - Rook
            {
                bool kingSpot = false;
                for (iter = 0; iter < 8; iter++) {
                    if (bArray[iter] != true) {
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
0    0000   11000
1    0001   10100
2    0010   10010
3    0011   10001
4    0100   01100
5    0101   01010
6    0110   01001
7    0111   00110
8    1000   00101
9    1001   00011
*/

class BoardArray{
    private:
      Piece *boardarray[8][8];
      Color turn;
      BoardFactory b;

      bool MoveBecomesCheck(string col, int row, string newcol, int newrow);

    public:
        BoardArray();
        ~BoardArray();
        void ResetBoard();
        void Turn();
        void display();
        char StringtoChar(string toChar);
        int ChartoInt(char toInt);
        void move(string col ,int row, string newcol, int newrow);
        bool check();
        bool checkmate();
        bool stalemate();
	
};
#endif
