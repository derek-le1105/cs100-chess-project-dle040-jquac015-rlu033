#include <cstring>
#include "Board.h"
Board::Board(){
    BoardFactory fact;
    fact.CreateBoard(pieceArray, NORMAL);
    this->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Chess", sf::Style::Close | sf::Style::Titlebar);
    this->init();
    this->run();

}

Board::Board(int width, int height, std::string title) {
    this->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    this->init();
    this->run();
}

Board::~Board(){

}

void Board::PrintBoard() {
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (pieceArray[i][j] == nullptr) {cout << "0";}
            else {cout << "1";}
        } cout << endl;
    }
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
    boardAssets.loadTexture("Highlight Piece", HIGHLIGHT_PIECE_FILE_PATH);
    boardAssets.loadTexture("Potential Move Circle", POTENTIAL_MOVE_FILE_PATH);
    boardAssets.loadTexture("White Screen", WHITE_SCREEN_FILE_PATH);
    boardAssets.loadTexture("White Checkmate", WHITE_CHECKMATE_FILE_PATH);
    boardAssets.loadTexture("Black Checkmate", BLACK_CHECKMATE_FILE_PATH);


    _chessBoard.setTexture(this->boardAssets.getTexture("Chess Board"));
    _chessBoard.setScale(1.5, 1.5);

    _highlightPiece.setTexture(this->boardAssets.getTexture("Highlight Piece"));
    _highlightPiece.setScale(1.00223, 1.00669);

    _potentialMove.setTexture(this->boardAssets.getTexture("Potential Move Circle"));       //used to pushback into the potential moves vector
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
                    break;
            }
            pieceArray[j][i]->currentSprite.setPosition(BLOCK_SIZE * j, BLOCK_SIZE * i);
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

                if(checkTurn(posX, posY)) {
                    if (pieceArray[posX][posY] == nullptr)        //if mouse is clicked on a block with no piece in it
                        checkClick = pieceCurrentlyClicked;
                    else {                                          //if mouse is clicked on a block with a piece in it
                        checkClick = moveCurrentlyClicked;
                        storePreviousCord();
                        _highlightPiece.setPosition(posX * 84.2, posY * 84.6);

                        for (char tempIter = 'a'; tempIter <= 'h'; ++tempIter)  //use for loops to display all positions that are valid for movement for current piece
                            for (int j = 1; j <= 8; ++j)
                                if (pieceArray[posX][posY]->move(tempIter, j, pieceArray))
                                    getPotentialMoves(CharToInt(tempIter) - 1, j - 1);
                    }
                    drawSpriteCheck = valid;
                }
            }
            else if (checkClick == moveCurrentlyClicked){       //reverts back to previous enum to allow clicking a new piece
                if(checkTurn(prevX, prevY)) {
                    potentialMoves.clear();
                    int charToIntX = CharToInt(prevXChar) - 1,
                            posX = mousePosition.x / 84, posY = (mousePosition.y + 84 - 1) / 84, boardPosyY = posY - 1;
                    char iter = 'a';

                    for (int i = 0; i < posX; ++i)
                        iter++;

                    if (pieceArray[charToIntX][prevY]->move(iter, posY, pieceArray)) {   //checks to see if desired block is a valid move
                        movePiece(charToIntX, posX, posY, boardPosyY, iter);

                        if(check())
                            gameoverCheck = true;

                        drawSpriteCheck = invalid;

                        turn = (turn == WHITE) ? BLACK : WHITE;             //if game = whiteturn, set to black and vice versa
                    }
                    checkClick = pieceCurrentlyClicked;
                }
            }
        }
    }
}

