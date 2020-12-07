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

//needs to also not put the king in check (relies on check())
bool BoardArray::stalemate() {
    if (check()) { return false; }

    int i, j; //iterate through the board
    char a; int b; //iterate through possible moves
    Piece* currPiece;
    bool passCheck;
    string fromStr, toStr;
    int fromInt, toInt;

    for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {

        currPiece = boardarray[i][j];

        if (currPiece != nullptr) {
            //Pawns have 4 possible moves, but in either direction based on alignment
            if (currPiece->getType() == PType::ptype) {

                for (b = currPiece->getY()-1; b <= currPiece->getY()+1; b = b+2) {
                    for (a = currPiece->getX()-1; a <= currPiece->getY()+1; a++) {
                        if (currPiece->move(a,b, boardarray)) {
                            fromStr = {currPiece->getX()};
                            fromInt = currPiece->getY();
                            toStr = {a};
                            toInt = b;

                            if (!this->MoveBecomesCheck(fromStr, fromInt, toStr, toInt))
                                return false;
                        }
                    }
                }

                if (currPiece->move(a,b-2, boardarray) || currPiece->move(a,b+2, boardarray)) {
                    fromStr = {currPiece->getX()};
                    fromInt = currPiece->getY();
                    toStr = {a};
                    toInt = b;

                    if (!this->MoveBecomesCheck(fromStr, fromInt, toStr, toInt))
                        return false;
                }
            }

            //Knights have 8 possible moves
            else if (currPiece->getType() == PType::ntype) {

                for (b = currPiece->getY()-2; b <= currPiece->getY()+2; b = b+4) {
                    for (a = currPiece->getX()-1; a <= currPiece->getY()+1; a = a+2) {
                        if (currPiece->move(a,b, boardarray)) {
                            fromStr = {currPiece->getX()};
                            fromInt = currPiece->getY();
                            toStr = {a};
                            toInt = b;

                            if (!this->MoveBecomesCheck(fromStr, fromInt, toStr, toInt))
                                return false;
                        }
                    }
                }
                for (b = currPiece->getY()-1; b <= currPiece->getY()+1; b = b+2) {
                    for (a = currPiece->getX()-2; a <= currPiece->getY()+2; a = a+4) {
                        if (currPiece->move(a,b, boardarray)) {
                            fromStr = {currPiece->getX()};
                            fromInt = currPiece->getY();
                            toStr = {a};
                            toInt = b;

                            if (!this->MoveBecomesCheck(fromStr, fromInt, toStr, toInt))
                                return false;
                        }
                    }
                }
            }

            //Bishops only need one space in diagonals
            else if (currPiece->getType() == PType::btype) {

                for (b = currPiece->getY()-1; b <= currPiece->getY()+1; b = b+2) {
                    for (a = currPiece->getX()-1; a <= currPiece->getX()+1; a = a+2) {
                        if (currPiece->move(a,b, boardarray)) {
                            fromStr = {currPiece->getX()};
                            fromInt = currPiece->getY();
                            toStr = {a};
                            toInt = b;

                            if (!this->MoveBecomesCheck(fromStr, fromInt, toStr, toInt))
                                return false;
                        }
                    }
                }
            }

            //Rooks move one space vertical or horizontal
            else if (currPiece->getType() == PType::rtype) {

                for (b = currPiece->getY()-1; b <= currPiece->getY(); b = b+2) {
                    if (currPiece->move(currPiece->getX(),b, boardarray)) {
                        fromStr = {currPiece->getX()};
                        fromInt = currPiece->getY();
                        toStr = {currPiece->getX()};
                        toInt = b;

                        if (!this->MoveBecomesCheck(fromStr, fromInt, toStr, toInt))
                            return false;
                    }
                }
                for (a = currPiece->getX()-1; a <= currPiece->getX(); a = a+2) {
                    if (currPiece->move(a,currPiece->getY(), boardarray)) {
                        fromStr = {currPiece->getX()};
                        fromInt = currPiece->getY();
                        toStr = {a};
                        toInt = currPiece->getY();

                        if (!this->MoveBecomesCheck(fromStr, fromInt, toStr, toInt))
                            return false;
                    }
                }
            }

            //Queens move as either rooks or bishops
            else if (currPiece->getType() == PType::qtype) {

                for (b = currPiece->getY()-1; b <= currPiece->getY()+1; b = b+1) {
                    for (a = currPiece->getX()-1; a <= currPiece->getX()+1; a = a+1) {
                        if (currPiece->move(a,b, boardarray)) {
                            fromStr = {currPiece->getX()};
                            fromInt = currPiece->getY();
                            toStr = {a};
                            toInt = b;

                            if (!this->MoveBecomesCheck(fromStr, fromInt, toStr, toInt))
                                return false;
                        }
                    }
                }
            }

            //actually, this is the same as the queen. Huh.
            else if (currPiece->getType() == PType::ktype) {

                for (b = currPiece->getY()-1; b <= currPiece->getY()+1; b = b+1) {
                    for (a = currPiece->getX()-1; a <= currPiece->getX()+1; a = a+1) {
                        if (currPiece->move(a,b, boardarray)) {
                            fromStr = {currPiece->getX()};
                            fromInt = currPiece->getY();
                            toStr = {a};
                            toInt = b;

                            if (!this->MoveBecomesCheck(fromStr, fromInt, toStr, toInt))
                                return false;
                        }
                    }
                }
            }
        }

    }
    }

    return true;
}

//Is true if the move will make check become true, false if it does not become check
bool BoardArray::MoveBecomesCheck(string fromStr, int fromInt, string toStr, int toInt) {
    bool becomesCheck = false;
    
    this->move(fromStr, fromInt, toStr, toInt);
    becomesCheck = this->check();

    this->move(toStr, toInt, fromStr, fromInt);

    return becomesCheck;
}