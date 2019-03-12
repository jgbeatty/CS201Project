#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Vertical(char **board, int move, char turn) {
    int check = 5;
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
    while ( (check <= 5) && (move <=6) && (move >= 0) && (board[check][move] == turn)  ) { 
        four++;
        if (four == 4) {
            win = 1;
            break;
        }
        check++;
    } 
    return win;
}

int Horizontal(char **board, int move, char turn) {
    int check = 5;
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
    while ( (move < 7) && (board[check][move] == turn) ) {
        four++;
        if (four == 4) {
            win = 1;
            break;
        }
        move++;
    }
    return win;
}

int Backslash (char **board, int move, char turn) {
    int check = 5;
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
    while ( (check >= 0) && (move < 7) && (board[(check - 1)][(move + 1)] == turn) ) {
        move++;
        check--;
    }
    while ( (check < 6) && (move >= 0) && (board[check][move] == turn) ) {
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

int Fowardslash (char **board, int move, char turn) {
    int check = 5;
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
    while ( (check < 6) && (move < 7) && (board[check][move] == turn) ) {
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
