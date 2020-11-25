#include "Board.h"
Board::Board(){
    BoardFactory fact;
    fact.CreateBoard(pieceArray, NORMAL);
    this->window.create(sf::VideoMode(673.5, 676.5), "Chess", sf::Style::Close | sf::Style::Titlebar);
    this->init();
    this->run();
}

Board::Board(int width, int height, std::string title) {
    this->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    this->init();
    this->run();
}

void Board::init(){
    boardAssets.loadTexture("Chess Board", CHESS_BOARD_FILE_PATH);
    boardAssets.loadTexture("Pawn White Piece", PAWN_W_PIECE_FILE_PATH);
    boardAssets.loadTexture("Pawn Black Piece", PAWN_B_PIECE_FILE_PATH);
    boardAssets.loadTexture("Rook White Piece", ROOK_W_PIECE_FILE_PATH);
    boardAssets.loadTexture("Rook Black Piece", ROOK_B_PIECE_FILE_PATH);
    boardAssets.loadTexture("Bishop White Piece", BISHOP_W_PIECE_FILE_PATH);
    boardAssets.loadTexture("Bishop Black Piece", BISHOP_B_PIECE_FILE_PATH);
    boardAssets.loadTexture("Knight White Piece", KNIGHT_W_PIECE_FILE_PATH);
    boardAssets.loadTexture("Knight Black Piece", KNIGHT_B_PIECE_FILE_PATH);
    boardAssets.loadTexture("Queen White Piece", QUEEN_W_PIECE_FILE_PATH);
    boardAssets.loadTexture("Queen Black Piece", QUEEN_B_PIECE_FILE_PATH);
    boardAssets.loadTexture("King White Piece", KING_W_PIECE_FILE_PATH);
    boardAssets.loadTexture("King Black Piece", KING_B_PIECE_FILE_PATH);

    _chessBoard.setTexture(this->boardAssets.getTexture("Chess Board"));
    _chessBoard.setScale(1.5, 1.5);

    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if(!board[i][j])
                continue;

            switch(board[i][j]){
                case -6:
                    pieceArray[j][i]->currentSprite.setTexture(this->boardAssets.getTexture("King White Piece"));
                    break;
                case -5:
                    pieceArray[j][i]->currentSprite.setTexture(this->boardAssets.getTexture("Queen White Piece"));
                    break;
                case -4:
                    pieceArray[j][i]->currentSprite.setTexture(this->boardAssets.getTexture("Bishop White Piece"));
                    break;
                case -3:
                    pieceArray[j][i]->currentSprite.setTexture(this->boardAssets.getTexture("Knight White Piece"));
                    break;
                case -2:
                    pieceArray[j][i]->currentSprite.setTexture(this->boardAssets.getTexture("Rook White Piece"));
                    break;
                case -1:
                    pieceArray[j][i]->currentSprite.setTexture(this->boardAssets.getTexture("Pawn White Piece"));
                    break;
                case 1:
                    pieceArray[j][i]->currentSprite.setTexture(this->boardAssets.getTexture("Pawn Black Piece"));
                    break;
                case 2:
                    pieceArray[j][i]->currentSprite.setTexture(this->boardAssets.getTexture("Rook Black Piece"));
                    break;
                case 3:
                    pieceArray[j][i]->currentSprite.setTexture(this->boardAssets.getTexture("Knight Black Piece"));
                    break;
                case 4:
                    pieceArray[j][i]->currentSprite.setTexture(this->boardAssets.getTexture("Bishop Black Piece"));
                    break;
                case 5:
                    pieceArray[j][i]->currentSprite.setTexture(this->boardAssets.getTexture("Queen Black Piece"));
                    break;
                case 6:
                    pieceArray[j][i]->currentSprite.setTexture(this->boardAssets.getTexture("King Black Piece"));
                    //pieceArray[j][i] = new King(BLACK, 'D', 4);
                    break;
            }
            pieceArray[j][i]->currentSprite.setPosition(BLOCK_SIZE * j, BLOCK_SIZE * i);
        }
    }
}

void Board::draw() {
    window.draw(this->_chessBoard);
/*    for(int i = 0; i < 32; ++i)
        window.draw(pieces[i]);*/
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if(pieceArray[j][i] != nullptr)
                window.draw(pieceArray[j][i]->currentSprite);
        }
    }
}

void Board::handleInput() {
    sf::Event event;

    while (this->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            this->window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
            if(checkClick == pieceCurrentlyClicked){
                int posX = mousePosition.x / 84, posY = mousePosition.y / 84;

                if(pieceArray[posX][posY] == nullptr)        //if mouse is clicked on a block with no piece in it
                    checkClick = pieceCurrentlyClicked;
                else {                                          //if mouse is clicked on a block with a piece in it
                    checkClick = moveCurrentlyClicked;
                    storePreviousCord();
                }
            }
            else if (checkClick == moveCurrentlyClicked){       //reverts back to previous enum to allow clicking a new piece
                int tempX = CharToInt(prevX) - 1;
                int posX = mousePosition.x / 84, posY = (mousePosition.y + 84 - 1) / 84, boardPosyY = posY - 1;
                char iter = 'a';
                for(int i = 0; i < posX; ++i)
                    iter++;
                if(pieceArray[tempX][prevY]->move(iter, posY, pieceArray)){
                    pieceArray[tempX][prevY]->currentSprite.setPosition(posX * BLOCK_SIZE, boardPosyY * BLOCK_SIZE);
                    pieceArray[posX][boardPosyY] = pieceArray[tempX][prevY];        //sets new position = previous position
                    pieceArray[tempX][prevY] = nullptr;                             //makes previous position nullptr
                    board[posX][boardPosyY] = board[tempX][prevY];
                    board[tempX][prevY] = 0;
                }
                checkClick = pieceCurrentlyClicked;
            }
        }
    }
}

void Board::run(){
    while(this->window.isOpen()){
        mousePosition = sf::Mouse::getPosition(window);
        handleInput();
        draw();
        window.display();
    }
}

void Board::storePreviousCord() {
    int posX = mousePosition.x / 84, posY = mousePosition.y / 84;
    char iter = 'a';
    for(int i = 0; i < posX; ++i)
        iter++;
    prevX = iter;
    prevY = posY;
}

