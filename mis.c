#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// This function makes sure the input is a number
bool number(char test[]) {
  int x = strlen(test);
  bool state;
  for (int i = 0; i < x; i++) {
    if (!isdigit(test[i])) {
      state = false;
      break;
    }
    state = true;
  }
  return state;
}

// This function sets the score back to 0
void destroyArray(int *store, int column) {
  for (int i = 0; i < column; i++)
    store[i] = 0;
}

// This function returns the placement for the opponents
int placeMent(int *store, int column) {
  int x = (column / 2);
  int min = store[x];
  for (int i = 0; i < column; i++) {
    if (store[i] < min) {
      min = store[i];
      x = i;
    }
  }
  return x;
}

// This one returns the maximum score and accounts for doubles
int maxArray(int* store, int *backUp, int column, int *trouble) {
  int x = (column / 2);
  int max = store[x];
  int count = 0;
  for (int i = 0; i < column; i++) {
    if (store[i] > max ) {
      max = store[i];
      x = i;
      *trouble = 0;
      count = 0;
    }
    if (store[i] == max) {
      count++;
      if (count >= 2) {
        *trouble = 1;
      }
    }

  }
  return x;
}

// This function returns the minimum value int the array
int minArray(int* store, int column) {
  int min = 0;
  for (int i = 0; i < column; i++) {
    if (store[i] < min ) min = store[i];
  }
  return min;
}

// Ths function returns a 1 if the column is filled
int fillCol(char** board, int column) {
  if (board[0][column] != ' ') return 1;

  else return 0;
}

// This function prints the 2D matrix with the stones in them
void printBoard(char **array, int row, int column) {
    for (int a = 0; a < row; a++) {
        for (int b = 0; b < column; b++) {
            printf("| %c ", array[a][b]);
        }
        printf("|\n-");
        for (int b = 0; b < column; b++) {
          printf("----");
        }
        printf("\n");
    }
    for (int a = 1; a <= column; a++) {
      if (a < 10)
        printf("  %d ", a);
      else
        printf(" %d ", a);
    }
    printf("\n");
    return;
  }

// This function places the stone that the user/player picks
void placeMark(int move, char turn, char **board, int row, int column) {
  int check = 0;
  if (board[check+1][move] != ' ') {
    check = 0;
  }
  else {
    while ( (check < row) && (board[check][move] == ' ')  ) {
      check++;
    }
    check--;
  }
  board[check][move] = turn;
  return;
}

// This function returns how many stones are in a vertical alignment
int Vertical(char **board, int move, char turn, int row, int column) {
    int check = (row-1);
    int four = 0;
    if (board[0][move] != ' ') {
        check = 0;
    }
    else {
        while(board[check][move] != ' ') {
            check--;
        }
    }
    if (check != 0)
        check ++;
    while ( (check <= (row - 1)) && (move <=(column - 1)) && (move >= 0) && (board[check][move] == turn)  ) {
        four++;
        if (four == 4) {
            break;
        }
        check++;
    }
    return four;
}

// This function returns how many stones are in a horizontal alignment
int Horizontal(char **board, int move, char turn, int row, int column) {
    int check = (row - 1);
    int four = 0;
    if (board[0][move] != ' ') {
        check = 0;
    }
    else {
        while(board[check][move] != ' ') {
            check--;
        }
        check++;
    }

    while ( ( (move-1) >= 0) && (board[check][move-1] == turn) ) {
        move--;
    }
    while ( (move < column) && (board[check][move] == turn) ) {
        four++;
        if (four == 4) {
            break;
        }
        move++;
    }
    return four;
}

// This function returns how many stones are in a backslash alignment
int Backslash (char **board, int move, char turn, int row, int column) {
    int check = (row - 1);
    int four = 0;
    if (board[0][move] != ' ') {
        check = 0;
    }
    else {
      while(board[check][move] != ' ') {
          check--;
      }
      check++;
    }
    while ( (check > 0) && (move < column) && (board[(check - 1)][(move + 1)] == turn) ) {
        move++;
        check--;
    }
    while ( (check < row) && (move >= 0) && (board[check][move] == turn) ) {
        four++;
        if (four == 4) {
            break;
        }
        check++;
        move--;
    }
    return four;
}

