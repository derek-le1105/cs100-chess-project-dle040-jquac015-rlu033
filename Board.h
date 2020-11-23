#ifndef SFML_PROJECT_BOARD_H
#define SFML_PROJECT_BOARD_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "AssetManager.h"

const float BLOCK_SIZE = 84.2;

class Board {
private:
    AssetManager boardAssets;
    sf::RenderWindow window;
    sf::Vector2i mousePosition;
    //Piece* array[][];

protected:
    sf::Sprite _chessBoard; //each block is 84.2 by 84.2
    sf::Sprite _pawnWhitePiece1;
    sf::Sprite _pawnWhitePiece2;
    sf::Sprite _pawnWhitePiece3;
    sf::Sprite _pawnWhitePiece4;
    sf::Sprite _pawnWhitePiece5;
    sf::Sprite _pawnWhitePiece6;
    sf::Sprite _pawnWhitePiece7;
    sf::Sprite _pawnWhitePiece8;
    sf::Sprite _rookWhitePiece1;
    sf::Sprite _rookWhitePiece2;
    sf::Sprite _knightWhitePiece1;
    sf::Sprite _knightWhitePiece2;
    sf::Sprite _bishopWhitePiece1;
    sf::Sprite _bishopWhitePiece2;
    sf::Sprite _queenWhitePiece;
    sf::Sprite _kingWhitePiece;

    sf::Sprite _pawnBlackPiece1;
    sf::Sprite _pawnBlackPiece2;
    sf::Sprite _pawnBlackPiece3;
    sf::Sprite _pawnBlackPiece4;
    sf::Sprite _pawnBlackPiece5;
    sf::Sprite _pawnBlackPiece6;
    sf::Sprite _pawnBlackPiece7;
    sf::Sprite _pawnBlackPiece8;
    sf::Sprite _rookBlackPiece1;
    sf::Sprite _rookBlackPiece2;
    sf::Sprite _knightBlackPiece1;
    sf::Sprite _knightBlackPiece2;
    sf::Sprite _bishopBlackPiece1;
    sf::Sprite _bishopBlackPiece2;
    sf::Sprite _queenBlackPiece;
    sf::Sprite _kingBlackPiece;

public:
    Board();
    Board(int width, int height, std::string title);

    void init();
    void draw();
    void handleInput();
    void run();
};


#endif //SFML_PROJECT_BOARD_H
