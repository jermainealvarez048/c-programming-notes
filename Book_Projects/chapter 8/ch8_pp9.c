/*
Write a program that generates a “random walk” across a 10 × 10 array. The array will con
tain characters (all '.' initially). The program must randomly “walk” from element to ele
ment, always going up, down, left, or right by one element. The elements visited by the
program will be labeled with the letters A through Z, in the order visited. Here’s an example
of the desired output:

A . . . . . . . . . 
B C D . . . . . . . 
. F E . . . . . . . 
H G . . . . . . . . 
I . . . . . . . . . 
J . . . . . . . Z . 
K . . R S T U V Y . 
L M P Q . . . W X . 
. N O . . . . . . . 
. . . . . . . . . . 

Hint: Use the srand and rand functions (see deal.c) to generate random numbers.
After generating a number, look at its remainder when divided by 4. There are four possible
values for the remainder—0, 1, 2, and 3—indicating the direction of the next move. Before
performing a move, check that (a) it won’t go outside the array, and (b) it doesn’t take us to
an element that already has a letter assigned. If either condition is violated, try moving in
another direction. If all four directions are blocked, the program must terminate. Here’s an
example of premature termination:

A B G H I . . . . . 
. C F . J K . . . . 
. D E . M L . . . . 
. . . . N O . . . . 
. . W X Y P Q . . . 
. . V U T S R . . . 
. . . . . . . . . . 
. . . . . . . . . . 
. . . . . . . . . . 
. . . . . . . . . . 

Y is blocked on all four sides, so there’s no place to put Z.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 10

int main(void) {
    char walk[N][N];
    char letters = 'A';
    int row = 0, col = 0;

    srand((unsigned) time(NULL));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            walk[i][j] = '.';
    }

    walk[row][col] = letters++;
    while (letters <= 'Z') {
        int blocked = 0;
        int direction = rand() % 4;
        
        for (int attempt = 0; attempt < 4; attempt++) {
            int r = row, c = col;
            switch (direction) {
                case 0: r = row - 1; break; // up
                case 1: c = col + 1; break; // right
                case 2: r = row + 1; break; // down
                case 3: c = col - 1; break; // left
            }

            if (r >= 0 && r < N && c >= 0 && c < N && walk[r][c] == '.') {
                row = r;
                col = c;
                walk[row][col] = letters++;
                break;
            } else {
                blocked++;
                direction = (direction + 1) % 4;
            }
        }

        if (blocked == 4)
            break;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            printf("%c ", walk[i][j]);
        printf("\n");
    }

    return 0;
}