void Board::movePiece(int charToIntX, int posX, int posY, int boardPosY, char iter){
    pieceArray[charToIntX][prevY]->currentSprite.setPosition(posX * BLOCK_SIZE, boardPosY * BLOCK_SIZE);    //moves sprite to cursor clicked

    pieceArray[posX][boardPosY] = pieceArray[charToIntX][prevY];        //sets new position = previous position
    pieceArray[charToIntX][prevY]->setCoord(iter, posY);                 //sets coordinates within piece
    pieceArray[charToIntX][prevY] = nullptr;                             //makes previous position nullptr

    board[boardPosY][posX] = board[prevY][charToIntX];                  //sets boardPiece at [boardPosY][posX] to boardPiece at [prevY][charToIntX]
    board[prevY][charToIntX] = 0;                                        //'cleans up' previous piece
}

void Board::displayGameOver(Color turn) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (pieceArray[i][j] == nullptr)
                continue;
            else
                pieceArray[i][j] = nullptr;
        }
    }

    if (turn == WHITE) {
        _checkmateMessage.setTexture(this->boardAssets.getTexture("Black Checkmate"));
        _chessBoard.setColor(sf::Color::Black);

    }
    else {
        _chessBoard.setTexture(this->boardAssets.getTexture("White Screen"));
        _checkmateMessage.setTexture(this->boardAssets.getTexture("White Checkmate"));
        _chessBoard.setScale(3, 3);
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
    prevXChar = iter;
    prevX = posX;
    prevY = posY;
}

bool Board::checkTurn(int x, int y) {   //checks who's turn it is in the game
    if(pieceArray[x][y] == nullptr)     //if user clicks on an empty block, do nothing
        return true;
    else
        return ((turn == WHITE && pieceArray[x][y]->getAlignment() == WHITE) || (turn == BLACK && pieceArray[x][y]->getAlignment() == BLACK));
}

void Board::draw() {
    window.draw(this->_chessBoard);
    if(drawSpriteCheck == valid)
        window.draw(this->_highlightPiece);

    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if(pieceArray[j][i] != nullptr)
                window.draw(pieceArray[j][i]->currentSprite);
        }
    }

    for(int i = 0; i < potentialMoves.size(); ++i)
        window.draw(potentialMoves[i]);

    if(gameoverCheck) {
        displayGameOver(turn);
        window.draw(_checkmateMessage);
    }
}

bool Board::check(){
    Piece* checked;
    Piece* checKing;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(pieceArray[i][j] != nullptr) {
                checked = pieceArray[i][j];
                if (checked->getType() == ktype && checked->getAlignment() != turn) {
                    checKing = pieceArray[i][j];
                }
            }
        }
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(pieceArray[i][j] != nullptr) {
                checked = pieceArray[i][j];
                if (checked->move(checKing->getX(), checKing->getY(), pieceArray) && checKing->getAlignment() != checked->getAlignment()) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Board::checkmate() {

    if (!check()) { return false; }
    Piece *checked;
    Piece *checKing;
    int i, j, xsave, ysave;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (pieceArray[i][j] != nullptr) {
                checked = pieceArray[i][j];
                if (checked->getType() == ktype && checked->getAlignment() == turn) {
                    checKing = pieceArray[i][j];
                }
            }
        }
    }
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (pieceArray[i][j] != nullptr) {
                checked = pieceArray[i][j];
                if (checked->move(checKing->getX(), checKing->getY(), pieceArray) &&
                    checKing->getAlignment() != checked->getAlignment()) {
                    xsave = ChartoInt(checked->getX());
                    ysave = checked->getY();
                }
            }
        }
    }
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (pieceArray[i][j] != nullptr) {
                checked = pieceArray[i][j];
                if (checked->move(xsave + 'a', ysave, pieceArray) &&
                    pieceArray[xsave][ysave]->getAlignment() != checked->getAlignment()) {
                    return false;
                }
            }
        }
    }
    xsave = ChartoInt(checKing->getX());
    ysave = checKing->getY();
    for (i = ChartoInt(checKing->getX() - 1); i < ChartoInt(checKing->getX()) + 2; i++) {
        for (j = checKing->getY() - 1; j < checKing->getY() + 2; j++) {
            if (pieceArray[i][j] != nullptr) {
                if (checKing->move(i + 'a', j, pieceArray)) {
                    pieceArray[i][j] = checKing;
                    checKing = nullptr;
                    if (!check()) { return false; }
                }

            }
        }
        pieceArray[xsave][ysave] = pieceArray[i][j];
        return true;
    }
}

