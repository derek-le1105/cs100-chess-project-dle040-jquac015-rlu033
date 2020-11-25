#include <iostream>
#include "BoardArray.h"
#include "Piece.cpp"
using namespace std;

BoardArray::BoardArray(){ 
        boardarray = new (Piece**)[8];
        for(int i=0; i<8; i++){
                boardarray[i] = new (Piece*)[8];
        }
        for(int i=0; i<8; i++){//initialize board to be filled w/ null ptrs
                for(int j=0; j<8; j++){
                        boardarray[i][j] = NULL;
                }
        }
}

BoardArray::~BoardArray(){
        for(int i=0; i<8; i++){
                delete [] boardarray[i];
        }
        delete [] boardarray;
}

BoardArray::ResetBoard(){
        for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                        delete boardarray[i][j];
                }
        }
	//Place all white pieces
        Piece WRookR = new Rook(White, H, 1);
        boardarray[7][7] = *WRookR;
        Piece WRookL = new Rook(White, A, 1);
        boardarray[0][7] = *WRookL;
	Piece WKnightR = new Knight(White, G, 1);
	boardarray[6][7] = *WKnightR;
	Piece WKnightL = new Knight(White, B, 1);
	boardarray[1][7] = *WKnightL;
	Piece WBishopR = new Bishop(White, F, 1);
	boardarray[5][7] = *WBishopR;
	Piece WBishopL = new Bishop(White, C, 1);
	boardarray[2][7] = *WBishopL;
	Piece WKing = new King(White, E, 1);
	boardarray[4][7] = *WKing;
	Piece WQueen = new Queen(White, D, 1);
	boardarray[3][7] = *WQueen;
	Piece WPawn1 = new Pawn(White, A, 2);
	boardarray[0][6] = *WPawn1;
	Piece WPawn2 = new Pawn(White, B, 2);
	boardarray[1][6] = *WPawn2;
	Piece WPawn3 = new Pawn(White, C, 2);
	boardarray[2][6] = *WPawn3;
	Piece WPawn4 = new Pawn(White, D, 2);
	boardarray[3][6] = *WPawn4;
	Piece WPawn5 = new Pawn(White, E, 2);
	boardarray[4][6] = *WPawn5;
	Piece WPawn6 = new Pawn(White, F, 2);
	boardarray[5][6] = *WPawn6;
	Piece WPawn7 = new Pawn(White, G, 2);
	boardarray[6][6] = *WPawn7;
	Piece WPawn8 = new Pawn(White, H, 2);
	boardarray[7][6] = *WPawn8;
	//Place all black pieces
        Piece BRookR = new Rook(Black, H, 8);
        boardarray[7][0] = *BRookR;
        Piece BRookL = new Rook(Black, A, 8);
        boardarray[0][0] = *BRookL;
	Piece BKnightR = new Knight(Black, G, 8);
	boardarray[6][0] = *BKnightR;
	Piece BKnightL = new Knight(Black, B, 8);
	boardarray[1][0] = *BKnightL;
	Piece BBishopR = new Bishop(Black, F, 8);
	boardarray[5][0] = *BBishopR;
	Piece BBishopL = new Bishop(Black, C, 8);
	boardarray[2][0] = *BBishopL;
	Piece BKing = new King(Black, E, 8);
	boardarray[4][0] = *BKing;
	Piece BQueen = new Queen(Black, D, 8);
	boardarray[3][0] = *BQueen;
	Piece BPawn1 = new Pawn(Black, A, 7);
	boardarray[0][1] = *WPawn1;
	Piece BPawn2 = new Pawn(Black, B, 7);
	boardarray[1][1] = *WPawn2;
	Piece BPawn3 = new Pawn(Black, C, 7);
	boardarray[2][1] = *WPawn3;
	Piece BPawn4 = new Pawn(Black, D, 7);
	boardarray[3][1] = *WPawn4;
	Piece BPawn5 = new Pawn(Black, E, 7);
	boardarray[4][1] = *WPawn5;
	Piece BPawn6 = new Pawn(Black, F, 7);
	boardarray[5][1] = *WPawn6;
	Piece BPawn7 = new Pawn(Black, G, 7);
	boardarray[6][1] = *WPawn7;
	Piece BPawn8 = new Pawn(Black, H, 7);
	boardarray[7][1] = *WPawn8;
}
