# Chess

 > Authors: [Justin Quach](https://github.com/jquac015), [Ryan Lu](https://github.com/Lyran312), [Derek Le](https://github.com/derek-le1105)
 
## Project Description
 > For our project, we plan to make a virtual 2-player chess game.
 > * Taken from [Wikipedia](https://en.wikipedia.org/wiki/Chess)
 >   * Chess is a two-player strategy board game played on a checkered board with 64 squares arranged in an 8×8 square grid.
 >   * Each player begins with 16 pieces: one king, one queen, two rooks, two knights, two bishops, and eight pawns. Each piece type moves differently, with the most powerful being the queen and the least powerful the pawn.
 >   * During the game, play typically involves exchanging pieces for the opponent's similar pieces, and finding and engineering opportunities to trade advantageously or to get a better position.
 >   * The objective is to checkmate the opponent's king by placing it under an inescapable threat of capture. To this end, a player's pieces are used to attack and capture the opponent's pieces, while supporting one another. There are also several ways a game can end in a draw.
 
 > * This is interesting to us because we are all avid chess players and it is interesting to see chess being built as a program from the ground up.
 > * Languages/Tools/Technologies:
 >   * [C++](https://www.cplusplus.com/)
 >   * [C++ graphics library](https://www.sfml-dev.org/download/sfml/2.5.1/)
 > * Input/Output:
 >   * The input will be the moves the player wants to make.
 >   * The output will be a chess board and chess pieces that reflect the position the player inputs. At the end of the game, an "End Game" message will be displayed (P1 wins, P2 wins, Draw).
 > * The three design patterns we plan to use are factory, strategy, and visitor:
 >   * We want to use the strategy design pattern in order to check for all moves of a chess piece. This allows us to check whether or not there is a checkmate/check/stalemate. It is important to use the strategy design pattern because every pieces has a different type of movement and we would not be able to fully accommodate the piece without using the strategy design pattern. We also might create a scoring system with the piece values that can use the strategy pattern. 
 >   * An important pattern is the factory pattern. The board is a double array of Piece*, which can be tedious to set up/reset over and over. To solve this, we can make use of a factory to populate the array. This way we can also change the starting positions of the pieces, as there are different styles than the traditional set-up.
 >   * Because we are using the strategy design pattern, it would also be important to use a visitor to view items in the object using the strategy design pattern. By using a visitor, we can check the alignment of a piece, which is used in deciding if that piece can move on a specific player's turn, or when chcking if a piece can capture another piece. This can also be applied during the Board's move function, which can be able to look at location of a piece and the possible movements it can make, specifically the squares it threatens. 

## Class Diagram
![final project diagram](https://user-images.githubusercontent.com/72291856/101779897-add1ef00-3aaa-11eb-9b64-5758fe8917a6.png)
![final project diagram1](https://user-images.githubusercontent.com/72291856/101779903-b0ccdf80-3aaa-11eb-8f75-84dbcae3512a.png)
 
 ## Screenshots
 ![scrnsht1](https://user-images.githubusercontent.com/64372005/101778926-67c85b80-3aa9-11eb-817d-305380df7fe3.PNG)
 ![scrnsht2](https://user-images.githubusercontent.com/64372005/101778944-7151c380-3aa9-11eb-979a-f8e703c00300.PNG)
 ![scrnsht3](https://user-images.githubusercontent.com/64372005/101778826-3ea7cb00-3aa9-11eb-9ec3-2521d922fe1a.PNG)
 
 ## Installation/Usage
 > * Download the ZIP folder for this project.
 > * Unzip the folder.
 > * Navigate to the cmake-build-debug folder.
 > * Run the sfml_project.exe file.
 
 ## Testing
![image](https://user-images.githubusercontent.com/72291856/101778906-6008b700-3aa9-11eb-8c3c-4ea7ec191333.png)
![image](https://user-images.githubusercontent.com/72291856/101778990-82023980-3aa9-11eb-9cfc-05eb1db4759b.png)
![image](https://user-images.githubusercontent.com/72291856/101779071-a1996200-3aa9-11eb-9a16-fc9c0fa2880d.png)
![image](https://user-images.githubusercontent.com/72291856/101779186-c42b7b00-3aa9-11eb-9759-06ed5f17c0e0.png)
