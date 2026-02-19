/*
Transpose of Given Matrix
- rows -> columns, columns -> rows
*/

#include <stdio.h>

int main(void) {
    int A[3][3] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};
    int T[3][3];

    printf("Before Transpose:");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j % 3 == 0)
                printf("\n");
            printf("%d ", A[i][j]);
        }
    }
    printf("\n");

    printf("After Transpose:");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            T[i][j] = A[j][i];
            if (j % 3 == 0)
                printf("\n");
            printf("%d ", T[i][j]);
        }
    }
    
    return 0;
}