# CS201 Portfolio Project
In my portfolio project I choose to make a connect 4 game that can be played with two people, or one player can play against the AI that was coded. This will be submitted by March 31, 2019 at the University of Alabama. This is for our CS201, our Data Structures and Algorithms class.

### Sources
-Solving Connect 4: Part 3- MinMax algorithm <br />
&nbsp;&nbsp; -http://blog.gamesolver.org/solving-connect-four/03-minmax/ <br />
-MiniMax Algorithm <br />
&nbsp;&nbsp; -https://theoryofprogramming.com/2017/12/12/minimax-algorithm/ <br />
  
## Video Tutorial
-https://youtu.be/C2Gr4KQMqEA

## Notes About the Game
* Connect 4 is a game played between two people with pieces 'X' for player 1 and 'O' for player 2 <br />
* The goal of the game is two place four of the players pieces in a row wether it be vertical, horizontal, or diagonal <br />
* This game was coded on Atom and tested on Ubuntu <br />
* The game was coded for a class project for the University of Alabama <br />
* To play this game type the command "make", and the exicutable isi "./main"

## Feature
* This game uses ASCII character based interface
* Game modes are single player, and double player
* The board is represented by a 2D array of characters that are ' ' for an empty cell, 'X' for player one, and 'O' for player two
* The resorces stated above were used to implement a negamax variant of the MinMax for the AI. It scores the moves based on how many consecutive pieces there are. The more pieces, the higher the score. The negamax variant does the same score for both pieces, but the score is negative if it is the opponents piece. 
* For the scores the code as two arrays the size of the number of columns. It takes the 'O' score, the computer's score, and puts it in the array. Next, it scores the opponents move 'X' for each column. Then it takes the lowest score from the opponent's array and adds it to it's score. Once it runs trough all the columns, it takes the maximum of it's array and places the piece there. If there are multiple scores that are the same, the computer places the piece where the play is best for the opponent blocking them. 
