/*
Reversing a Series of Numbers (Revisited)

The reverse.c program of Section 8.1 reads 10 numbers, then writes the num
bers in reverse order. As the program reads the numbers, it stores them in an array.
Once all the numbers are read, the program steps through the array backwards as it
prints the numbers.
The original program used subscripting to access elements of the array. Here’s
a new version in which I’ve replaced subscripting with pointer arithmetic.
*/

/* Reverses a series of numbers (pointer version) */

#include <stdio.h>

#define N 10

int main(void) {
    int a[N], *p;

    printf("Enter %d numbers: ", N);
    for (p = a; p < a + N; p++)
        scanf("%d", p);

    printf("In reverse order: ");
    for (p = a + (N-1); p >= a; p--)
        printf("%d ", *p);
    printf("\n");

    return 0;
}