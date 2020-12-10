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
    Piece* checked;
    Piece* checKing;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            checked = boardarray[i][j];
            if(checked->getType() == ktype && checked->getAlignment() != turn){
                checKing = boardarray[i][j];
            }
        }
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            checked = boardarray[i][j];
            if(checked->move(checKing->getX(), checKing->getY(), boardarray) && checKing->getAlignment() != checked->getAlignment()){
                return true;
            }
        }
    }
    return false;
}

bool BoardArray::checkmate(){
    if(!check()){return false;}
    Piece* checked;
    Piece* checKing;
    int i, j, xsave, ysave;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            checked = boardarray[i][j];
            if(checked->getType() == ktype && checked->getAlignment() == turn){
                checKing = boardarray[i][j];
            }
        }
    }
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            checked = boardarray[i][j];
            if(checked->move(checKing->getX(), checKing->getY(), boardarray) && checKing->getAlignment() != checked->getAlignment()){
                xsave = ChartoInt(checked->getX());
                ysave = checked->getY();
            }
        }
    }
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            checked = boardarray[i][j];
            if(checked->move(xsave+'a', ysave, boardarray) && boardarray[xsave][ysave]->getAlignment() != checked->getAlignment()){
                return false;
            }
        }
    }
    xsave = ChartoInt(checKing->getX());
    ysave = checKing->getY();
    for(i=ChartoInt(checKing->getX()-1); i<ChartoInt(checKing->getX())+2; i++) {
        for(j=checKing->getY()-1; j<checKing->getY()+2; j++){
            if(checKing->move(i+'a', j, boardarray)){
                boardarray[i][j] = checKing;
                checKing = nullptr;
                check();
            }
        }
    }
    boardarray[xsave][ysave] = boardarray[i][j];
    return false;
}

bool BoardArray::stalemate(){}
