#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void placeMark(int move, char turn, char **board, int row, int column) {
  int check = (row - 1);
  while (board[check][move] != ' ') {
    check--;
  }
  board[check][move] = turn;

  return;
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
        printf(" %d  ", a);
      else
        printf(" %d ", a);
    }
    printf("\n");
    return;
}



int Vertical(char **board, int move, char turn, int row, int column) {
    int check = (row-1);
    int four = 0;
    int win = 0;
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
            win = 1;
            break;
        }
        check++;
    } 
    return win;
}

int Horizontal(char **board, int move, char turn, int row, int column) {
    int check = (row - 1);
    int four = 0;
    int win = 0;
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
            win = 1;
            break;
        }
        move++;
    }
    return win;
}

int Backslash (char **board, int move, char turn, int row, int column) {
    int check = (row - 1);
    int four = 0;
    int win = 0;
    if (board[0][move] != ' ') {
        check = 0;
    }
    else {
        while(board[check][move] != ' ') {
            check--;
        }
        check++;
    }
    while ( (check >= 0) && (move < column) && (board[(check - 1)][(move + 1)] == turn) ) {
        move++;
        check--;
    }
    while ( (check < row) && (move >= 0) && (board[check][move] == turn) ) {
        four++;
        if (four == 4) {
            win = 1;
            break;
        }
        check++;
        move--;
    }
    return win;
}

int Fowardslash (char **board, int move, char turn, int row, int column) {
    int check = (row - 1);
    int four = 0;
    int win = 0;
    if (board[0][move] != ' ') {
        check = 0;
    }
    else {
        while(board[check][move] != ' ') {
            check--;
        }
        check++;
    }
    while ( (check >= 0) && (move >= 0) && (board[check - 1][move - 1] == turn) ) {
        move--;
        check--;
    }
    while ( (check < row) && (move < column) && (board[check][move] == turn) ) {
        four++;
        if (four == 4) {
            win = 1;
            break;
        }
        check++;
        move++;
    }
    
    return win;
}

int checkWin(char **board, int move, char turn, int row, int column) {
  int count = 0;
  int win = 0;
  win = Vertical(board, move, turn, row, column);
  if (win != 1) {
    win = Horizontal(board, move, turn, row, column);
  }
  if (win != 1) {
    win = Backslash(board, move, turn, row, column);
  }
  if (win != 1) {
    win = Fowardslash(board, move, turn, row, column);
  }

  return win;
}