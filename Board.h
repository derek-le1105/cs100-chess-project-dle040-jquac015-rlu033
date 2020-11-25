#ifndef SFML_PROJECT_BOARD_H
#define SFML_PROJECT_BOARD_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "AssetManager.h"
#include <iostream>
#include <cctype>
#include <cmath>

const float BLOCK_SIZE = 84.2;

enum ChessType {NORMAL, FISCHER};
enum pieceClicked {pieceCurrentlyClicked, moveCurrentlyClicked};

class BoardFactory {
public:
    BoardFactory(){}
    //changes array in argument, does not create a new one
    void CreateBoard(Piece* array[][8], ChessType type = NORMAL) {
        int i, j;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                /*if (array[i][j] != nullptr)
                    delete array[i][j];*/
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
        //FISCHER-RANDOM implement here
    }
};

class Board {
private:
    AssetManager boardAssets;
    sf::RenderWindow window;
    sf::Vector2i mousePosition;
    Piece* pieceArray[8][8];
    pieceClicked checkClick = pieceCurrentlyClicked;
    char prevX;
    int prevY;

protected:
    int board[8][8] =
            {  2, 3, 4, 5, 6, 4, 3, 2,
               1, 1, 1, 1, 1, 1, 1, 1,
               0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0,
              -1,-1,-1,-1,-1,-1,-1,-1,
              -2,-3,-4,-5,-6,-4,-3,-2 };
    sf::Sprite _chessBoard; //each block is 84.2 by 84.2


public:
    Board();
    Board(int width, int height, std::string title);

    void init();
    void draw();
    void handleInput();
    void run();
    void storePreviousCord();
    int CharToInt(char c) {
        if (isupper(c))
            return c - 'A' + 1;
        if (islower(c))
            return c - 'a' + 1;
        else
            return 0;
    }
};


#endif //SFML_PROJECT_BOARD_H
