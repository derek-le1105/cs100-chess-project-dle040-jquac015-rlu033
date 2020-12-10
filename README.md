 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\<"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Chess

 > Authors: [Justin Quach](https://github.com/jquac015), [Ryan Lu](https://github.com/Lyran312), [Derek Le](https://github.com/derek-le1105)
 
 > You will be forming a group of **THREE** students and work on an interesting project that you will propose yourself (in this `README.md` document). You can pick any project that you'd like, but it needs ot implement three design patterns. Each of the members in a group is expected to work on at least one design pattern and its test cases. You can, of course, help each other, but it needs to be clear who will be responsible for which pattern and for which general project features.
 
 > ## Expectations
 > * Incorporate **three** distinct design patterns, *two* of the design patterns need to be taught in this course:
 >   * Composite, Strategy, Abstract Factory, Visitor
 > * All three design patterns need to be linked together (it can't be three distinct projects)
 > * Your project should be implemented in C/C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.

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
 >   * [C++ graphics library](https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1126/materials/cppdoc/graphics.html)
 > * Input/Output:
 >   * The input will be the moves the player wants to make.
 >   * The output will be a chess board and chess pieces that reflect the position the player inputs. At the end of the game, an "End Game" message will be displayed (P1 wins, P2 wins, Draw).
 > * The three design patterns we plan to use are abstract factory, strategy, and visitor:
 >   * We want to use the strategy design pattern in order to check for all moves of a chess piece. This allows us to check whether or not there is a checkmate/check/stalemate. It is important to use the strategy design pattern because every pieces has a different type of movement and we would not be able to fully accommodate the piece without using the strategy design pattern. We also might create a scoring system with the piece values that can use the strategy pattern. 
 >   * An important pattern is abstract factory. The board is a double array of Piece*, which can be tedious to set up/reset over and over. To solve this, we can make use of a factory to populate the array. This way we can also change the starting positions of the pieces, as there are different styles than the traditional set-up.
 >   * Because we are using the strategy design pattern, it would also be important to use a visitor to view items in the object using the strategy design pattern. By using a visitor, we can check the alignment of a piece, which is used in deciding if that piece can move on a specific player's turn, or when chcking if a piece can capture another piece. This can also be applied during the Board's move function, which can be able to look at location of a piece and the possible movements it can make, specifically the squares it threatens. 

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
![final project diagram](https://user-images.githubusercontent.com/72291856/101779897-add1ef00-3aaa-11eb-9b64-5758fe8917a6.png)
![final project diagram1](https://user-images.githubusercontent.com/72291856/101779903-b0ccdf80-3aaa-11eb-8f75-84dbcae3512a.png)
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
![image](https://user-images.githubusercontent.com/72291856/101778906-6008b700-3aa9-11eb-8c3c-4ea7ec191333.png)
![image](https://user-images.githubusercontent.com/72291856/101778990-82023980-3aa9-11eb-9cfc-05eb1db4759b.png)
![image](https://user-images.githubusercontent.com/72291856/101779071-a1996200-3aa9-11eb-9a16-fc9c0fa2880d.png)
![image](https://user-images.githubusercontent.com/72291856/101779186-c42b7b00-3aa9-11eb-9759-06ed5f17c0e0.png)
