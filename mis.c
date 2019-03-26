#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void destroyArray(int *store, int column) {
  for (int i = 0; i < column; i++)
    store[i] = 0;
}

int maxArray(int* store, int column) {
  int x = (column / 2);
  int max = store[x];
  for (int i = 0; i < column; i++) {
    if (store[i] > max ) {
     max = store[i];
     x = i;
    }
  }
  return x;
}

int minArray(int* store, int column) {
  int min = 0;
  for (int i = 0; i < column; i++) {
    if (store[i] < min ) min = store[i];
  }
  return min;
}

int fillCol(char** board, int column) {
  if (board[0][column] != ' ') return 1;

  else return 0;
}

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
    }
    if (check != 0)
        check ++;
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
    printf("%d\n", four);
    return four;
}

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

int checkScore(char** board, int row, int column, int moverow, int movecol, char shape) {
  int score = 0;
  int temp = 0;
  temp = Vertical(board, movecol, shape, row, column);
  score = Horizontal(board, movecol, shape, row, column);
  printf("%d\n", score);
  if (temp > score) score = temp;
  temp = Backslash(board, movecol, shape, row, column);
  if (temp > score) score = temp;
  temp = Fowardslash(board, movecol, shape, row, column);
  if (temp > score) score = temp;

  return score;

}

int scoreMove(char** board, int row, int column, int movecol, char shape) {
  int score = 0;
  int moverow = 0;
  int temp = 0;
  while (board[moverow][movecol] == ' ') {
    moverow++;
  }
  temp = checkScore(board, row, column, moverow, movecol, shape);
  if (temp == 4) score = 25;
  if (temp == 3) score = 10;
  if (temp == 2) score = 5;
  if (temp == 1) score = 1;

  if (shape == 'O')
    return score;
  else
    return (-score);
}

int computerMove(char** board, int row, int column) {
  int ratingO[column];
  int ratingX[column];
  destroyArray(ratingO, column);
  destroyArray(ratingX, column);
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
      ratingO[i] = (ratingO[i] + minArray(ratingX, column) );
      destroyArray(ratingX, column);
      removeStone(board, i);
    }
    else {
      ratingO[i] = -30;
    }
  }

  return (maxArray(ratingO, column));
}
