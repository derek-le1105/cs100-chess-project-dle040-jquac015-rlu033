#ifndef __BOARDARRAY_H__
#define __BOARDARRAY_H__
#include <string>
#include "Piece.cpp" 

class BoardArray{
    private:
      Piece ***boardarray[][8];

    public:
        BoardArray();
        ~BoardArray();
        void ResetBoard();
	void display();
	void move(string col ,int row);
	bool check();
	bool checkmate();
	bool stalemate();
	
};
#endif
