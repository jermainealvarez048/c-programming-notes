/*
Finding Lower, Upper Triangle, and Diagonal Elements of Square Matrix
condition:
- if rows == columns
upper triangle:
- i < j
lower triangle
- i > j
diagonal
- i == j
*/

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    bool square_matrix = false;
    int m, n; // m = rows, n = columns
    
    printf("Enter # of rows and columns: ");
    scanf("%d %d", &m, &n);

    if (m == n) {
        square_matrix = true;
    } else {
        printf("Not square matrix.\n");
        return 1;
    }

    int a[m][n];

    printf("Enter %d numbers as a square matrix: ", m * n);
    // input numbers
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");

    // output in a square matrix
    printf("In Square Matrix:");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j % 3 == 0) 
                printf("\n");
            printf("%d ", a[i][j]);
        }
    }
    printf("\n\n");

    // check the lower, upper triangle, and diagonal
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                printf("%d -> Upper Triangle\n", a[i][j]);
            } 
            else if (i > j) {
                printf("%d -> Lower Triangle\n", a[i][j]);
            } else {
                printf("%d -> Diagonal\n", a[i][j]);
            }
        }
    }

    

    return 0;
}