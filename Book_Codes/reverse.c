/*
Reversing a Series of Numbers

Our first array program prompts the user to enter a series of numbers, then writes
the numbers in reverse order:

Enter 10 numbers: 34 82 49 102 7 94 23 11 50 31
In reverse order: 31 50 11 23 94 7 102 49 82 34

Our strategy will be to store the numbers in an array as they’re read, then go
through the array backwards, printing the elements one by one. In other words, we
won’t actually reverse the elements in the array, but we’ll make the user think we
did.
*/

#include <stdio.h>

#define N 10

int main(void) {
    int a[N], i;

    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    printf("In reverse order: ");
    for (i = N - 1; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}