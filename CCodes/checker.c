/*
Write a program fragment that declares an 8 × 8 char array named checker_board and
then uses a loop to store the following data into the array (one character per array element):
B R B R B R B R
R B R B R B R B
B R B R B R B R
R B R B R B R B
B R B R B R B R
R B R B R B R B
B R B R B R B R
R B R B R B R B
Hint: The element in row i, column j, should be the letter B if i + j is an even number.
*/

#include <stdio.h>

int main(void) {
    char checker_board[8][8];
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                checker_board[i][j] = 'B';
            } else {
                checker_board[i][j] = 'R';
            }
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%c ", checker_board[i][j]);
        }
        printf("\n");
    }

    return 0;
}