// This function returns how many stones are in a fowardslash alignment
int Fowardslash (char **board, int move, char turn, int row, int column) {
    int check = (row - 1);
    int four = 0;
    if (board[0][move] != ' ') {
        check = 0;
    }
    else {
        while(board[check][move] != ' ') {
            check--;
        }
        check++;
    }
    while ( (check > 0) && (move > 0) && (board[check - 1][move - 1] == turn) ) {
        move--;
        check--;
    }
    while ( (check < row) && (move < column) && (board[check][move] == turn) ) {
        four++;
        if (four == 4) {
            break;
        }
        check++;
        move++;
    }
    return four;
}

// This function returns the number of stones with a maximum of four
int checkWin(char **board, int move, char turn, int row, int column) {
  int win = 0;
  win = Vertical(board, move, turn, row, column);
  if (win < 4) {
    win = Horizontal(board, move, turn, row, column);
  }
  if (win < 4) {
    win = Backslash(board, move, turn, row, column);
  }
  if (win < 4) {
    win = Fowardslash(board, move, turn, row, column);
  }
  return win;
}

// This function returns a 1 if the board is filled and there are no more moves
int boardFilled(char** board, int row, int column) {
  int all;
  for (int i = 0; i < column; i++){
    if(board[0][i] == ' ') {
      all = 0;
      break;
    }
    all = 1;
  }

  return all;
}

// This function removes the top stone in a column
void removeStone(char** board, int column) {
  int row = 0;
  if (board[0][column] != ' ') {
    board[0][column] = ' ';
    return;
  }
  while (board[row][column] == ' ') {
    row++;
  }
  board[row][column] = ' ';
  return;
}

// This function finds the maximum number of consecutive stones and returns them.
int checkScore(char** board, int row, int column, int movecol, char shape) {
  int score = 0;
  int temp = 0;
  temp = Vertical(board, movecol, shape, row, column);
  score = Horizontal(board, movecol, shape, row, column);
  if (temp > score) score = temp;
  temp = Backslash(board, movecol, shape, row, column);
  if (temp > score) score = temp;
  temp = Fowardslash(board, movecol, shape, row, column);
  if (temp > score) score = temp;

  return score;

}

// This function returns the score for the placement based on the number of consecutive stones next to the stones
int scoreMove(char** board, int row, int column, int movecol, char shape) {
  int score = 0;
  int temp = 0;
  temp = checkScore(board, row, column, movecol, shape);
  if (temp == 4) score = 22;
  if (temp == 3) score = 11;
  if (temp == 2) score = 5;
  if (temp == 1) score = 1;

  if (shape == 'O')
    return (score);
  else
    return (-score);
// If it is the computer's stone it returns a positive number while the opponents score will be returned negative
}


// This function returns the next best move for the computer.
int computerMove(char** board, int row, int column) {
  // score of our move
  int ratingO[column];
  // score of opponents next move after ours
  int ratingX[column];
  // location of their best move after ours
  int captain[column];
  // accounts for doubles in the array
  int trouble;
  // final decision
  int decision;
  // zero's out arrays
  destroyArray(ratingO, column);
  destroyArray(ratingX, column);
  // this is my next best move algorithm. It scores both the computer's move and then the next one
  for (int i = 0; i < column; i++){
    if ( (fillCol(board, i) == 0) ) {
      placeMark(i, 'O', board, row, column);
      ratingO[i] = scoreMove(board, row, column, i, 'O');
      for (int j = 0; j < column; j++) {
        if( (fillCol(board, j) == 0) ) {
          placeMark(j, 'X', board, row, column);
          ratingX[j] = scoreMove(board, row, column, j, 'X');
          removeStone(board, j);
        }
      }
      // It adds the minimum of the opponents score to the score of that move putting an emphasis on blocking the opponents move
      ratingO[i] = (ratingO[i] + minArray(ratingX, column) );
      captain[i] = placeMent(ratingX, column);
      destroyArray(ratingX, column);
      removeStone(board, i);
    }
    else {
      // if the collumn is full it changes the 0 to a -30 to block picking that column
      ratingO[i] = -30;
    }
  }
  // we find the maximum value in the array to place the stone
  decision = maxArray(ratingO, captain, column, &trouble);
  if (trouble == 1) {
    // if there are doubles in the array we block the column that is best for the opponent blocking their move
    return (captain[decision]);
  }
  else
    return decision;
}
