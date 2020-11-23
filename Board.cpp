#include "Board.h"
Board::Board(){
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

    _pawnWhitePiece1.setTexture(this->boardAssets.getTexture("Pawn White Piece"));
    _pawnWhitePiece1.move(0, BLOCK_SIZE);
    _pawnWhitePiece2.setTexture(this->boardAssets.getTexture("Pawn White Piece"));
    _pawnWhitePiece2.move(BLOCK_SIZE, BLOCK_SIZE);
    _pawnWhitePiece3.setTexture(this->boardAssets.getTexture("Pawn White Piece"));
    _pawnWhitePiece3.move(BLOCK_SIZE * 2, BLOCK_SIZE);
    _pawnWhitePiece4.setTexture(this->boardAssets.getTexture("Pawn White Piece"));
    _pawnWhitePiece4.move(BLOCK_SIZE * 3, BLOCK_SIZE);
    _pawnWhitePiece5.setTexture(this->boardAssets.getTexture("Pawn White Piece"));
    _pawnWhitePiece5.move(BLOCK_SIZE * 4, BLOCK_SIZE);
    _pawnWhitePiece6.setTexture(this->boardAssets.getTexture("Pawn White Piece"));
    _pawnWhitePiece6.move(BLOCK_SIZE * 5, BLOCK_SIZE);
    _pawnWhitePiece7.setTexture(this->boardAssets.getTexture("Pawn White Piece"));
    _pawnWhitePiece7.move(BLOCK_SIZE * 6, BLOCK_SIZE);
    _pawnWhitePiece8.setTexture(this->boardAssets.getTexture("Pawn White Piece"));
    _pawnWhitePiece8.move(BLOCK_SIZE * 7, BLOCK_SIZE);

    _pawnBlackPiece1.setTexture(this->boardAssets.getTexture("Pawn Black Piece"));
    _pawnBlackPiece1.move(0, BLOCK_SIZE * 6);
    _pawnBlackPiece2.setTexture(this->boardAssets.getTexture("Pawn Black Piece"));
    _pawnBlackPiece2.move(BLOCK_SIZE, BLOCK_SIZE * 6);
    _pawnBlackPiece3.setTexture(this->boardAssets.getTexture("Pawn Black Piece"));
    _pawnBlackPiece3.move(BLOCK_SIZE * 2, BLOCK_SIZE * 6);
    _pawnBlackPiece4.setTexture(this->boardAssets.getTexture("Pawn Black Piece"));
    _pawnBlackPiece4.move(BLOCK_SIZE * 3, BLOCK_SIZE * 6);
    _pawnBlackPiece5.setTexture(this->boardAssets.getTexture("Pawn Black Piece"));
    _pawnBlackPiece5.move(BLOCK_SIZE * 4, BLOCK_SIZE * 6);
    _pawnBlackPiece6.setTexture(this->boardAssets.getTexture("Pawn Black Piece"));
    _pawnBlackPiece6.move(BLOCK_SIZE * 5, BLOCK_SIZE * 6);
    _pawnBlackPiece7.setTexture(this->boardAssets.getTexture("Pawn Black Piece"));
    _pawnBlackPiece7.move(BLOCK_SIZE * 6, BLOCK_SIZE * 6);
    _pawnBlackPiece8.setTexture(this->boardAssets.getTexture("Pawn Black Piece"));
    _pawnBlackPiece8.move(BLOCK_SIZE * 7, BLOCK_SIZE * 6);

    _rookWhitePiece1.setTexture(this->boardAssets.getTexture("Rook White Piece"));
    _rookWhitePiece2.setTexture(this->boardAssets.getTexture("Rook White Piece"));
    _rookWhitePiece2.move(BLOCK_SIZE * 7, 0);

    _rookBlackPiece1.setTexture(this->boardAssets.getTexture("Rook Black Piece"));
    _rookBlackPiece1.move(0, BLOCK_SIZE * 7);
    _rookBlackPiece2.setTexture(this->boardAssets.getTexture("Rook Black Piece"));
    _rookBlackPiece2.move(BLOCK_SIZE * 7, BLOCK_SIZE * 7);

    _bishopWhitePiece1.setTexture(this->boardAssets.getTexture("Bishop White Piece"));
    _bishopWhitePiece1.move(BLOCK_SIZE * 2, 0);
    _bishopWhitePiece2.setTexture(this->boardAssets.getTexture("Bishop White Piece"));
    _bishopWhitePiece2.move(BLOCK_SIZE * 5, 0);

    _bishopBlackPiece1.setTexture(this->boardAssets.getTexture("Bishop Black Piece"));
    _bishopBlackPiece1.move(BLOCK_SIZE * 5, BLOCK_SIZE * 7);
    _bishopBlackPiece2.setTexture(this->boardAssets.getTexture("Bishop Black Piece"));
    _bishopBlackPiece2.move(BLOCK_SIZE * 2, BLOCK_SIZE * 7);

    _knightWhitePiece1.setTexture(this->boardAssets.getTexture("Knight White Piece"));
    _knightWhitePiece1.move(BLOCK_SIZE, 0);
    _knightWhitePiece2.setTexture(this->boardAssets.getTexture("Knight White Piece"));
    _knightWhitePiece2.move(BLOCK_SIZE * 6, 0);

    _knightBlackPiece1.setTexture(this->boardAssets.getTexture("Knight Black Piece"));
    _knightBlackPiece1.move(BLOCK_SIZE, BLOCK_SIZE * 7);
    _knightBlackPiece2.setTexture(this->boardAssets.getTexture("Knight Black Piece"));
    _knightBlackPiece2.move(BLOCK_SIZE * 6, BLOCK_SIZE * 7);

    _queenWhitePiece.setTexture(this->boardAssets.getTexture("Queen White Piece"));
    _queenWhitePiece.move(BLOCK_SIZE * 3, 0);

    _queenBlackPiece.setTexture(this->boardAssets.getTexture("Queen Black Piece"));
    _queenBlackPiece.move(BLOCK_SIZE * 3, BLOCK_SIZE * 7);

    _kingWhitePiece.setTexture(this->boardAssets.getTexture("King White Piece"));
    _kingWhitePiece.move(BLOCK_SIZE * 4, 0);

    _kingBlackPiece.setTexture(this->boardAssets.getTexture("King Black Piece"));
    _kingBlackPiece.move(BLOCK_SIZE * 4, BLOCK_SIZE * 7);
}