//needs to also not put the king in check (relies on check())
bool Board::stalemate() {
    if (check()) { return false; }

    int i, j; //iterate through the board
    char a; int b; //iterate through possible moves
    Piece* currPiece;
    bool passCheck;
    string fromStr, toStr;
    int fromInt, toInt;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {

            currPiece = pieceArray[i][j];

            if (currPiece != nullptr) {
                //Pawns have 4 possible moves, but in either direction based on alignment
                if (currPiece->getType() == PType::ptype) {

                    for (b = currPiece->getY()-1; b <= currPiece->getY()+1; b = b+2) {
                        for (a = currPiece->getX()-1; a <= currPiece->getY()+1; a++) {
                            if (currPiece->move(a,b, pieceArray)) {
                                fromStr = {currPiece->getX()};
                                fromInt = currPiece->getY();
                                toStr = {a};
                                toInt = b;

                                if (!this->MoveBecomesCheck(fromStr, fromInt, toStr, toInt))
                                    return false;
                            }
                        }
                    }

                    if (currPiece->move(a,b-2, pieceArray) || currPiece->move(a,b+2, pieceArray)) {
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
                            if (currPiece->move(a,b, pieceArray)) {
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
                            if (currPiece->move(a,b, pieceArray)) {
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
                            if (currPiece->move(a,b, pieceArray)) {
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
                        if (currPiece->move(currPiece->getX(),b, pieceArray)) {
                            fromStr = {currPiece->getX()};
                            fromInt = currPiece->getY();
                            toStr = {currPiece->getX()};
                            toInt = b;

                            if (!this->MoveBecomesCheck(fromStr, fromInt, toStr, toInt))
                                return false;
                        }
                    }
                    for (a = currPiece->getX()-1; a <= currPiece->getX(); a = a+2) {
                        if (currPiece->move(a,currPiece->getY(), pieceArray)) {
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
                            if (currPiece->move(a,b, pieceArray)) {
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
                            if (currPiece->move(a,b, pieceArray)) {
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

bool Board::MoveBecomesCheck(string fromStr, int fromInt, string toStr, int toInt) {
    bool becomesCheck = false;
    int posX = mousePosition.x / 84, posY = (mousePosition.y + 84 - 1) / 84, boardPosyY = posY - 1;
    prevY = fromInt;
    //this->move(fromStr, fromInt, toStr, toInt);
    this->movePiece(stoi(fromStr), stoi(toStr), toInt, toInt - 1, StringtoChar(fromStr));
    becomesCheck = this->check();

    this->movePiece(stoi(toStr), stoi(fromStr), fromInt, fromInt - 1, StringtoChar(toStr));
    //this->move(toStr, toInt, fromStr, fromInt);

    return becomesCheck;
}

int Board::ChartoInt(char toInt){
    int ret = toInt;
    if(ret>=65 && ret<=90){
        return ret-65;
    }else if(ret>=97 && ret<=122){
        return ret-97;
    }
}

void Board::getPotentialMoves(int i, int j) {       //stores potential moves into a vector and sets position of each potential move (uses <vector>.clear() to empty vector if another piece is clicked)
    potentialMoves.push_back(_potentialMove);
    potentialMoves.back().setTexture(this->boardAssets.getTexture("Potential Move Circle"));
    potentialMoves.back().setPosition(BLOCK_SIZE * i, BLOCK_SIZE * j);
}

char Board::StringtoChar(string toChar){
    int len = toChar.length();
    char ret[len+1];
    strcpy(ret, toChar.c_str());
    return ret[0];
}
