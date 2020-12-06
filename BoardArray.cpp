#include <iostream>
#include "BoardArray.h"
#include "Piece.cpp"
#include "board.hpp"
#include "string.h"
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

void BoardArray::ResetBoard(){
    CreateBoard(boardarray, NORMAL);
    turn = WHITE;
}

void BoardArray::Turn(){
    if(turn == WHITE){
        turn = BLACK;
    }else if(turn == BLACK){
        turn = WHITE;
    }
}

void BoardArray::display(){}

char BoardArray::StringtoChar(string toChar){
    int len = toChar.length();
    char ret[len+1];
    strcpy(ret, toChar.c_str());
    return ret[0];
}

int BoardArray::ChartoInt(char toInt){
    int ret = toInt;
    if(ret>=65 && ret<=90){
        return ret-65;
    }else if(ret>=97 && ret<=122){
        return ret-97;
    }
}

void BoardArray::move(string col ,int row, string newcol, int newrow){
    int temp1 = ChartoInt(StringtoChar(col));
    int temp2 = ChartoInt(StringtoChar(newcol));
    if(boardarray[temp1][row].getalignment()==turn){
        if(boardarray[temp1][row].move(StringtoChar(newcol), newrow, boardarray)){
            boardarray[temp2][newrow] = boardarray[temp1][row];
            boardarray[temp1][row] = nullptr;
            return;
        }
    }
    cout << "invalid move\n";
    return;
}

bool BoardArray::check(){
    Piece* findking = new King(turn, 'z', 20);
    int poskingx;
    int poskingy;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(typeid(boardarray[i][j]) == typeid(findking)){
                poskingx = i;
                poskingy = j;
            }
        }
    }
    delete findking;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(boardarray[i][j].move(poskingx+65, poskingy, boardarray){
                return true;
            }
        }
    }
    return false;
}

bool BoardArray::checkmate(){}

bool BoardArray::stalemate(){
    int i, j; //iterate through the board
    char a; int b; //iterate through possible moves
    Piece* currPiece;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            currPiece = boardarray[i][j];

            if (currPiece != nullptr) {
                //Pawns have 4 possible moves, but in either direction based on alignment
                if (currPiece->getType() == PType::ptype) {
                    if (currPiece->move(a,currPiece->getY()-1, boardarray) || (currPiece->move(a,currPiece->getY()+1, boardarray))) {
                        return false;
                    }
                }

                //Knights have 8 possible moves
                else if (currPiece->getType() == PType::ntype) {
                    a = currPiece->getX(); b = currPiece->getY();
                    if (currPiece->move(a-2, b-1, boardarray) || (currPiece->move(a-2, b+1, boardarray)) { return false; }
                    else if (currPiece->move(a-1, b-2, boardarray) || (currPiece->move(a-1, b+2, boardarray)) { return false; }
                    else if (currPiece->move(a+1, b-2, boardarray) || (currPiece->move(a+1, b+2, boardarray)) { return false; }
                    else if (currPiece->move(a+2, b-1, boardarray) || (currPiece->move(a+2, b+1, boardarray)) { return false; }
                }
                else if (boardarray[i][j]->getType() == PType::btype)
            }
        }

    }

    return true;
}
