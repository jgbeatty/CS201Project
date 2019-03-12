#include <stdio.h>
#include <stdlib.h>
#define row 6
#define column 7

char **allocateMatrix(char **);
void printBoard(char **);

int main () {
    char **board;
    board = allocateMatrix(board);
    for (int a = 0; a < row; a++){
        for (int b= 0; b < column; b++) {
            board[a][b] = 'X';
        }
    }

    board[0][0] = 'J';
    board[5][4] = 'J';
    printBoard(board);

    return 0;

}

char **allocateMatrix(char **data) {
    data = malloc (sizeof(char *) * row);
    for (int i = 0; i < row; i++)
        data[i] = malloc (sizeof(char *) * column);
    return data;
}

void printBoard(char **array) {
    for (int a = 0; a < row; a++) {
        for (int b = 0; b < column; b++) {
            printf("|%c", array[a][b]);
        }
        printf("|\n");
        printf("---------------\n");
    }
    printf(" 1 2 3 4 5 6 7\n");
    return;
}