void Board::draw() {
    window.draw(this->_chessBoard);
    window.draw(this->_pawnWhitePiece1);
    window.draw(this->_pawnWhitePiece2);
    window.draw(this->_pawnWhitePiece3);
    window.draw(this->_pawnWhitePiece4);
    window.draw(this->_pawnWhitePiece5);
    window.draw(this->_pawnWhitePiece6);
    window.draw(this->_pawnWhitePiece7);
    window.draw(this->_pawnWhitePiece8);
    window.draw(this->_rookWhitePiece1);
    window.draw(this->_rookWhitePiece2);
    window.draw(this->_bishopWhitePiece1);
    window.draw(this->_bishopWhitePiece2);
    window.draw(this->_knightWhitePiece1);
    window.draw(this->_knightWhitePiece2);
    window.draw(this->_queenWhitePiece);
    window.draw(this->_kingWhitePiece);

    window.draw(this->_pawnBlackPiece1);
    window.draw(this->_pawnBlackPiece2);
    window.draw(this->_pawnBlackPiece3);
    window.draw(this->_pawnBlackPiece4);
    window.draw(this->_pawnBlackPiece5);
    window.draw(this->_pawnBlackPiece6);
    window.draw(this->_pawnBlackPiece7);
    window.draw(this->_pawnBlackPiece8);

    window.draw(this->_rookBlackPiece1);
    window.draw(this->_rookBlackPiece2);

    window.draw(this->_bishopBlackPiece1);
    window.draw(this->_bishopBlackPiece2);

    window.draw(this->_knightBlackPiece1);
    window.draw(this->_knightBlackPiece2);

    window.draw(this->_queenBlackPiece);
    window.draw(this->_kingBlackPiece);
}

void Board::handleInput() {
    sf::Event event;
    while(this->window.pollEvent(event)){
        if(event.type== sf::Event::Closed )
            this->window.close();
        if(event.type == sf::Event::MouseButtonPressed) {
            mousePosition = sf::Mouse::getPosition();
            //_pawnWhitePiece1.move(_pawnWhitePiece1.getPosition().x, _pawnWhitePiece1.getPosition().y);
        }
    }
}

void Board::run(){
    while(this->window.isOpen()){
        handleInput();
        draw();
        window.display();
    }
}

