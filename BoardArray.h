#ifndef __BOARDARRAY_H__
#define __BOARDARRAY_H__
#include <string>
#include "Piece.cpp" 

class BoardArray{
    private:
      Piece *boardarray[][8];
      Color turn;
      bool bkingcheck;
      bool wkingcheck;

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
